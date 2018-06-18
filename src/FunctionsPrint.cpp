#include "../librerie/common.h"

//FUNZIONI STAMPA E CHIUSURA
extern void tutorial();		
extern void crediti();			
extern void stampaScrittaIniziale();
extern void pulisciSchermo();
extern void schermataFine();
extern void salvataggioDati();	
extern void scoreboard();
extern void chiusura();

void stampaScrittaIniziale()
{
    	init_color(COLOR_RED, 1000, 0, 0);
    	init_color(COLOR_BLUE, 321, 568, 937);		
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_WHITE,COLOR_BLACK);	
	attron(COLOR_PAIR(4));
      mvprintw(LINES-LINES+5,COLS/2-58,R"(  _______           _______          _________          _______         _______  _______  _______  _______  _______ )");
      mvprintw(LINES-LINES+6,COLS/2-58,R"( (  ____ \|\     /|(  ____ )|\     /|\__   __/|\     /|(  ____ \       (  ____ \(  ____ )(  ___  )(  ____ \(  ____ \)");
      mvprintw(LINES-LINES+7,COLS/2-58,R"( | (    \/| )   ( || (    )|| )   ( |   ) (   | )   ( || (    \/       | (    \/| (    )|| (   ) || (    \/| (    \/)");
      mvprintw(LINES-LINES+8,COLS/2-58,R"( | (_____ | |   | || (____)|| |   | |   | |   | |   | || (__           | (_____ | (____)|| (___) || |      | (__    )");
      mvprintw(LINES-LINES+9,COLS/2-58,R"( (_____  )| |   | ||     __)( (   ) )   | |   ( (   ) )|  __)          (_____  )|  _____)|  ___  || |      |  __)   )");
     mvprintw(LINES-LINES+10,COLS/2-58,R"(       ) || |   | || (\ (    \ \_/ /    | |    \ \_/ / | (                   ) || (      | (   ) || |      | (      )");
     mvprintw(LINES-LINES+11,COLS/2-58,R"( /\____) || (___) || ) \ \__  \   /  ___) (___  \   /  | (____/\       /\____) || )      | )   ( || (____/\| (____/\)");
     mvprintw(LINES-LINES+12,COLS/2-58,R"( \_______)(_______)|/   \__/   \_/   \_______/   \_/   (_______/       \_______)|/       |/     \|(_______/(_______/)");
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(1));
	mvprintw(LINES/2+10,COLS-COLS+2,R"(   ,    )");
	mvprintw(LINES/2+11,COLS-COLS+2,R"(__/ \__ )");
	mvprintw(LINES/2+12,COLS-COLS+2,R"(\     / )");
	mvprintw(LINES/2+13,COLS-COLS+2,R"(/_   _\ )");
	mvprintw(LINES/2+14,COLS-COLS+2,R"(  \ /   )");
	mvprintw(LINES/2+15,COLS-COLS+2,R"(   '    )");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvprintw(LINES/2+1,20,R"(   ,    )");
	mvprintw(LINES/2+2,20,R"(__/ \__ )");
	mvprintw(LINES/2+3,20,R"(\     / )");
	mvprintw(LINES/2+4,20,R"(/_   _\ )");
	mvprintw(LINES/2+5,20,R"(  \ /   )");
	mvprintw(LINES/2+6,20,R"(   '    )");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(LINES/2+7,50,R"(   ,    )");
	mvprintw(LINES/2+8,50,R"(__/ \__ )");
	mvprintw(LINES/2+9,50,R"(\     / )");
	mvprintw(LINES/2+10,50,R"(/_   _\ )");
	mvprintw(LINES/2+11,50,R"(  \ /   )");
	mvprintw(LINES/2+12,50,R"(   '    )");
	attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(1));
	mvprintw(LINES/2+2,80,R"(   ,    )");
	mvprintw(LINES/2+3,80,R"(__/ \__ )");
	mvprintw(LINES/2+4,80,R"(\     / )");
	mvprintw(LINES/2+5,80,R"(/_   _\ )");
	mvprintw(LINES/2+6,80,R"(  \ /   )");
	mvprintw(LINES/2+7,80,R"(   '    )");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvprintw(LINES/2,120,R"(   ,    )");
	mvprintw(LINES/2+1,120,R"(__/ \__ )");
	mvprintw(LINES/2+2,120,R"(\     / )");
	mvprintw(LINES/2+3,120,R"(/_   _\ )");
	mvprintw(LINES/2+4,120,R"(  \ /   )");
	mvprintw(LINES/2+5,120,R"(   '    )");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(LINES/2+11,110,R"(   ,    )");
	mvprintw(LINES/2+12,110,R"(__/ \__ )");
	mvprintw(LINES/2+13,110,R"(\     / )");
	mvprintw(LINES/2+14,110,R"(/_   _\ )");
	mvprintw(LINES/2+15,110,R"(  \ /   )");
	mvprintw(LINES/2+16,110,R"(   '    )");
        attroff(COLOR_PAIR(3));
}
void pulisciSchermo()
{
	for(int i=0;i<LINES;i++)
	{
		for(int j=0;j<COLS;j++)
		{
			mvprintw(i,j," ");
		}
	}
}

