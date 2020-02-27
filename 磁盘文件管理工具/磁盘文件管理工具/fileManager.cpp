//目录--》扫描目录--》重复文件的结果--》管理重复文件
//findfirst  findnext:通过查找标志（搜索句柄）匹配，返回符合的第一个文件的结构体
#include "fileManager.h"
#include "fileutil.h"

void FileManager::scannerDir(const std::string& path)
{
	//清理容器
	_files.clear();
	searchDir(path, _files);
	std::cout << "all file" << std::endl;
	showAllFile();
	getMd5toFiles();
	showCopyList();
	getCopyList();
	std::cout << "copy list" << std::endl;
	showCopyList();
	showAllFile();
}

void FileManager::getMd5toFiles()
{
	_md5toFiles.clear();
	for (const auto& f : _files)
	{
		//计算新文件之间重置
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

//只保留重复文件的结果
void FileManager::getCopyList()
{
	_filestoMd5.clear();
	//不能用范围for：涉及删除操作，迭代器会失效
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//查找每一个md5对应的所有文件结果
		if (_md5toFiles.count(it->first) > 1)
		{
			//equal_range 返回值：pair<beginIt, endIt> : 左闭右开--》迭代器遍历时连续
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.second;
			while (begin != pairIt.second)
			{
				//只存放重复文件的映射关系
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//下一个不同的md5的起始位置
			it = pairIt.second;
		}
		else
		{
			//erase 返回值：被删除元素的下一个位置
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}

//所有的删除,保证一个文件不存在副本,保留指定文件
void FileManager::deleteByName(const std::string& name)
{
	if (_filestoMd5.count(name) == 0)
	{
		std::cout << name << "not exist!" << std::endl;
		return;
	}
	std::string curMD5 = _filestoMd5[name];
	std::cout << name << "--->" << _md5toFiles.count(curMD5) << std::endl;
	auto  pairIt = _md5toFiles.equal_range(curMD5);
	auto curIt = pairIt.first;
	int count = 0;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_files.erase(curIt->second);
			_filestoMd5.erase(curIt->second);
			deleteFile(curIt->second.c_str);
			++count;
		}
		++curIt;
	}

	//更新_md5toFiles
	curIt = pairIt.first;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			//key--->md5
			_md5toFiles.erase(curIt);
			pairIt = _md5toFiles.equal_range(curMD5);
			curIt = pairIt.first;
		}
		++curIt;
	}
	std::cout << "delete files ：" << count << std::endl;
}

void FileManager::deleteByMD5(const std::string& md5)
{
	//md5 ---》files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	//删除时需要保留一份，保留第一个文件
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "--->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		_files.erase(curIt->second);
		_filestoMd5.erase(curIt->second);
		//文件从磁盘删除
		deleteFile(curIt->second.c_str);
		++count;
		++curIt;
	}
	//更新 md5--> files
	curIt = pairIt.first;
	++curIt;
	//erase(first, last) -->删除区间值 [first, last)
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << "delete files number: " << count << std::endl;
}

void FileManager::deleteByMD5V2(const std::string& md5)
{
	//md5 ---》files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	auto it = _md5toFiles.find(md5);
	deleteByName(it->second);
}

//每个重复的文件只保留一个
void FileManager::deleteAllCopy()
{
	std::unordered_set<std::string> md5Set;
	for (const auto& p : _md5toFiles)
	{
		md5Set.insert(p.first);
	}
	for (const auto& md5 : md5Set)
	{
		deleteByMD5(md5);
	}
}

//模糊删除：删除所有模糊匹配"matchName"所有文件的副本
void FileManager::deleteByMatchName(const std::string& matchName)
{
	std::unordered_set<std::string> allFiles;
	//遍历所有文件
	for (const auto& f : _files)
	{
		if (f.find(matchName) != std::string::npos)
			allFiles.insert(f);
	}
	for (const auto& f : allFiles)
	{
		if (_filestoMd5.count(f) != 0)
			deleteByName(f);
	}
}

void FileManager::showCopyList()
{
	int count = 0;
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	while (it != _md5toFiles.end())
	{
		//MD5值相同的显示在一起
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5: " << it->first << std::endl;
		while (curIt != pairIt.second)
		{
			std::cout << "\t第" << idx << "个文件：";
			std::cout << curIt->second << std::endl;
			count++;
			++idx;
			++curIt;
		}
		it = pairIt.second;
	}
	std::cout << "文件总数：" << total << "\t" << count << std::endl;
}

void FileManager::showAllFile()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count: " << _files.size() << std::endl;
}

