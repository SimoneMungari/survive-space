#include "../librerie/common.h"

extern void *enemyInit(void *);
extern void startEnemy();	
extern void movimentoEnemy();	
extern void controlloDifficolta(int&);

//FUNZIONI THREAD ENEMY

void *enemyInit(void * args)	//Viene invocato il thread pEnemy tramite la funzione enemyInit
{
	movimentoEnemy();	//Chiama la funzione che si occupa del movimento autonomo dei nemici
}

void movimentoEnemy()
{
	soundB.loadFromFile("../music/gun.wav");	//Inizializzazione dei suoni di "morte" dei nemici
	sound.setBuffer(soundB);
	sound.setVolume(80);
	int step=1;
	int dir=0,dirprec=0;
	for(int i=0;i<16;i++)
	{
		dir=((rand()%80)+1);	//Numero casuale da 1 ad 80 per lo "spawn" dei nemici
		enemy[i]->update(dir);	//Vengono aggiornate le posizioni di partenza dei nemici
	}
	while(running)
	{
		for(int i=0;i<nNemici;i++)
		{
			pthread_mutex_lock(&mutexGame);	//Blocca il mutex
			enemy[i]->movimento(player);	//
			enemy[i]->cancellaEnemy(false);	// Fa il movimento del nemico e cancella la posizione precedente
			refresh();			//
			pthread_mutex_unlock(&mutexGame);//Sblocca il mutex
			if(enemy[i]->getDeath()==true)	//Se il nemico è morto
			{
				controlloDifficolta(step);
				sound.play();
				enemy[i]->setDeath(false);	//Resuscita
				do{
					dir=((rand()%80)+1);	//Ma in una posizione differente
				}while(dir==dirprec);		//Mini controllo che due nemici non nascano nella stessa posizione
				dirprec=dir;
				enemy[i]->update(dir);		//Aggiorna la posizione del nemico precedentemente morto
			}
		}
		usleep(900000);
						//Invocazione della funzione per controllare la difficoltà con passaggio di array "step"
	}
}

//FUNZIONI CONTROLLO DIFFICOLTÀ

void controlloDifficolta(int &step)
{
	
	if((player->getEnemyKilled()==(10*step)) && step<11)	//Se il numero di nemici morti è > 10 ed è attivo lo step[0]
	{			
		nNemici++;					//Aumenta il numero dei nemici di 1
		step++;
	}
	if(player->getEnemyKilled()%50==0 && player->getEnemyKilled()>0)
	{
		player->setVita(10);
		player->bonus=true;
	}
}
