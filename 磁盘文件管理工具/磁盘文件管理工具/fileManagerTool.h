#pragma once
#include "fileManager.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class FileManagerTool
{
public:
	void scanner();
	void deletebyMd5();
	void deletebyName();
	void deleteAllCopy();
	void deleteFuzzyMatchCopy();
	void showCopy();
	void showAllFile();
private:
	FileManager _fm;
};