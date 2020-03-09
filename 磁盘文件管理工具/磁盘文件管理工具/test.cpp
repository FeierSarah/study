#include <iostream>
#include "MD5.h"
#include "fileutil.h"
#include "fileManager.h"
#include "fileManagerTool.h"

using std::cout;
using std::endl;

void testHex()
{
	MD5 md5;
	unit32 n = 0x23456789;//83674523
	cout << md5.changeHex(n) << endl;
}

void testStringMD5()
{
	MD5 md5;
	std::string str = "123456789abcdefgh";
	cout << md5.getStringMD5(str) << endl;
	std::string str2 = "123456789abcdefgi";
	cout << md5.getStringMD5(str2) << endl;
}

void testFileMD5()
{
	MD5 md5;
	const char* filepath1 = "md5test1.txt";
	const char* filepath2 = "md5test2.txt";
	cout << md5.getFileMD5(filepath1) << endl;
	//计算下一个文件需要重置
	md5.reset();
	cout << md5.getFileMD5(filepath2) << endl;
}

//void testSearch()
//{
//	std::string path;
//	cout << "please input search dir:" << endl;
//	getline(std::cin, path);
//	std::vector<std::string> subFiles;
//	searchDir(path, subFiles);
//	for (const auto& f : subFiles)
//	{
//		cout << f << endl;
//	}
//}

void testFM()
{
	FileManager fm;
	std::string path = "C:\\Users\\dell\\Desktop\\欧阳慧\\bite\\VS\\study";
	fm.scannerDir(path);
}

void menu()
{
	cout << "****************************************************" << endl;
	cout << "1: scanner         2: show all        3: show copy  " << endl;
	cout << "4: delete name     5: delete md5      6: delete all " << endl;
	cout << "7: delete matched  0: exit" << endl;
	cout << "****************************************************" << endl;
}

void testFileManagerTool()
{
	FileManagerTool fmt;
	int input;
	do
	{
		menu();
		std::string garbage;
		cout << "请输入选项" << endl;
		cin >> input;
		getline(cin, garbage);
		switch (input)
		{
		case 1:
			fmt.scanner();
			break;
		case 2:
			fmt.showAll();
			break;
		case 3:
			fmt.showCopy();
			break;
		case 4:
			fmt.deletebyName();
			break;
		case 5:
			fmt.deletebyMd5();
			break;
		case 6:
			fmt.deleteAllCopy();
			break;
		case 7:
			fmt.deleteFuzzyMatchCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);


}

int main()
{
	//testHex();
	//testStringMD5();
	//testFileMD5();
	//testSearch();
	//testFM();
	testFileManagerTool();
	return 0;
}
