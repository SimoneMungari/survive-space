#include "../librerie/player.h"

Player::Player() //Costruttore vuoto
{
	this->x=LINES/2;	//Posizione iniziale della navicella
	this->y=(COLS/2)+1;
	this->vita=100;
	this->enemyKilled=0;
	this->forma="<@>";
	this->su=false;
	this->giu=false;
	this->destra=false;
	this->sinistra=false;
	this->bonus=false;
}

int Player::getX() const
{
	return x;
}

int Player::getY() const
{
	return y;
}

int Player::getVita() const
{
	return vita;
}

int Player::getEnemyKilled() const
{
	return enemyKilled;
}

void Player::setEnemyKilled(int x)
{
	enemyKilled+=x;
}

void Player::setVita(int x)
{
	vita+=x;
}


void Player::Su()
{
	bool collisione=controlloCollisione(x-1,y);
	if(collisione==false)
	{
		x--;
		su=true;
		giu=false;
		destra=false;
		sinistra=false;
	}
}
void Player::Giu()
{
	bool collisione=controlloCollisione(x+1,y);
	if(collisione==false)
	{
		x++;
		giu=true;
		su=false;
		destra=false;
		sinistra=false;
	}
}
void Player::Destra()
{
	bool collisione=controlloCollisione(x,y+1);
	if(collisione==false)
	{
		y++;
		destra=true;
		su=false;
		giu=false;
		sinistra=false;
	}
}
void Player::Sinistra()
{
	bool collisione=controlloCollisione(x,y-1);
	if(collisione==false)
	{
		y--;
		sinistra=true;
		su=false;
		giu=false;
		destra=false;
	}
}

void Player::visualizza_stat()
{
	if(vita>=100)
	{
		mvprintw(0,COLS-25,"Vita: %d",vita);
	}
	else if(vita<=95 && vita>=10)
	{
		mvprintw(0,COLS-25,"Vita: %d",vita);
	 	mvprintw(0,COLS-17," ");
	}
	else
	{
		mvprintw(0,COLS-25,"Vita: %d",vita);
	 	mvprintw(0,COLS-18,"  ");
	}
	mvprintw(1,COLS-25,"Nemici Uccisi: %d",enemyKilled);
	if(bonus)
	{
		mvprintw(2,COLS-30,"BONUS! VITA+10!");
		if(enemyKilled%53==0)
		{
			bonus=false;
			mvprintw(2,COLS-30,"               ");
		}
	}
}


void Player::visualizza_player() const
{
	cancella_player();
	mvprintw(x,y,forma.c_str());
}

void Player::cancella_player() const
{
	if(su)
		mvprintw(x+1,y,"   ");
	if(giu)
		mvprintw(x-1,y,"   ");	
	if(destra)
		mvprintw(x,y-1," ");
	if(sinistra)
		mvprintw(x,y+3," ");
}


bool Player::controlloCollisione(int tempx, int tempy) const
{
	//inizio controllo linea superiore

	for(int i=-18;i<19;i++)
	{
		if(tempx == (LINES/2)-3 && tempy==(COLS/2)+i)
			return true;
	}

	//inizio controllo laterale
	for(int i=-3;i<6;i++)
	{
		if(tempx == (LINES/2)+i && tempy==(COLS/2)-18)
			return true;
	}
	
	for(int i=-3;i<6;i++)
	{	
		if(tempx == (LINES/2)+i && tempy==(COLS/2)+16)
			return true;
	}

	//inizio controllo linea inferiore
	
	
	for(int i=-18;i<19;i++)
	{
		if(tempx == (LINES/2)+5 && tempy==(COLS/2)+i)
			return true;
	}
	return false;
}
