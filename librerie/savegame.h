#ifndef __SAVEGAME_H
#define __SAVEGAME_H
#include <vector>
#include <fstream>

using namespace std;

class Savegame
{
	private:
	string user;
	int score;
	
	public:
	Savegame();
	Savegame(string,int);
	string getUser() const;
	void setUser(string);
	int getScore() const;
	void setScore(int);
	void save() const;
	void load(vector<string>&) const;
	void ordina(vector<string>&) const;
	
};

#endif
