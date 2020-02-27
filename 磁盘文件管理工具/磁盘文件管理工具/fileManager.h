#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "MD5.h"
class FileManager
{
public:
	void scannerDir(const std::string& path);
	void getMd5toFiles();
	void getCopyList();
	//所有的删除
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteByMD5V2(const std::string& md5);
	void deleteAllCopy();
	//模糊删除：删除所有模糊匹配"matchName"所有文件的副本
	void deleteByMatchName(const std::string& matchName);

	void showCopyList();
	void showAllFile();
	void showMD5Map();
private:
	//vector list map set
	std::unordered_set<std::string> _files;
	//md5-->file
	std::unordered_multimap<std::string, std::string> _md5toFiles;
	//file-->md5
	std::unordered_map<std::string, std::string> _filestoMd5;
	MD5 _md5;
};