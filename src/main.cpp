#include "../librerie/common.h"
#include <time.h>
#include <math.h>

using namespace std;

//VARIABILI GLOBALI
pthread_mutex_t mutexGame;
Enemy* enemy[16];
Player* player;
int dirProiettile=0;
bool running=true;
bool reset=false;
int nNemici=6;
string user=" ";
sf::SoundBuffer soundB;
sf::Sound sound;
sf::Music music;

void start();			/*				*/
void preStart();		/*	   FUNZIONI DI 		*/
void menu();			/*				*/
void tutorial();		/*	INIZIALIZZAZIONE	*/
void crediti();			/*		E		*/
void stampaScrittaIniziale();	/*	      FINE		*/
void stampaCampoGioco();	/*				*/
void pulisciSchermo();		/*				*/
void schermataFine();		/*				*/
void salvataggioDati();		/*				*/
void scoreboard();		/*				*/
void chiusura();		/*				*/

void playerF();			//	FUNZIONI
void movimentoPlayer(int);	//	 PLAYER
void sparaSu();			//
void sparaGiu();		//
void sparaDestra();		//
void sparaSinistra();		//
void *sparato(void *);       	// FUNZIONE THREAD PROIETTILE

void *enemyInit(void *);	 // FUNZIONE THREAD NEMICO
void startEnemy();		//	FUNZIONI
void movimentoEnemy();		//	 ENEMY

void controlloDifficolta(bool[]);//	FUNZIONE CONTROLLO DIFFICOLTÀ

int main()
{	
	srand(time(NULL));
	do{
		cout<<"INSERISCI L'USERNAME (max 9 caratteri)"<<endl;
		getline(cin,user);
	}while(user.length()>9);
	menu();
	while(running)		
	{
		start();
		if(reset)
		{
			chiusura();
			pulisciSchermo();
			schermataFine();
			menu();
		}
		
	}
	return 0;


}


void menu()
{
	soundB.loadFromFile("../music/menuClick.wav");
	sound.setBuffer(soundB);
	sound.setVolume(100);
	music.setVolume(50);
	music.openFromFile("../music/menu.wav");
	music.play();
	music.setLoop(true);
	WINDOW * menuwin= newwin(20,20,COLS/2,LINES/2);
	menuwin=initscr();
	start_color();
	cbreak();
	noecho();
	nodelay(menuwin, TRUE);
	curs_set(0);
	refresh();
	wrefresh(menuwin);
	keypad(menuwin,true);
	string scelte[5]={"GIOCA PARTITA","TUTORIAL","SCOREBOARD", "CREDITI", "ESCI"};
	int scelta;
	int evidenziato=0;
	int sceltafinale=-1;
	init_pair(5,COLOR_WHITE,COLOR_BLACK);
	bool menuloop=true;
	while(menuloop)
	{
		stampaScrittaIniziale();
		refresh();
		wrefresh(menuwin);
		for(int i=0;i<5;i++)
		{
			if(i==evidenziato)
			wattron(menuwin, A_REVERSE);
			attron(COLOR_PAIR(5));
			mvprintw((LINES/2)+i+1,COLS/2-5,scelte[i].c_str());
			attroff(COLOR_PAIR(5));
			wattroff(menuwin, A_REVERSE);
		}
		scelta= getch();
		switch(scelta)
		{
			case KEY_UP:
				{
					evidenziato--;
					if(evidenziato==-1)
					evidenziato=0;
					break;
				}
			case KEY_DOWN:
				{
					evidenziato++;
					if(evidenziato==5)
						evidenziato=4;
					break;
				}
			case '\n':
				{
					sound.play();
					sceltafinale=evidenziato;
					break;
				}
			default:
				break;
		}
		switch(sceltafinale)
		{
			case 1:{ tutorial(); sceltafinale=-1; break;}
			case 2:{ scoreboard(); sceltafinale=-1; break;}
			case 3:{ crediti(); sceltafinale=-1; break;}
			default:{ break;}
				
		}
		if(sceltafinale!=-1)
			menuloop=false;
	}
	music.stop();
	pulisciSchermo();
	endwin();
	if(sceltafinale==0)
		running=true;
	else if(sceltafinale==4)
		running=false;
}

void preStart()
{
	stampaCampoGioco();
	refresh();
	soundB.loadFromFile("../music/countdown.wav");
	sound.setBuffer(soundB);
	sound.play();
	sound.setPlayingOffset(sf::seconds(7));
	usleep(4E+6);
	soundB.loadFromFile("../music/partenza.wav");
	sound.setVolume(100);
	sound.play();
	usleep(1E+6);
}

void start()
{
	pthread_t pEnemy;
	nNemici=6;
	WINDOW *win;
	win=initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	pthread_mutex_init(&mutexGame,NULL);
	preStart();
	music.openFromFile("../music/game.wav");
	music.setVolume(50);
	music.play();
	music.setLoop(true);
	for(int i=0;i<16;i++)
	{	
		enemy[i]=new Enemy();
	}
	pthread_create(&pEnemy, NULL, enemyInit,NULL);
	playerF();
	pthread_join(pEnemy,NULL);	
	music.stop();		
}
