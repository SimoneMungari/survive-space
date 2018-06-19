#include "../librerie/common.h"

extern void playerF();
extern void movimentoPlayer(int);
extern void sparaSu();
extern void sparaGiu();
extern void sparaDestra();
extern void sparaSinistra();
extern void *sparato(void *); 


//FUNZIONI THREAD PLAYER E PROIETTILE

void * sparato(void *arg)	//Inizio thread proiettile
{
	switch(dirProiettile)
	{
		case 1:{ sparaSu(); break;}
		case 2:{ sparaGiu(); break;}
		case 3:{ sparaSinistra(); break;}
		case 4:{ sparaDestra(); break;}
	}
}

void movimentoPlayer(int mossa)
{
	if(mossa<97)	//Controllo se il tasto premuto è in maiuscolo, lo rende minuscolo
		mossa+=32;

	switch(mossa)
	{	
		case  KEY_UP:
		{
			player->Su();	
			break;
		}
		case KEY_DOWN:
		{
			player->Giu();		
			break;
		}
		case KEY_RIGHT:
		{
			player->Destra();			
			break;
		}
		case KEY_LEFT:
		{
			player->Sinistra();
			break;
		}
		case 'w':
		{
			pthread_t pProiettile1;				//Dichiarazione thread proiettile
			dirProiettile=1;				//Inizializzata la direzione
			pthread_create(&pProiettile1,NULL,sparato,NULL);//Il thread è partito invocando la funzione "sparato"
			break;
		}
		case 'a':
		{
			pthread_t pProiettile2;
			dirProiettile=3;		
			pthread_create(&pProiettile2,NULL,sparato,NULL);
			break;
		}
		case 's':
		{	
			pthread_t pProiettile3;
			dirProiettile=2;
			pthread_create(&pProiettile3,NULL,sparato,NULL);
			break;
		}
		case 'd':
		{
			pthread_t pProiettile4;
			dirProiettile=4;	
			pthread_create(&pProiettile4,NULL,sparato,NULL);
			break;
		}
		default:
			return;

	}
}

void playerF()
{
	int mossa=0;
	player=new Player();	//Costruzione dell'oggetto player
	stampaCampoGioco();
	while(running)
	{
		pthread_mutex_lock(&mutexGame); 	//Mutex bloccato
		attron(COLOR_PAIR(1));
		player->visualizza_player();		//Stampe della vita, punteggio e della navicella
		attroff(COLOR_PAIR(1));
		player->visualizza_stat();
		refresh();
		mossa=getch();				//Prende in input il tasto premuto dall'utente
		pthread_mutex_unlock(&mutexGame);	//Mutex sbloccato
		movimentoPlayer(mossa);			//Chiamata funzione movimentoPlayer alla quale viene passato il comando 
		if(player->getVita()<=0)		//Controllo se la vita è <=0 il gioco finisce
			running=false;

	}
	reset=true;
}

void sparaSu()
{
	if(running==false)
		return;	
	bool collisione=false, collisionePro=false;
	int ytemp=player->getY()+1;
	int i=player->getX()-2;	
	int dir=0,dirprec=0;
	for(i;i>=-1;i--)	//For che muove il proiettile da sotto verso sopra, quindi i-- e si ferma quando arriva a -1 (al limite)
	{
		collisione=player->controlloCollisione(i,ytemp-1); //Controlla la collisione con la base
		for(int k=0;k<nNemici;k++)	//For che scorre i nemici per controllare se c'è stato uno scontro proiettile-nemico
		{
			if(enemy[k]->getY()==ytemp && (enemy[k]->getX()==i || enemy[k]->getX()==(i-1))) //controllo coordinate
			{
				if(enemy[k]->getDeath()==false)	//Se entra nell'if vuol dire che il nemico è stato colpito
				{
					enemy[k]->setDeath(true);	//Il nemico muore
					pthread_mutex_lock(&mutexGame);	//Mutex bloccato
					enemy[k]->cancellaEnemy(true);	//Cancella il nemico nella sua posizione attuale
					pthread_mutex_unlock(&mutexGame);//Mutex sbloccato
					enemy[k]->setX(LINES+1);	//Il nemico viene spostato fuori dallo schermo nell'attesa che gli
					collisionePro=true;		//venga assegnata un'altra posizione, quindi collisione con proiettile
									// va a true
				}
				break;
			}
		}
		if(collisionePro)	//	Se c'è stata collisione proiettile-nemico, esce dal for
			break;		//	
		if(collisione)		//	Se c'è stata collisione con la base, salta il blocco e va avanti
			i--;		//
		pthread_mutex_lock(&mutexGame);	//Mutex bloccato
		mvprintw(i,ytemp,"^");		//Stampa proiettile
		refresh();
		pthread_mutex_unlock(&mutexGame);	//Mutex sbloccato
		usleep(20000);
		pthread_mutex_lock(&mutexGame);	//Mutex bloccato
		mvprintw(i,ytemp," ");		//cancella il proiettile precedente
		refresh();
		pthread_mutex_unlock(&mutexGame);//Mutex sbloccato
		if(running==false)
			break;
	}
}

	//Ragionamento uguale anche per gli altri versi (giu, destra, sinitra), l'unica differenza è lo spostamento del proiettile	

