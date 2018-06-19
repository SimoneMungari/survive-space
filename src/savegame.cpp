#include "../librerie/savegame.h"

Savegame::Savegame() //Costruttore vuoto
{
	user=" ";
	score=0;
}

Savegame::Savegame(string nome, int punteggio):user(nome), score(punteggio)	//Costruttore che riceve una stringa (l'username) e il
{										//punteggio
	if(score<0)
		score=0;
}

string Savegame::getUser() const
{
	return user;
}

void Savegame::setUser(string nome)
{
	user=nome;
}

int Savegame::getScore() const
{
	return score;
}

void Savegame::setScore(int punteggio)
{
	score=punteggio;
}

void Savegame::ordina(vector<string> &v) const //Metodo per ordinare in modo decrescente i punteggi
{
	vector<int> vcopia;
	vector<string> vcopiaS;
	
	for(int i=1;i<v.size();i=i+2)			// Vengono utilizzati due vector di "comodo", uno contenente i punteggi
		vcopia.push_back(atoi(v[i].c_str())); 	// e l'altro contenente i nomi
	for(int i=0;i<v.size();i=i+2)			//
		vcopiaS.push_back(v[i]);		//
	

	int posMax=0;
	for(int i=0;i<vcopia.size()-1;i++)	//Algoritmo Selection Sort
	{
		posMax=i;
		for(int j=i+1;j<vcopia.size();j++)
		{
			if(vcopia[j]>vcopia[posMax])
			{
				posMax=j;

			}
		}
		if(posMax!=i)
		{
			int tem=vcopia[i];
			vcopia[i]=vcopia[posMax];
			vcopia[posMax]=tem;

			string temp=vcopiaS[i];
			vcopiaS[i]=vcopiaS[posMax];
			vcopiaS[posMax]=temp;
		}
	}
	vector<string> passaggio;
	for(int i=0;i<v.size();i++)	//Il vector principale viene svuotato
		v.pop_back();
	for(int i=0;i<vcopiaS.size();i++)	//Il vector principale viene riempito con i punteggi e gli username ordinati
	{
		passaggio.push_back(to_string(vcopia[i]));
		v[i]=passaggio[i];
		v[i]+=" ";
		v[i]+=vcopiaS[i];
	}


}

void Savegame::save() const
{
	ofstream ofile; //Variabile per l'input dei dati da tastiera verso il file
	ofile.open("scoreboard.txt",ios::app);	//Apertura del file "scoreboard" nel quale verranno salvati i dati
	ofile<<user<<endl<<score<<endl;		//Salvataggio dei dati
	ofile.close();	//Chiusura file
}

void Savegame::load(vector<string> &v) const
{
	ifstream ifile; //Variabile per l'output dei dati dal file verso il programma
	vector<int> vint;
	string x;
	ifile.open("scoreboard.txt");
	while(!ifile.eof()) //While fin quando non è finito il file, lo scorre tutto
	{
		ifile>>x;	//Prende la stringa dal file
		v.push_back(x);// e la posiziona nel vector
	}
	ifile.close(); // Chiusura file
	ordina(v);	//Invocazione metodo per l'ordinamento
}
