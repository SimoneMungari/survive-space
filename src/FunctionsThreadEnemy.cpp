#include "../librerie/common.h"

extern void *enemyInit(void *);
extern void startEnemy();	
extern void movimentoEnemy();	
extern void controlloDifficolta(bool[]);

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
	bool step[10]={true,false,false,false,false,false,false,false,false,false}; //Array di boolean per il controlloDifficoltà
	int dir=0,dirprec=0;
	for(int i=0;i<16;i++)
	{
		dir=(rand()%80)+1;	//Numero casuale da 1 ad 80 per lo "spawn" dei nemici
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
				sound.play();
				enemy[i]->setDeath(false);	//Resuscita
				do{
					dir=(rand()%80)+1;	//Ma in una posizione differente
				}while(dir==dirprec);		//Mini controllo che due nemici non nascano nella stessa posizione
				dirprec=dir;
				enemy[i]->update(dir);		//Aggiorna la posizione del nemico precedentemente morto
			}
		}
		usleep(900000);
		controlloDifficolta(step);	//Invocazione della funzione per controllare la difficoltà con passaggio di array "step"
	}
}

//FUNZIONI CONTROLLO DIFFICOLTÀ

void controlloDifficolta(bool step[])
{
	if(player->getEnemyKilled()>10 && step[0])	//Se il numero di nemici morti è > 10 ed è attivo lo step[0]
	{
		step[0]=false;
		step[1]=true;				//Lo step precedente va a False perchè è finito, lo step successivo si attiva
		nNemici++;				//Aumenta il numero dei nemici di 1
		return;
	}
	if(player->getEnemyKilled()>20 && step[1])
	{
		step[1]=false;
		step[2]=true;
		nNemici++;
		return;	
	}
	if(player->getEnemyKilled()>30 && step[2])
	{
		step[2]=false;
		step[3]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>40 && step[3])
	{
		step[3]=false;
		step[4]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>50 && step[4])
	{
		step[4]=false;
		step[5]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>60 && step[5])
	{
		step[5]=false;
		step[6]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>70 && step[6])
	{
		step[6]=false;
		step[7]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>80 && step[7])
	{
		step[7]=false;
		step[8]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>90 && step[8])
	{
		step[8]=false;
		step[9]=true;
		nNemici++;
		return;
	}
	if(player->getEnemyKilled()>100 && step[9])	//I nemici aumentano fino allo step[9], quando il giocatore supera i 100 nemici uccisi
	{						// ci saranno in gioco 16 oggetti Enemy
		step[9]=false;
		nNemici++;
		return;
	}
}
