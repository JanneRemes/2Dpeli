#include "SaveAndLoad.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
string fileName = "saveFile";

SaveGame SaveAndLoad::loadFromFile(int fileIndex)
{
	SaveGame *d = new SaveGame();
		string file = fileName;
	ostringstream oss;
	oss<<fileIndex;
	file += oss.str();
	file += ".dat";
	cout<<file<<endl;
	ifstream myFile(file,ios::binary| ios::in);
	if(myFile)
	{
		myFile.read((char*)d,sizeof(SaveGame));

	}
	else
	{
		cout<<"Error loading from file"<<endl;
	}
	myFile.close();
	return *d;
}
void SaveAndLoad::saveToFile(int fileIndex,SaveGame *d)
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
		writeFile.write((char*)d,sizeof(SaveGame));
	}
	writeFile.close();
	
}