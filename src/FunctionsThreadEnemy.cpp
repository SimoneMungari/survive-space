#include "../librerie/common.h"

extern void *enemyInit(void *);
extern void startEnemy();	
extern void movimentoEnemy();	
extern void controlloDifficolta(bool[]);

//FUNZIONI THREAD ENEMY

void *enemyInit(void * args)
{
	movimentoEnemy();
}

void movimentoEnemy()
{
	soundB.loadFromFile("../music/gun.wav");
	sound.setBuffer(soundB);
	sound.setVolume(80);
	bool step[10]={true,false,false,false,false,false,false,false,false,false};
	int dir=0,dirprec=0;
	for(int i=0;i<16;i++)
	{
		dir=(rand()%80)+1;
		enemy[i]->update(dir);
	}
	while(running)
	{
		for(int i=0;i<nNemici;i++)
		{
			pthread_mutex_lock(&mutexGame);
			enemy[i]->movimento(player);
			enemy[i]->cancellaEnemy(false);
			refresh();
			pthread_mutex_unlock(&mutexGame);
			if(enemy[i]->getDeath()==true)
			{
				sound.play();
				enemy[i]->setDeath(false);
				do{
					dir=(rand()%80)+1;
				}while(dir==dirprec);
				dirprec=dir;
				enemy[i]->update(dir);
			}
		}
		usleep(900000);
		controlloDifficolta(step);
	}
}

//FUNZIONI CONTROLLO DIFFICOLTÀ

void controlloDifficolta(bool step[])
{
	if(player->getEnemyKilled()>10 && step[0])
	{
		step[0]=false;
		step[1]=true;
		nNemici++;
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
	if(player->getEnemyKilled()>100 && step[9])
	{
		step[9]=false;
		nNemici++;
		return;
	}
}
