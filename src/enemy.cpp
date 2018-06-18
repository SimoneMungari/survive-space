#include "../librerie/enemy.h"

Enemy::Enemy()
{

	forma="#";
	vita=15;
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

void Enemy::update(int direzione)
{

	this->forma="#";
	this->vita=15;
	this->direzione=direzione;

	switch(direzione)
	{
		case 1:
			{
				this->x=0;
				this->y=(COLS/2)-16;
				break;
			}
		case 2:
			{
				this->x=0;
				this->y=(COLS/2)-15;
				break;
			}
		case 3:
			{
				this->x=0;
				this->y=(COLS/2)-14;
				break;
			}
		case 4:
			{
				this->x=0;
				this->y=(COLS/2)-13;
				break;
			}
		case 5:
			{
				this->x=0;
				this->y=(COLS/2)-12;
				break;
			}
		case 6:
			{
				this->x=0;
				this->y=(COLS/2)-11;
				break;
			}
		case 7:
			{
				this->x=0;
				this->y=(COLS/2)-10;
				break;
			}
		case 8:
			{
				this->x=0;
				this->y=(COLS/2)-9;
				break;
			}
		case 9:
			{
				this->x=0;
				this->y=(COLS/2)-8;
				break;
			}
		case 10:
			{
				this->x=0;
				this->y=(COLS/2)-7;
				break;
			}
		case 11:
			{
				this->x=0;
				this->y=(COLS/2)-6;
				break;
			}
		case 12:
			{
				this->x=0;
				this->y=(COLS/2)-5;
				break;
			}
		case 13:
			{
				this->x=0;
				this->y=(COLS/2)-4;
				break;
			}
		case 14:
			{
				this->x=0;
				this->y=(COLS/2)-3;
				break;
			}
		case 15:
			{
				this->x=0;
				this->y=(COLS/2)-2;
				break;
			}
		case 16:
			{
				this->x=0;
				this->y=(COLS/2)-1;
				break;
			}
		case 17:
			{
				this->x=0;
				this->y=(COLS/2);
				break;
			}
		case 18:
			{
				this->x=0;
				this->y=(COLS/2)+1;
				break;
			}
		case 19:
			{
				this->x=0;
				this->y=(COLS/2)+2;
				break;
			}
		case 20:
			{
				this->x=0;
				this->y=(COLS/2)+3;
				break;
			}
		case 21:
			{
				this->x=0;
				this->y=(COLS/2)+4;
				break;
			}
		case 22:
			{
				this->x=0;
				this->y=(COLS/2)+5;
				break;
			}
		case 23:
			{
				this->x=0;
				this->y=(COLS/2)+6;
				break;
			}
		case 24:
			{
				this->x=0;
				this->y=(COLS/2)+7;
				break;
			}
		case 25:
			{
				this->x=0;
				this->y=(COLS/2)+8;
				break;
			}
		case 26:
			{
				this->x=0;
				this->y=(COLS/2)+9;
				break;
			}
		case 27:
			{
				this->x=0;
				this->y=(COLS/2)+10;
				break;
			}
		case 28:
			{
				this->x=0;
				this->y=(COLS/2)+11;
				break;
			}
		case 29:
			{
				this->x=0;
				this->y=(COLS/2)+12;
				break;
			}
		case 30:
			{
				this->x=0;
				this->y=(COLS/2)+13;
				break;
			}
		case 31:
			{
				this->x=0;
				this->y=(COLS/2)+14;
				break;
			}
		case 32:
			{
				this->x=0;
				this->y=(COLS/2)+15;
				break;
			}
		case 33:
			{
				this->x=0;
				this->y=(COLS/2)+16;
				break;
			}

		case 34:
			{
				this->x=LINES;
				this->y=(COLS/2)-16;
				break;
			}
		case 35:
			{
				this->x=LINES;
				this->y=(COLS/2)-15;
				break;
			}
		case 36:
			{
				this->x=LINES;
				this->y=(COLS/2)-14;
				break;
			}
		case 37:
			{
				this->x=LINES;
				this->y=(COLS/2)-13;
				break;
			}
		case 38:
			{
				this->x=LINES;
				this->y=(COLS/2)-12;
				break;
			}
		case 39:
			{
				this->x=LINES;
				this->y=(COLS/2)-11;
				break;
			}
		case 40:
			{
				this->x=LINES;
				this->y=(COLS/2)-10;
				break;
			}
		case 41:
			{
				this->x=LINES;
				this->y=(COLS/2)-9;
				break;
			}
		case 42:
			{
				this->x=LINES;
				this->y=(COLS/2)-8;
				break;
			}
		case 43:
			{
				this->x=LINES;
				this->y=(COLS/2)-7;
				break;
			}
		case 44:
			{
				this->x=LINES;
				this->y=(COLS/2)-6;
				break;
			}
		case 45:
			{
				this->x=LINES;
				this->y=(COLS/2)-5;
				break;
			}
		case 46:
			{
				this->x=LINES;
				this->y=(COLS/2)-4;
				break;
			}
		case 47:
			{
				this->x=LINES;
				this->y=(COLS/2)-3;
				break;
			}
		case 48:
			{
				this->x=LINES;
				this->y=(COLS/2)-2;
				break;
			}
		case 49:
			{
				this->x=LINES;
				this->y=(COLS/2)-1;
				break;
			}
		case 50:
			{
				this->x=LINES;
				this->y=(COLS/2);
				break;
			}
		case 51:
			{
				this->x=LINES;
				this->y=(COLS/2)+1;
				break;
			}
		case 52:
			{
				this->x=LINES;
				this->y=(COLS/2)+2;
				break;
			}
		case 53:
			{
				this->x=LINES;
				this->y=(COLS/2)+3;
				break;
			}
		case 54:
			{
				this->x=LINES;
				this->y=(COLS/2)+4;
				break;
			}
		case 55:
			{
				this->x=LINES;
				this->y=(COLS/2)+5;
				break;
			}
		case 56:
			{
				this->x=LINES;
				this->y=(COLS/2)+6;
				break;
			}
		case 57:
			{
				this->x=LINES;
				this->y=(COLS/2)+7;
				break;
			}
		case 58:
			{
				this->x=LINES;
				this->y=(COLS/2)+8;
				break;
			}
		case 59:
			{
				this->x=LINES;
				this->y=(COLS/2)+9;
				break;
			}
		case 60:
			{
				this->x=LINES;
				this->y=(COLS/2)+10;
				break;
			}
		case 61:
			{
				this->x=LINES;
				this->y=(COLS/2)+11;
				break;
			}
		case 62:
			{
				this->x=LINES;
				this->y=(COLS/2)+12;
				break;
			}
		case 63:
			{
				this->x=LINES;
				this->y=(COLS/2)+13;
				break;
			}
		case 64:
			{
				this->x=LINES;
				this->y=(COLS/2)+14;
				break;
			}
		case 65:
			{
				this->x=LINES;
				this->y=(COLS/2)+15;
				break;
			}
		case 66:
			{
				this->x=LINES;
				this->y=(COLS/2)+16;
				break;
			}
		case 67:
			{
				this->x=(LINES/2)-2;
				this->y=0;
				break;
			}
		case 68:
			{
				this->x=(LINES/2)-1;
				this->y=0;
				break;
			}
		case 69:
			{
				this->x=(LINES/2);
				this->y=0;
				break;
			}
		case 70:
			{
				this->x=(LINES/2)+1;
				this->y=0;
				break;
			}
		case 71:
			{
				this->x=(LINES/2)+2;
				this->y=0;
				break;
			}
		case 72:
			{
				this->x=(LINES/2)+3;
				this->y=0;
				break;
			}
		case 73:
			{
				this->x=(LINES/2)+4;
				this->y=0;
				break;
			}
		case 74:
			{
				this->x=(LINES/2)-2;
				this->y=COLS;
				break;
			}
		case 75:
			{
				this->x=(LINES/2)-1;
				this->y=COLS;
				break;
			}
		case 76:
			{
				this->x=(LINES/2);
				this->y=COLS;
				break;
			}
		case 77:
			{
				this->x=(LINES/2)+1;
				this->y=COLS;
				break;
			}
		case 78:
			{
				this->x=(LINES/2)+2;
				this->y=COLS;
				break;
			}
		case 79:
			{
				this->x=(LINES/2)+3;
				this->y=COLS;
				break;
			}
		case 80:
			{
				this->x=(LINES/2)+4;
				this->y=COLS;
				break;
			}
	}
}



void Enemy::visualizzaEnemy(int xtemp, int ytemp) const
{
	mvprintw(xtemp,ytemp,forma.c_str());	
}

void Enemy::cancellaEnemy(bool comodo) const
{
	if(!comodo)
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
	else
	{
		mvprintw(x,y," ");		
	}
}

void Enemy::movimento(Player * player)
{
	if(direzione>=1 && direzione<=33)
	{
		x++;
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}
		collisione=player->controlloCollisione(x,y+2);
		if(collisione)
		{
			death=true;
			player->setVita(-5);
			return;
		}					
		attron(COLOR_PAIR(2));
		visualizzaEnemy(x,y);
		attron(COLOR_PAIR(2));
	}
	else if(direzione>=34 && direzione<=66)
	{
		x--;
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}					
		collisione=player->controlloCollisione(x,y+2);
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
	else if(direzione>=67 && direzione<=73)
	{
		y++;
		bool collisione;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}
		collisione=player->controlloCollisione(x,y+2);
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
	else if(direzione>=74 && direzione<=80)
	{
		bool collisione;
		y--;
		if(death==true)
		{
			player->setEnemyKilled(1);
			return;
		}
		collisione=player->controlloCollisione(x,y-2);
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
