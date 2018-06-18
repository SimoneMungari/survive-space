#ifndef __PLAYER_H
#define __PLAYER_H
#include <ncurses.h>
#include <iostream>

using namespace std;

class Player
{
	private:
		string forma;
		int x;
		int y;
		int vita;
		int enemyKilled;
		bool su;
		bool giu;
		bool destra;
		bool sinistra;

	public:	
		Player();
		int getX() const;
		int getY() const;
		int getVita() const;
		int getEnemyKilled() const;
		void setEnemyKilled(int);
		void setVita(int);
		void Su();
		void Giu();
		void Destra();
		void Sinistra();
		void Cambio_vita(int);
		void visualizza_stat() const;
		void visualizza_player() const;
		void cancella_player() const;
		bool controlloCollisione(int,int) const;
};

#endif