void tutorial()
{
	pulisciSchermo();
	while(true)
	{
		attron(COLOR_PAIR(3));
		mvprintw(LINES/2-13,COLS/2-25,R"(___________      __               .__       .__   )");
		mvprintw(LINES/2-12,COLS/2-25,R"(\__    ___/_ ___/  |_  ___________|__|____  |  |  )");
		mvprintw(LINES/2-11,COLS/2-25,R"(  |    | |  |  \   __\/  _ \_  __ \  \__  \ |  |  )");
		mvprintw(LINES/2-10,COLS/2-25,R"(  |    | |  |  /|  | (  <_> )  | \/  |/ __ \|  |__)");
		mvprintw(LINES/2-9,COLS/2-25,R"(  |____| |____/ |__|  \____/|__|  |__(____  /____/)");
		mvprintw(LINES/2-8,COLS/2-25,R"(                                          \/      )");
		attroff(COLOR_PAIR(3));
		
		mvprintw(LINES/2-5,COLS/2-10,"COMANDI DI MOVIMENTO:");
		mvprintw(LINES/2-4,COLS/2-17,"Spostarsi verso sopra------Freccia Su");
		mvprintw(LINES/2-3,COLS/2-17,"Spostarsi verso sotto------Freccia Giu");
		mvprintw(LINES/2-2,COLS/2-17,"Spostarsi verso destra-----Freccia Destra");
		mvprintw(LINES/2-1,COLS/2-17,"Spostarsi verso sinistra---Freccia Sinistra");

		mvprintw(LINES/2+1,COLS/2-10,"COMANDI PER SPARARE:");
		mvprintw(LINES/2+2,COLS/2-11,"Sparare verso sopra------W");
		mvprintw(LINES/2+3,COLS/2-11,"Sparare verso sotto------S");
		mvprintw(LINES/2+4,COLS/2-11,"Sparare verso destra-----D");
		mvprintw(LINES/2+5,COLS/2-11,"Sparare verso sinistra---A");

		mvprintw(LINES/2+7,COLS/2-4,"CONSIGLO:");
		mvprintw(LINES/2+8,COLS/2-20,"Si consiglia di giocare a schermo intero,");
		mvprintw(LINES/2+9,COLS/2-43,"la grafica del gioco potrebbe essere distorta a causa di una risoluzione troppo bassa");
		mvprintw(LINES/2+12,COLS/2-9,"BUON DIVERTIMENTO!");

		mvprintw(LINES-2,COLS/2-14,"Premi M per tornare indietro");
		int mossa;	
		mossa=getch();
		if(mossa=='m')
		{
			pulisciSchermo();
			return;
		}
	}
}

