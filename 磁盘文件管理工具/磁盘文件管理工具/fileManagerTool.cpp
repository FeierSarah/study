#include "fileManagerTool.h"

void FileManagerTool::scanner()
{
	cout << "������Ҫɨ����ļ��У�" << endl;
	std::string path;
	getline(cin, path);
	_fm.scannerDir(path);
}

void FileManagerTool::deletebyMd5()
{
	cout << "������Ҫɾ���ļ���MD5ֵ��" << endl;
	std::string md5;
	cin >> md5;
	_fm.deleteByMD5V2(md5);
}

void FileManagerTool::deletebyName()
{
	cout << "������Ҫɾ�����ļ�����" << endl;
	std::string filename;
	getline(cin, filename);
	_fm.deleteByName(filename);
}

void FileManagerTool::deleteAllCopy()
{
	_fm.deleteAllCopy();
}

void FileManagerTool::deleteFuzzyMatchCopy()
{
	cout << "������ƥ���ļ�����" << endl;
	std::string match;
	getline(cin, match);
	_fm.deleteByMatchName(match);
}

void FileManagerTool::showCopy()
{
	_fm.showCopyList();
}

void FileManagerTool::showAll()
{
	_fm.showAllFile;
}