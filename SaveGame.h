#pragma once
class SaveGame
{
public:
	SaveGame(void);
	~SaveGame(void){};
	 void setWeapons(int w[]);
	 void setRounds(int n){rounds = n;};
	 void setCash(int n) {cash = n;};
	 void setFileIndex(int n){fileIndex = n;};
	 void print();
private:
	 int weapons[5];
	 int rounds;
	int cash;
	 int fileIndex;
};