void stampaCampoGioco()
{
	//ALTO A DESTRA
	attron(COLOR_PAIR(1));
	mvprintw(LINES/2-17,COLS/2+20,R"(   ,    )");
	mvprintw(LINES/2-16,COLS/2+20,R"(__/ \__ )");
	mvprintw(LINES/2-15,COLS/2+20,R"(\     / )");
	mvprintw(LINES/2-14,COLS/2+20,R"(/_   _\ )");
	mvprintw(LINES/2-13,COLS/2+20,R"(  \ /   )");
	mvprintw(LINES/2-12,COLS/2+20,R"(   '    )");
        attroff(COLOR_PAIR(1));
							
	attron(COLOR_PAIR(2));
	mvprintw(LINES/2-10,COLS/2+25,R"(   ,    )");
	mvprintw(LINES/2-9,COLS/2+25,R"(__/ \__ )");
	mvprintw(LINES/2-8,COLS/2+25,R"(\     / )");
	mvprintw(LINES/2-7,COLS/2+25,R"(/_   _\ )");
	mvprintw(LINES/2-6,COLS/2+25,R"(  \ /   )");
	mvprintw(LINES/2-5,COLS/2+25,R"(   '    )");
        attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(LINES/2-16,COLS/2+40,R"(         .)");
	mvprintw(LINES/2-15,COLS/2+40,R"(       \ | /)");
	mvprintw(LINES/2-14,COLS/2+40,R"(     '-.;;;.-')");
	mvprintw(LINES/2-13,COLS/2+40,R"(    -==;;;;;==-)");
	mvprintw(LINES/2-12,COLS/2+40,R"(     .-';;;'-.)");
	mvprintw(LINES/2-11,COLS/2+40,R"(       / | \)");
	mvprintw(LINES/2-10,COLS/2+40,R"(         ')");
        attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(4));
	mvprintw(LINES/2-10,COLS/2+57,R"(      ,)");
	mvprintw(LINES/2-9,COLS/2+57,R"(   \  :  /)");
	mvprintw(LINES/2-8,COLS/2+57,R"(`. __/ \__ .')");
	mvprintw(LINES/2-7,COLS/2+57,R"(_ _\     /_ _)");
	mvprintw(LINES/2-6,COLS/2+57,R"(   /_   _\)");
	mvprintw(LINES/2-5,COLS/2+57,R"( .'  \ /  `.)");
	mvprintw(LINES/2-4,COLS/2+57,R"(   /  :  \    )");
	mvprintw(LINES/2-3,COLS/2+57,R"(      ')");
        attroff(COLOR_PAIR(4));

	//ALTO A SINISTRA
	attron(COLOR_PAIR(1));
	mvprintw(LINES/2-18,COLS/2-70,R"(   ,    )");
	mvprintw(LINES/2-17,COLS/2-70,R"(__/ \__ )");
	mvprintw(LINES/2-16,COLS/2-70,R"(\     / )");
	mvprintw(LINES/2-15,COLS/2-70,R"(/_   _\ )");
	mvprintw(LINES/2-14,COLS/2-70,R"(  \ /   )");
	mvprintw(LINES/2-13,COLS/2-70,R"(   '    )");
        attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvprintw(LINES/2-17,COLS/2-50,R"(   ,    )");
	mvprintw(LINES/2-16,COLS/2-50,R"(__/ \__ )");
	mvprintw(LINES/2-15,COLS/2-50,R"(\     / )");
	mvprintw(LINES/2-14,COLS/2-50,R"(/_   _\ )");
	mvprintw(LINES/2-13,COLS/2-50,R"(  \ /   )");
	mvprintw(LINES/2-12,COLS/2-50,R"(   '    )");
        attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(LINES/2-12,COLS/2-30,R"(      ,)");
	mvprintw(LINES/2-11,COLS/2-30,R"(   \  :  /)");
	mvprintw(LINES/2-10,COLS/2-30,R"(`. __/ \__ .')");
	mvprintw(LINES/2-9,COLS/2-30,R"(_ _\     /_ _)");
	mvprintw(LINES/2-8,COLS/2-30,R"(   /_   _\)");
	mvprintw(LINES/2-7,COLS/2-30,R"( .'  \ /  `.)");
	mvprintw(LINES/2-6,COLS/2-30,R"(   /  :  \    )");
	mvprintw(LINES/2-5,COLS/2-30,R"(      ')");
        attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(4));
	mvprintw(LINES/2-11,COLS/2-65,R"(         _.._)");
	mvprintw(LINES/2-10,COLS/2-65,R"(        .' .-'`)");
	mvprintw(LINES/2-9,COLS/2-65,R"(       /  /)");
	mvprintw(LINES/2-8,COLS/2-65,R"(       |  |)");
	mvprintw(LINES/2-7,COLS/2-65,R"(       \  '.___.;)");
	mvprintw(LINES/2-6,COLS/2-65,R"(        '._  _.')");
	mvprintw(LINES/2-5,COLS/2-65,R"(           ``)");
        attroff(COLOR_PAIR(4));

	//BASSO A SINISTRA
	attron(COLOR_PAIR(1));
	mvprintw(LINES/2+11,COLS/2-70,R"(   ,    )");
	mvprintw(LINES/2+12,COLS/2-70,R"(__/ \__ )");
	mvprintw(LINES/2+13,COLS/2-70,R"(\     / )");
	mvprintw(LINES/2+14,COLS/2-70,R"(/_   _\ )");
	mvprintw(LINES/2+15,COLS/2-70,R"(  \ /   )");
	mvprintw(LINES/2+16,COLS/2-70,R"(   '    )");
        attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvprintw(LINES/2+7,COLS/2-60,R"(   ,    )");
	mvprintw(LINES/2+8,COLS/2-60,R"(__/ \__ )");
	mvprintw(LINES/2+9,COLS/2-60,R"(\     / )");
	mvprintw(LINES/2+10,COLS/2-60,R"(/_   _\ )");
	mvprintw(LINES/2+11,COLS/2-60,R"(  \ /   )");
	mvprintw(LINES/2+12,COLS/2-60,R"(   '    )");
        attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(LINES/2+5,COLS/2-45,R"(         ___---___)");
	mvprintw(LINES/2+6,COLS/2-45,R"(      .--         --. )");
	mvprintw(LINES/2+7,COLS/2-45,R"(    ./   ()      .-. \.)");
	mvprintw(LINES/2+8,COLS/2-45,R"(   /   o    .   (   )  \)");
	mvprintw(LINES/2+9,COLS/2-45,R"(  / .            '-'    \)");
	mvprintw(LINES/2+10,COLS/2-45,R"( | ()    .  O         .  |)");
	mvprintw(LINES/2+11,COLS/2-45,R"(|                         |)");
	mvprintw(LINES/2+12,COLS/2-45,R"(|    o           ()       |)");
	mvprintw(LINES/2+13,COLS/2-45,R"(|       .--.          O   |)");
	mvprintw(LINES/2+14,COLS/2-45,R"( | .   |    |            |)");
	mvprintw(LINES/2+15,COLS/2-45,R"(  \    `.__.'    o   .  /)");
	mvprintw(LINES/2+16,COLS/2-45,R"(   \                   /)");
	mvprintw(LINES/2+17,COLS/2-45,R"(    `\  o    ()      /')");
	mvprintw(LINES/2+18,COLS/2-45,R"(      `--___   ___--')");
	mvprintw(LINES/2+19,COLS/2-45,R"(            ---)");
        attroff(COLOR_PAIR(3));

	//BASSO A DESTRA

	attron(COLOR_PAIR(1));
	mvprintw(LINES/2+11,COLS/2+50,R"(   ,    )");
	mvprintw(LINES/2+12,COLS/2+50,R"(__/ \__ )");
	mvprintw(LINES/2+13,COLS/2+50,R"(\     / )");
	mvprintw(LINES/2+14,COLS/2+50,R"(/_   _\ )");
	mvprintw(LINES/2+15,COLS/2+50,R"(  \ /   )");
	mvprintw(LINES/2+16,COLS/2+50,R"(   '    )");
        attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvprintw(LINES/2+9,COLS/2+30,R"(         _.._)");
	mvprintw(LINES/2+10,COLS/2+30,R"(        .' .-'`)");
	mvprintw(LINES/2+11,COLS/2+30,R"(       /  /)");
	mvprintw(LINES/2+12,COLS/2+30,R"(       |  |)");
	mvprintw(LINES/2+13,COLS/2+30,R"(       \  '.___.;)");
	mvprintw(LINES/2+14,COLS/2+30,R"(        '._  _.')");
	mvprintw(LINES/2+15,COLS/2+30,R"(           ``)");
        attroff(COLOR_PAIR(2));

	//CAMPO DI GIOCO
	mvprintw((LINES/2)-3,(COLS/2)-18,"O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O");			
	mvprintw((LINES/2)-2,(COLS/2)-18,"[");
	mvprintw((LINES/2)-1,(COLS/2)-18,"[");
	mvprintw((LINES/2),(COLS/2)-18,"[");
	mvprintw((LINES/2)+1,(COLS/2)-18,"[");
	mvprintw((LINES/2)+2,(COLS/2)-18,"[");
	mvprintw((LINES/2)+3,(COLS/2)-18,"[");
	mvprintw((LINES/2)+4,(COLS/2)-18,"[");
	mvprintw((LINES/2)+5,(COLS/2)-18,"[");			
	mvprintw((LINES/2)-2,(COLS/2)+18,"]");
	mvprintw((LINES/2)-1,(COLS/2)+18,"]");
	mvprintw((LINES/2),(COLS/2)+18,"]");
	mvprintw((LINES/2)+1,(COLS/2)+18,"]");
	mvprintw((LINES/2)+2,(COLS/2)+18,"]");	
	mvprintw((LINES/2)+3,(COLS/2)+18,"]");	
	mvprintw((LINES/2)+4,(COLS/2)+18,"]");	
	mvprintw((LINES/2)+5,(COLS/2)+18,"]");		
	mvprintw((LINES/2)+5,(COLS/2)-18,"O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O");		
}

