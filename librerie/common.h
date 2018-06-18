#ifndef COMMON_H
#define COMMON_H

#include "../librerie/player.h"
#include "../librerie/enemy.h"
#include "../librerie/savegame.h"
#include <string>
#include <pthread.h>
#include <SFML/Audio.hpp>
#include <unistd.h>

//VARIABILI GLOBALI
extern pthread_mutex_t mutexGame;
extern Enemy* enemy[16];
extern Player* player;
extern int dirProiettile;
extern bool running;
extern bool reset;
extern int nNemici;
extern string user;
extern sf::SoundBuffer soundB;
extern sf::Sound sound;
extern sf::Music music;

extern void stampaCampoGioco();

#endif
