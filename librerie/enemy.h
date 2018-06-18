#ifndef __ENEMY_H
#define __ENEMY_H
#include "player.h"

using namespace std;

class Enemy
{
	private:
		string forma;
		int x;
		int y;
		int vita;
		int direzione;
		bool death;
	
	public:		
		Enemy();
		bool getDeath() const;
		int getX() const;
		int getY() const;
		int getDirezione() const;
		void setX(int);
		void setDiny(int);
		void setDinx(int);
		void setDeath(bool);
		void update(int);
		void movimento(Player*);
		void visualizzaEnemy(int,int) const;
		void cancellaEnemy(bool) const;
			

};

#endif