void crediti()
{
	pulisciSchermo();
	while(true)
	{
		attron(COLOR_PAIR(1));
		mvprintw(LINES/2+8,COLS/2-50,R"(   ,    )");
		mvprintw(LINES/2+9,COLS/2-50,R"(__/ \__ )");
		mvprintw(LINES/2+10,COLS/2-50,R"(\     / )");
		mvprintw(LINES/2+11,COLS/2-50,R"(/_   _\ )");
		mvprintw(LINES/2+12,COLS/2-50,R"(  \ /   )");
		mvprintw(LINES/2+13,COLS/2-50,R"(   '    )");
		attroff(COLOR_PAIR(1));

		attron(COLOR_PAIR(2));
		mvprintw(LINES/2-4,COLS/2-37,R"(   ,    )");
		mvprintw(LINES/2-3,COLS/2-37,R"(__/ \__ )");
		mvprintw(LINES/2-2,COLS/2-37,R"(\     / )");
		mvprintw(LINES/2-1,COLS/2-37,R"(/_   _\ )");
		mvprintw(LINES/2,COLS/2-37,R"(  \ /   )");
		mvprintw(LINES/2+1,COLS/2-37,R"(   '    )");
		attroff(COLOR_PAIR(2));

		attron(COLOR_PAIR(4));
		mvprintw(LINES/2-17,COLS/2-40,R"(   ,    )");
		mvprintw(LINES/2-16,COLS/2-40,R"(__/ \__ )");
		mvprintw(LINES/2-15,COLS/2-40,R"(\     / )");
		mvprintw(LINES/2-14,COLS/2-40,R"(/_   _\ )");
		mvprintw(LINES/2-13,COLS/2-40,R"(  \ /   )");
		mvprintw(LINES/2-12,COLS/2-40,R"(   '    )");
		attroff(COLOR_PAIR(4));

		attron(COLOR_PAIR(3));
		mvprintw(LINES/2-8,COLS/2+13,R"(                      <>)");
		mvprintw(LINES/2-7,COLS/2+13,R"(        .-"""-.       ||::::::==========)");
		mvprintw(LINES/2-6,COLS/2+13,R"(       /= ___  \      ||::::::==========)");
		mvprintw(LINES/2-5,COLS/2+13,R"(      |- /~~~\  |     ||::::::==========)");
		mvprintw(LINES/2-4,COLS/2+13,R"(      |=( '.' ) |     ||================)");
		mvprintw(LINES/2-3,COLS/2+13,R"(      \__\_=_/__/     ||================)");
		mvprintw(LINES/2-2,COLS/2+13,R"(       {_______}      ||================)");
		mvprintw(LINES/2-1,COLS/2+13,R"(     /` *       `'--._||)");
		mvprintw(LINES/2,COLS/2+13,R"(    /= .     [] .     { >)");
		mvprintw(LINES/2+1,COLS/2+13,R"(   /  /|ooo     |`'--'|| )");
		mvprintw(LINES/2+2,COLS/2+13,R"(  (   )\_______/      ||)");
		mvprintw(LINES/2+3,COLS/2+13,R"(   \``\/       \      ||)");
		mvprintw(LINES/2+4,COLS/2+13,R"(    `-| ==    \_|     ||)");
		mvprintw(LINES/2+5,COLS/2+13,R"(      /         |     ||)");
		mvprintw(LINES/2+6,COLS/2+13,R"(     |=   >\  __/     ||)");
		mvprintw(LINES/2+7,COLS/2+13,R"(     \   \ |- --|     ||)");
		mvprintw(LINES/2+8,COLS/2+13,R"(      \ __| \___/     ||)");
		mvprintw(LINES/2+9,COLS/2+13,R"(      _{__} _{__}     ||)");
		mvprintw(LINES/2+10,COLS/2+13,R"(     (    )(    )     ||)");
		mvprintw(LINES/2+11,COLS/2+13,R"( ^^~  `"""  `"""  ~^^^~^^~~~^^^~^^^~^^^~^^~^)");
		attroff(COLOR_PAIR(3));

		attron(COLOR_PAIR(1));
	      	mvprintw(LINES/2-15,COLS/2-23,R"(_________                    .___.__  __  .__ )");
	      	mvprintw(LINES/2-14,COLS/2-23,R"(\_   ___ \_______   ____   __| _/|__|/  |_|__|)");
	      	mvprintw(LINES/2-13,COLS/2-23,R"(/    \  \/\_  __ \_/ __ \ / __ | |  \   __\  |)");
	      	mvprintw(LINES/2-12,COLS/2-23,R"(\     \____|  | \/\  ___// /_/ | |  ||  | |  |)");
	      	mvprintw(LINES/2-11,COLS/2-23,R"( \______  /|__|    \___  >____ | |__||__| |__|)");
		mvprintw(LINES/2-10,COLS/2-23,R"(        \/             \/     \/              )");
		attroff(COLOR_PAIR(1));
		mvprintw(LINES/2-4,COLS/2-10,"-*-*-*-*-*-*-*-*-*-*-*");
		mvprintw(LINES/2+3,COLS/2-10,"-*-*-*-*-*-*-*-*-*-*-*");
		mvprintw(LINES/2-3,COLS/2-10,"|");
		mvprintw(LINES/2-2,COLS/2-10,"(");
		mvprintw(LINES/2-1,COLS/2-10,"|");
		mvprintw(LINES/2,COLS/2-10,"(");
		mvprintw(LINES/2+1,COLS/2-10,"|");
		mvprintw(LINES/2+2,COLS/2-10,"(");


		mvprintw(LINES/2-3,COLS/2+11,"|");
		mvprintw(LINES/2-2,COLS/2+11,")");
		mvprintw(LINES/2-1,COLS/2+11,"|");
		mvprintw(LINES/2,COLS/2+11,")");
		mvprintw(LINES/2+1,COLS/2+11,"|");
		mvprintw(LINES/2+2,COLS/2+11,")");

		mvprintw(LINES/2-2,COLS/2-4,"CREATO DA:");
		mvprintw((LINES/2)-1,COLS/2-6,"SIMONE MUNGARI");
		mvprintw((LINES/2),COLS/2-8,"CdL: Informatica");
		mvprintw((LINES/2)+1,COLS/2-8,"Matricola: 190042");
	
		mvprintw(LINES-2,COLS/2-14,"Premi M per tornare indietro");
		int mossa;	
		mossa=getch();
		if(mossa=='m')
		{
			pulisciSchermo();
			return;
		}
	}
	
}

void scoreboard()
{
	pulisciSchermo();
	vector<string> v;
	Savegame* s=new Savegame();
	v.clear();
	s->load(v);
	while(true)
	{
		for(int i=0;((i<v.size()) && (i<10));i++)
		{
			if(i<9)
				mvprintw(i+(LINES-25),COLS/2-5,"%d) %s \n",i+1,v[i].c_str());
			else
				mvprintw(i+(LINES-25),COLS/2-6,"%d) %s \n",i+1,v[i].c_str());
		}
		attron(COLOR_PAIR(1));
	      	mvprintw(LINES/2-15,COLS/2-35,R"(  _________                         ___.                          .___)");
	      	mvprintw(LINES/2-14,COLS/2-35,R"( /   _____/ ____  ___________   ____\_ |__   _________ _______  __| _/)");
	      	mvprintw(LINES/2-13,COLS/2-35,R"( \_____  \_/ ___\/  _ \_  __ \_/ __ \| __ \ /  _ \__  \\_  __ \/ __ | )");
	      	mvprintw(LINES/2-12,COLS/2-35,R"( /        \  \__(  <_> )  | \/\  ___/| \_\ (  <_> ) __ \|  | \/ /_/ | )");
	      	mvprintw(LINES/2-11,COLS/2-35,R"(/_______  /\___  >____/|__|    \___  >___  /\____(____  /__|  \____ | )");
		mvprintw(LINES/2-10,COLS/2-35,R"(        \/     \/                  \/    \/           \/           \/ )");
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(2));
		mvprintw(LINES/2-15,COLS/2+38,R"(   ,    )");
		mvprintw(LINES/2-14,COLS/2+38,R"(__/ \__ )");
		mvprintw(LINES/2-13,COLS/2+38,R"(\     / )");
		mvprintw(LINES/2-12,COLS/2+38,R"(/_   _\ )");
		mvprintw(LINES/2-11,COLS/2+38,R"(  \ /   )");
		mvprintw(LINES/2-10,COLS/2+38,R"(   '    )");
		attroff(COLOR_PAIR(2));
		
		attron(COLOR_PAIR(3));
		mvprintw(LINES/2-13,COLS/2+50,R"(   ,    )");
		mvprintw(LINES/2-12,COLS/2+50,R"(__/ \__ )");
		mvprintw(LINES/2-11,COLS/2+50,R"(\     / )");
		mvprintw(LINES/2-10,COLS/2+50,R"(/_   _\ )");
		mvprintw(LINES/2-9,COLS/2+50,R"(  \ /   )");
		mvprintw(LINES/2-8,COLS/2+50,R"(   '    )");
		attroff(COLOR_PAIR(3));


		attron(COLOR_PAIR(4));
		mvprintw(LINES/2-15,COLS/2-50,R"(   ,    )");
		mvprintw(LINES/2-14,COLS/2-50,R"(__/ \__ )");
		mvprintw(LINES/2-13,COLS/2-50,R"(\     / )");
		mvprintw(LINES/2-12,COLS/2-50,R"(/_   _\ )");
		mvprintw(LINES/2-11,COLS/2-50,R"(  \ /   )");
		mvprintw(LINES/2-10,COLS/2-50,R"(   '    )");
		attroff(COLOR_PAIR(4));

		attron(COLOR_PAIR(1));
		mvprintw(LINES/2-5,COLS/2-28,R"(   ,    )");
		mvprintw(LINES/2-4,COLS/2-28,R"(__/ \__ )");
		mvprintw(LINES/2-3,COLS/2-28,R"(\     / )");
		mvprintw(LINES/2-2,COLS/2-28,R"(/_   _\ )");
		mvprintw(LINES/2-1,COLS/2-28,R"(  \ /   )");
		mvprintw(LINES/2,COLS/2-28,R"(   '    )");
		attroff(COLOR_PAIR(1));

		attron(COLOR_PAIR(1));
		mvprintw(LINES/2-5,COLS/2+10,R"(        _..._)");
		mvprintw(LINES/2-4,COLS/2+10,R"(      .'     '.      _)");
		mvprintw(LINES/2-3,COLS/2+10,R"(     /    .-""-\   _/ \)");
		mvprintw(LINES/2-2,COLS/2+10,R"(   .-|   /:.   |  |   |)");
		mvprintw(LINES/2-1,COLS/2+10,R"(   |  \  |:.   /.-'-./)");
		mvprintw(LINES/2,COLS/2+10,R"(   | .-'-;:__.'    =/)");
		mvprintw(LINES/2+1,COLS/2+10,R"(   .'=  *=|     _.=')");
		mvprintw(LINES/2+2,COLS/2+10,R"(  /   _.  |    ;)");
		mvprintw(LINES/2+3,COLS/2+10,R"( ;-.-'|    \   |)");
		mvprintw(LINES/2+4,COLS/2+10,R"(/   | \    _\  _\)");
		mvprintw(LINES/2+5,COLS/2+10,R"(\__/'._;.  ==' ==\)");
		mvprintw(LINES/2+6,COLS/2+10,R"(         \    \   |)");
		mvprintw(LINES/2+7,COLS/2+10,R"(         /    /   /)");
		mvprintw(LINES/2+8,COLS/2+10,R"(         /-._/-._/)");
		mvprintw(LINES/2+9,COLS/2+10,R"(         \   `\  \)");
		mvprintw(LINES/2+10,COLS/2+10,R"(          `-._/._/)");
		attroff(COLOR_PAIR(1));

		attron(COLOR_PAIR(3));
		mvprintw(LINES/2+11,COLS/2+10,R"(   ,    )");
		mvprintw(LINES/2+12,COLS/2+10,R"(__/ \__ )");
		mvprintw(LINES/2+13,COLS/2+10,R"(\     / )");
		mvprintw(LINES/2+14,COLS/2+10,R"(/_   _\ )");
		mvprintw(LINES/2+15,COLS/2+10,R"(  \ /   )");
		mvprintw(LINES/2+16,COLS/2+10,R"(   '    )");
		attroff(COLOR_PAIR(3));

		attron(COLOR_PAIR(2));
		mvprintw(LINES/2+7,COLS/2-37,R"(   ,    )");
		mvprintw(LINES/2+8,COLS/2-37,R"(__/ \__ )");
		mvprintw(LINES/2+9,COLS/2-37,R"(\     / )");
		mvprintw(LINES/2+10,COLS/2-37,R"(/_   _\ )");
		mvprintw(LINES/2+11,COLS/2-37,R"(  \ /   )");
		mvprintw(LINES/2+12,COLS/2-37,R"(   '    )");
		attroff(COLOR_PAIR(2));

		attron(COLOR_PAIR(4));
		mvprintw(LINES/2+11,COLS/2+50,R"(   ,    )");
		mvprintw(LINES/2+12,COLS/2+50,R"(__/ \__ )");
		mvprintw(LINES/2+13,COLS/2+50,R"(\     / )");
		mvprintw(LINES/2+14,COLS/2+50,R"(/_   _\ )");
		mvprintw(LINES/2+15,COLS/2+50,R"(  \ /   )");
		mvprintw(LINES/2+16,COLS/2+50,R"(   '    )");
		attroff(COLOR_PAIR(4));
		int mossa;	
		mvprintw(LINES-2,COLS/2-14,"Premi M per tornare indietro");
		mossa=getch();
		if(mossa=='m')
		{
			pulisciSchermo();
			return;
		}
	}
}

