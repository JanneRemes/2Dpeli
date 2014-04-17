#include "SaveGame.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
//int SaveGame::cash;
//int SaveGame::fileIndex;
//int SaveGame::rounds;
//string fileName = "saveFile";
//int SaveGame::weapons[] = {-1,-1,-1,-1,-1};
SaveGame::SaveGame()
{
	for (int i = 0; i < 5; ++i)
		{
			weapons[i] = -1; 
		}
	rounds = 0;
cash = -1;
fileIndex = 1;
}
//	static int weapons[5];
//	static int rounds;
//static int cash;
//static int fileIndex;
/*void SaveGame::loadFromFile(int fileind)
{
	string file = fileName;
	ostringstream oss;
	oss<<fileind;
	file += oss.str();
	file += ".dat";
	cout<<file<<endl;
	ifstream myFile(file,ios::binary| ios::in);
	if(myFile)
	{
		myFile.read((char*)weapons,sizeof(weapons));
		myFile.read((char*)rounds,sizeof(int));
		myFile.read((char*)cash,sizeof(int));
		myFile.read((char*)fileIndex,sizeof(int));

	}
	else
	{
		cout<<"Error loading from file"<<endl;
	}
		for(int i = 0; i < 5; i++)
		cout<<weapons[i]<<endl;
		cout<<rounds<<endl;
		cout<<cash<<endl;
		cout<<fileIndex<<endl;
}*/
/*void SaveGame::saveToFile()
{
		string file = fileName;
	ostringstream oss;
	oss<<fileIndex;
	file += oss.str();
	file += ".dat";
	cout<<file<<endl;
	ofstream writeFile(file,ios::binary| ios::out);
	if(writeFile)
	{
		writeFile.write((char*)weapons,sizeof(weapons));
		writeFile.write((char*)rounds,sizeof(int));
		writeFile.write((char*)cash,sizeof(int));
		writeFile.write((char*)fileIndex,sizeof(int));
	}
		else
	{
		cout<<"Error saving file"<<endl;
	}
	for(int i = 0; i < 5; i++)
		cout<<weapons[i]<<endl;
		cout<<rounds<<endl;
		cout<<cash<<endl;
		cout<<fileIndex<<endl;
}*/
 void SaveGame::setWeapons(int w[])
{
	for(int i = 0; i < 5;i++)
		weapons[i] = w[i];
}
 void SaveGame::print()
 {
	 for(int i = 0; i < 5; i++)
		cout<<weapons[i]<<endl;
		cout<<rounds<<endl;
		cout<<cash<<endl;
		cout<<fileIndex<<endl;
 }