void sparaGiu()
{	
	if(running==false)
		return;
	bool collisione, collisionePro=false;
	int ytemp=player->getY()+1;
	int i=player->getX()+2;
	for(i;i<=LINES;i++)
	{
		collisione=player->controlloCollisione(i,ytemp-1);
		for(int k=0;k<nNemici;k++)
		{
			if((enemy[k]->getX()==i || enemy[k]->getX()==(i+1)) && (ytemp==enemy[k]->getY()))
			{
				if(enemy[k]->getDeath()==false)
				{
					enemy[k]->setDeath(true);
					pthread_mutex_lock(&mutexGame);
					enemy[k]->cancellaEnemy(true);
					pthread_mutex_unlock(&mutexGame);
					enemy[k]->setX(LINES+1);
					collisionePro=true;
				}
				break;
			}
		}
		if(collisionePro)
			break;
		if(collisione)
			i++;
		pthread_mutex_lock(&mutexGame);
		mvprintw(i,ytemp,"v");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		usleep(20000);
		pthread_mutex_lock(&mutexGame);
		mvprintw(i,ytemp," ");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		if(running==false)
			break;
	}
}

void sparaDestra()
{
	if(running==false)
		return;
	bool collisione,collisionePro=false;
	int xtemp=player->getX();
	int i=player->getY()+4,o=0;
	for( i;i<COLS;i++)
	{
		collisione=player->controlloCollisione(xtemp,i-2);
		for(int k=0;k<nNemici;k++)
		{
			if((enemy[k]->getX()==xtemp) && (i==enemy[k]->getY() || (i+1)==enemy[k]->getY()))
			{
				if(enemy[k]->getDeath()==false)
				{
					enemy[k]->setDeath(true);
					pthread_mutex_lock(&mutexGame);
					enemy[k]->cancellaEnemy(true);
					pthread_mutex_unlock(&mutexGame);
					enemy[k]->setX(LINES+1);
					collisionePro=true;
				}
				break;
			}
		}
		if(collisionePro)
			break;
		if(collisione)
			i++;
		pthread_mutex_lock(&mutexGame);
		mvprintw(xtemp,i,">");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		usleep(20000);
		pthread_mutex_lock(&mutexGame);
		mvprintw(xtemp, i," ");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		if(running==false)
			break;
		
	}	
}
void sparaSinistra()
{
	if(running==false)
		return;
	bool collisione, collisionePro=false;
	int xtemp=player->getX();
	int i=player->getY()-4,o=player->getY();
	for(i;o>=0;o--,i--)
	{	
		collisione=player->controlloCollisione(xtemp,i);
		for(int k=0;k<nNemici;k++)
		{
			if((enemy[k]->getX()==xtemp) && (i==enemy[k]->getY() || (i-1)==enemy[k]->getY()))
			{	
				if(enemy[k]->getDeath()==false)
				{
					enemy[k]->setDeath(true);
					pthread_mutex_lock(&mutexGame);
					enemy[k]->cancellaEnemy(true);
					pthread_mutex_unlock(&mutexGame);
					enemy[k]->setX(LINES+1);
					collisionePro=true;
				}
				break;
			}
		}
		if(collisionePro)
			break;
		if(collisione)
			i--;
		pthread_mutex_lock(&mutexGame);
		mvprintw(xtemp,i,"<");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		usleep(20000);
		pthread_mutex_lock(&mutexGame);
		mvprintw(xtemp,i," ");
		refresh();
		pthread_mutex_unlock(&mutexGame);
		if(running==false)
			break;
	}
}

