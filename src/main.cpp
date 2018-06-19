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
	menu(); 	//Menu principale
	while(running)	//Inizio Gioco se running=true
	{
		start();
		if(reset)	//In caso di un'altra partita
		{
			chiusura();
			pulisciSchermo();
			schermataFine();
			menu();
		}
		
	}
			//Fine gioco
	return 0;


}


void menu()
{
	soundB.loadFromFile("../music/menuClick.wav");	// Inizializzazione suoni e musica per il menu
	sound.setBuffer(soundB);			
	sound.setVolume(100);
	music.setVolume(50);
	music.openFromFile("../music/menu.wav");
	music.play();
	music.setLoop(true);				//Loop=true la musica se finisce deve ricominciare		
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
	string scelte[5]={"GIOCA PARTITA","TUTORIAL","SCOREBOARD", "CREDITI", "ESCI"};	//Dichiarazione e inizializzazione delle variabili per
	int scelta=0;									// il menu
	int evidenziato=0;	// Evidenziato indica dove il cursore è posizionato
	int sceltafinale=-1;	// 
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
			wattron(menuwin, A_REVERSE);	//Evidenzia il testo
			attron(COLOR_PAIR(5));		//Colora il testo
			mvprintw((LINES/2)+i+1,COLS/2-5,scelte[i].c_str());	//Stampa "Gioca partita" "Tutorial" ecc ecc
			attroff(COLOR_PAIR(5));
			wattroff(menuwin, A_REVERSE);
		}
		scelta= getch();	//Prende in input la scelta del giocatore
		switch(scelta)
		{
			case KEY_UP:
				{
					evidenziato--;
					if(evidenziato==-1)	//Controllo per non sforare, se sei su "Gioca partita" non puoi andare ancora
					evidenziato=0;		//più su, quindi rimette evidenziato su 0 che è la prima scelta:"Gioca partita"
					break;
				}
			case KEY_DOWN:
				{
					evidenziato++;
					if(evidenziato==5) //Stesso controllo per l'ultima scelta
						evidenziato=4;
					break;
				}
			case '\n':
				{
					sound.play(); 
					sceltafinale=evidenziato; //Salva la scelta dell'utente in base a quale scritta è evidenziata
					break;
				}
			default:
				break;
		}
		switch(sceltafinale)	//Se la scelta è fra 1/2/3 rimane dentro il loop perchè dopo aver mostrato i Crediti (esempio) il gioco
		{			// ritorna al menu, non deve uscire
			case 1:{ tutorial(); sceltafinale=-1; break;} 	//Se la scelta ricade fra uno di questi, sceltafinale viene impostata
			case 2:{ scoreboard(); sceltafinale=-1; break;} // a -1, come valore di default per capire che deve rimanere nel while
			case 3:{ crediti(); sceltafinale=-1; break;}	// 
			default:{ break;}
				
		}
		if(sceltafinale!=-1) //Quindi se la scelta è diversa da -1 (vuol dire che l'utente non ha scelto 1/2/3) allora deve uscire dal
			menuloop=false; // loop, perchè ciò vuol dire che ha scelto 0/4 (Gioca partita o Esci)
	}
	music.stop();
	pulisciSchermo();
	endwin();
	if(sceltafinale==0) //L'utente ha scelto "Gioca Partita", imposta running=true così il gioco può iniziare
		running=true;
	else if(sceltafinale==4) //L'utente ha scelto "Esci", imposta running=false così il gioco termina
		running=false;
}

void preStart()
{
	stampaCampoGioco(); //Stampa il campo di Gioco
	refresh();
	soundB.loadFromFile("../music/countdown.wav"); //
	sound.setBuffer(soundB);		       //
	sound.play();			  	       //	Inizializzazione e inizio del suono per il Countdown
	sound.setPlayingOffset(sf::seconds(7));        //con un offset di 7 secondi (perchè il suono inizialmente fa partire il countdown da 10
	usleep(4E+6);				       // 	Aspetta 4 secondi
	soundB.loadFromFile("../music/partenza.wav");  //	
	sound.setVolume(100);			       //
	sound.play();				       //	Avvio del suono della navicella
	usleep(1E+6);
}

void start()
{
	pthread_t pEnemy; //Dichiarazione del thread pEnemy
	nNemici=6; //Reinizializzazione del num dei nemici per una partita successiva, il num nemici ad inizio partita deve sempre essere 6
	WINDOW *win;
	win=initscr();
	cbreak();
	keypad(win, TRUE);
	noecho();
	nodelay(win, TRUE);
	curs_set(0);
	pthread_mutex_init(&mutexGame,NULL); //Inizializzazione del mutex per gestire le operazioni dei thread
	preStart();	// Chiamata alla funzione preStart per il countdown
	music.openFromFile("../music/game.wav"); 	// Inizializzazione della musica che ci sarà per tutto il gioco
	music.setVolume(50);
	music.play();
	music.setLoop(true);
	for(int i=0;i<16;i++)
	{	
		enemy[i]=new Enemy();	//Creazione degli oggetti Enemy puntati all'interno dell'array 
	}
	pthread_create(&pEnemy, NULL, enemyInit,NULL); //Avvio del Thread pEnemy chiamando la funzione "enemyInit" senza passaggio di parametri
	playerF(); 	//Chiamata della funzione principale "playerF()" nel quale verrà gestita la navicella
	pthread_join(pEnemy,NULL);//Quando playerF finirà le sue istruzioni, pthread_join aspetta che finisca il thread pEnemy prima di
				  //far finire il gioco
	music.stop();
}