void salvataggioDati()
{
	WINDOW * savewin= newwin(20,20,COLS/2,LINES/2);
	savewin=initscr();
	start_color();
	cbreak();
	noecho();
	nodelay(savewin, TRUE);
	curs_set(0);
	refresh();
	wrefresh(savewin);
	keypad(savewin,true);
	string scelte[3]={"Si", "No"};
	int scelta;
	int evidenziato=0;
	int sceltafinale=-1;
	while(true)
	{
		attron(COLOR_PAIR(1));
	      	mvprintw(LINES/2-13,COLS/2-42,R"(____   ____           .__    _________      .__                           _________ )");
	      	mvprintw(LINES/2-12,COLS/2-42,R"(\   \ /   /_ __  ____ |__|  /   _____/____  |  |___  _______ _______   ___\_____   \)");
	      	mvprintw(LINES/2-11,COLS/2-42,R"( \   Y   /  |  \/  _ \|  |  \_____  \\__  \ |  |\  \/ /\__  \\_  __ \_/ __ \ /   __/)");
	      	mvprintw(LINES/2-10,COLS/2-42,R"(  \     /|  |  (  <_> )  |  /        \/ __ \|  |_\   /  / __ \|  | \/\  ___/|   |   )");
	      	mvprintw(LINES/2-9,COLS/2-42,R"(   \___/ |____/ \____/|__| /_______  (____  /____/\_/  (____  /__|    \___  >___|   )");
		mvprintw(LINES/2-8,COLS/2-42,R"(                                   \/     \/                \/            \/<___>   )");
		attroff(COLOR_PAIR(1));
		refresh();
		wrefresh(savewin);
		for(int i=0;i<2;i++)
		{
			if(i==evidenziato)
			wattron(savewin, A_REVERSE);
			attron(COLOR_PAIR(5));
			mvwprintw(savewin,(LINES/2)+i+1,COLS/2-5,scelte[i].c_str());
			attroff(COLOR_PAIR(5));
			wattroff(savewin, A_REVERSE);
		}
		scelta= wgetch(savewin);
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
					if(evidenziato==2)
						evidenziato=1;
					break;
				}
			case '\n':
				{
					sceltafinale=evidenziato;break;
				}
			default:
				break;
		}
		if(sceltafinale==0)
		{
			Savegame s(user,player->getEnemyKilled());
			s.save();
			endwin();
			break;
		}
		else if(sceltafinale==1)
		{
			endwin();
			break;
		}
	}
	pulisciSchermo();
}

