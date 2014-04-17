#pragma once
#include "SaveGame.h"
class SaveAndLoad
{
public:
	static SaveGame loadFromFile(int fileIndex);
	static void saveToFile(int fileIndex,SaveGame *d);
};

