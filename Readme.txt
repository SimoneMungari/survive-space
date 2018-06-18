ITALIANO

ISTRUZIONI PER IL CORRETTO AVVIO DEL GIOCO

Step 1:
Scaricare NCURSES, SFML, PTHREAD;
	sudo apt-get install libncurses5-dev
	sudo apt-get install libsfml-dev
	sudo apt-get install libpthread-stubs0-dev

Step 2:
Apri il terminale e vai nella cartella Progetto/src;

Step 3:
Compila il gioco tramite il seguente comando:
	g++ *.cpp -lncurses -lpthread -lsfml-audio -lsfml-system -o SurviveSpace

Ora puoi giocare!
	./SurviveSpace


CONSIGLIO:
Si consiglia di consultare il TUTORIAL presente nel menù principale del gioco.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ENGLISH

INSTRUCTIONS FOR STARTING THE GAME CORRECTLY

Step 1:
Download NCURSES, SFML, PTHREAD;
	sudo apt-get install libncurses5-dev
	sudo apt-get install libsfml-dev
	sudo apt-get install libpthread-stubs0-dev

Step 2:
Open console and go to the folder Progetto/src;

Step 3:
Compile the game using the following command:
	g++ *.cpp -lncurses -lpthread -lsfml-audio -lsfml-system -o SurviveSpace

Now you can play!
	./SurviveSpace


ADVICE:
It is recommended to consult the TUTORIAL present in the main menu of the game.
