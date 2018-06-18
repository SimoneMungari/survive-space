#include "../librerie/common.h"

extern void playerF();
extern void movimentoPlayer(int);
extern void sparaSu();
extern void sparaGiu();
extern void sparaDestra();
extern void sparaSinistra();
extern void *sparato(void *); 


//FUNZIONI THREAD PLAYER E PROIETTILE

void * sparato(void *arg)
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
	if(mossa<97)
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
			pthread_t pProiettile1;
			dirProiettile=1;			
			pthread_create(&pProiettile1,NULL,sparato,NULL);
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
	noecho();
	int mossa;
	player=new Player();
	stampaCampoGioco();
	while(running)
	{
		pthread_mutex_lock(&mutexGame);
		attron(COLOR_PAIR(1));
		player->visualizza_player();
		attroff(COLOR_PAIR(1));
		player->visualizza_stat();
		refresh();
		mossa=getch();
		pthread_mutex_unlock(&mutexGame);
		movimentoPlayer(mossa);
		if(player->getVita()<=0)
			running=false;

	}
	reset=true;
}

void sparaSu()
{
	if(running==false)
		return;	
	bool collisione, collisionePro=false;
	int ytemp=player->getY()+1;
	int i=player->getX()-2;	
	int numEnemyMorto;
	int dir=0,dirprec=0;
	for(i;i>=0;i--)
	{
		collisione=player->controlloCollisione(i,ytemp-1);
		for(int k=0;k<nNemici;k++)
		{
			if(enemy[k]->getY()==ytemp && (enemy[k]->getX()==i || enemy[k]->getX()==(i-1)))
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
		mvprintw(i,ytemp,"^");
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

void sparaGiu()
{	
	if(running==false)
		return;
	bool collisione, collisionePro=false;
	int ytemp=player->getY()+1;
	for(int i=player->getX()+2;i<=LINES;i++)
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

