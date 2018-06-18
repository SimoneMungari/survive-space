#include "../librerie/savegame.h"

Savegame::Savegame()
{
	user=" ";
	score=0;
}

Savegame::Savegame(string nome, int punteggio)
{
	user=nome;
	score=punteggio;
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

void Savegame::ordina(vector<string> &v) const
{
	vector<int> vcopia;
	vector<string> vcopiaS;
	
	for(int i=1;i<v.size();i=i+2)
		vcopia.push_back(atoi(v[i].c_str()));
	for(int i=0;i<v.size();i=i+2)
		vcopiaS.push_back(v[i]);
	

	int posMax;
	for(int i=0;i<vcopia.size()-1;i++)
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
	for(int i=0;i<v.size();i++)
		v.pop_back();
	for(int i=0;i<vcopiaS.size();i++)
	{
		passaggio.push_back(to_string(vcopia[i]));
		v[i]=passaggio[i];
		v[i]+=" ";
		v[i]+=vcopiaS[i];
	}


}

void Savegame::save() const
{
	ofstream ofile;
	ofile.open("scoreboard.txt",ios::app);
	ofile<<user<<endl<<score<<endl;
	ofile.close();
}

void Savegame::load(vector<string> &v) const
{
	ifstream ifile;
	vector<int> vint;
	string x;
	ifile.open("scoreboard.txt");
	while(!ifile.eof())
	{
		ifile>>x;
		v.push_back(x);
	}
	ifile.close();
	ordina(v);
}