void schermataFine()
{
	endwin();
	attron(COLOR_PAIR(4));
	running=false;
	reset=true;
	while(true)
	{
		attron(COLOR_PAIR(1));
	      	mvprintw(LINES/2-13,COLS/2-49,R"(__________              __  .__    __          __         .__  .__                        __  .__ )");
	      	mvprintw(LINES/2-12,COLS/2-49,R"(\______   \__ __  _____/  |_|__| _/  |_  _____/  |______  |  | |__|____________________ _/  |_|__|)");
	      	mvprintw(LINES/2-11,COLS/2-49,R"( |     ___/  |  \/    \   __\  | \   __\/  _ \   __\__  \ |  | |  \___   /\___   /\__  \\   __\  |)");
	      	mvprintw(LINES/2-10,COLS/2-49,R"( |    |   |  |  /   |  \  | |  |  |  | (  <_> )  |  / __ \|  |_|  |/    /  /    /  / __ \|  | |  |)");
	      	mvprintw(LINES/2-9,COLS/2-49,R"( |____|   |____/|___|  /__| |__|  |__|  \____/|__| (____  /____/__/_____ \/_____ \(____  /__| |__|)");
		mvprintw(LINES/2-8,COLS/2-49,R"(                     \/                                 \/              \/      \/     \/         )");
		attroff(COLOR_PAIR(1));

		mvprintw(LINES/2-3,COLS/2-12,"+++++++++++++++++++++++++");
		mvprintw(LINES/2-2,COLS/2-12,"+");
		mvprintw(LINES/2-1,COLS/2-12,"+");
		mvprintw(LINES/2,COLS/2-12,"+");
		mvprintw(LINES/2+1,COLS/2-12,"+");
		mvprintw(LINES/2+2,COLS/2-12,"+");

		mvprintw(LINES/2-2,COLS/2+12,"+");
		mvprintw(LINES/2-1,COLS/2+12,"+");
		mvprintw(LINES/2,COLS/2+12,"+");
		mvprintw(LINES/2+1,COLS/2+12,"+");
		mvprintw(LINES/2+2,COLS/2+12,"+");
		mvprintw(LINES/2+3,COLS/2-12,"+++++++++++++++++++++++++");
		mvprintw(LINES/2,(COLS/2),"%d",player->getEnemyKilled());
		mvprintw(LINES-2,COLS/2-15,"Premi INVIO per andare avanti!");
		refresh();
		int premuto=getch();
		if(premuto=='\n' || premuto=='\n')
		{
			endwin();
			break;
		}
	}
	attroff(COLOR_PAIR(4));
	pulisciSchermo();
	if(user!="")
		salvataggioDati();
}

void chiusura()
{	
	endwin();
	for(int i=0;i<16;i++)
		enemy[i]->~Enemy();
	player->~Player();
	
}

