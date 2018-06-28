#include "../librerie/enemy.h"

Enemy::Enemy()	//Costruttore, inizializza le variabili e la posizione iniziale a (0,0)
{

	forma="#";
	direzione=0;
	death=false;
	x=0;
	y=0;
}

bool Enemy::getDeath() const
{
	return death;
}

int Enemy::getX() const
{
	return x;
}

void Enemy::setX(int x)
{
	this->x=x;
}

int Enemy::getY() const
{
	return y;
}

int Enemy::getDirezione() const
{
	return direzione;
}


void Enemy::setDeath(bool x)
{
	death=x;
}

void Enemy::update(int direzione)	//Cambia lo spawn del nemico appena iniziato il gioco e ogniqualvolta muore un nemico
{

	this->direzione=direzione;

	if(direzione>=1 && direzione<=33)	//Spawn Su
	{
		this->x=0;
		this->y=(COLS/2)-17+direzione;
	}
	
	if(direzione>=34 && direzione<=66)	//Spawn Giù
	{
		this->x=LINES;
		this->y=(COLS/2)-50+direzione;
	}

	if(direzione>=67 && direzione<=73)	//Spawn Sinistra
	{
		this->x=(LINES/2)-69+direzione;
		this->y=0;
	}

	if(direzione>=74 && direzione<=80)	//Spawn Destra
	{
		this->x=(LINES/2)-76+direzione;
		this->y=COLS;
	}
}



void Enemy::visualizzaEnemy(int xtemp, int ytemp) const		//Stampa del nemico
{
	mvprintw(xtemp,ytemp,forma.c_str());	
}

void Enemy::cancellaEnemy(bool comodo) const
{
	if(!comodo)					//Se comodo==false cancella il nemico nella posizione precedente
	{
		if(direzione>=1 && direzione<=33)
		{
			mvprintw(x-1,y," ");	
		}
		else if(direzione>=34 && direzione<=66)
		{
			mvprintw(x+1,y," ");	
		}
		else if(direzione>=67 && direzione<=73)
		{
			mvprintw(x,y-1," ");	
		}
		else if(direzione>=74 && direzione<=80)
		{
			mvprintw(x,y+1," ");	
		}
	}
	else						//Se comodo==true cancella il nemico nella sua posizione attuale
	{
		mvprintw(x,y," ");		
	}
}

void Enemy::movimento(Player * player)			//Movimento del nemico, viene passato un puntatore a Player per la modifica dei valori
{							// di "Nemici Uccisi", "Vita" e usa la funzione "Controllo Collisione"
	if(direzione>=1 && direzione<=33)//Spawn da sopra
	{		
		x++;			//aggiunge uno alle x cosicchè il nemico scenda	
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);	//Se il nemico è morto, aumenta il punteggio dei nemici uccisi di 1
			return;
		}
		collisione=player->controlloCollisione(x,y); //Controlla la collisione con la base del player
		if(collisione) 	//Se la collisione risulta True, il nemico muore e la vita del giocatore si abbassa di 5 punti
		{
			death=true;
			player->setVita(-5);
			return;
		}					
		attron(COLOR_PAIR(2));	//Colora il nemico
		visualizzaEnemy(x,y);	//Stampa
		attron(COLOR_PAIR(2));
	}
	else if(direzione>=34 && direzione<=66) //Spawn da sotto, ragionamento uguale, unica differenza è lo spostamento
	{
		x--;	//Diminuisce le x cosicchè il nemico vada sopra
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}					
		collisione=player->controlloCollisione(x,y);
		if(collisione)
		{
			death=true;
			player->setVita(-5);
			return;
		}
		attron(COLOR_PAIR(2));
		visualizzaEnemy(x,y);
		attroff(COLOR_PAIR(2));
	}
	else if(direzione>=67 && direzione<=73) //Spawn da sinistra, ragionamento uguale, unica differenza è lo spostamento
	{
		y++; //Aggiunge uno alle y cosicchè il nemico vada a destra
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}
		collisione=player->controlloCollisione(x,y);
		if(collisione)
		{
			death=true;
			player->setVita(-5);
			return;
		}				
		attron(COLOR_PAIR(2));
		visualizzaEnemy(x,y);
		attroff(COLOR_PAIR(2));
	}
	else if(direzione>=74 && direzione<=80) //Spawn da destra, ragionamento uguale, unica differenza è lo spostamento
	{
		bool collisione;
		y--;  //Sottrae uno alle y cosicchè il nemico vada a sinistra
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}
		collisione=player->controlloCollisione(x,y-2);//Per controllare la collisione viene mandata la y-2 a causa del cursore
		if(collisione)
		{
			death=true;
			player->setVita(-5);
			return;
		}
		attron(COLOR_PAIR(2));
		visualizzaEnemy(x,y);
		attroff(COLOR_PAIR(2));
	}
}
