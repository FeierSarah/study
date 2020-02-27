//Ŀ¼--��ɨ��Ŀ¼--���ظ��ļ��Ľ��--�������ظ��ļ�
//findfirst  findnext:ͨ�����ұ�־�����������ƥ�䣬���ط��ϵĵ�һ���ļ��Ľṹ��
#include "fileManager.h"
#include "fileutil.h"

void FileManager::scannerDir(const std::string& path)
{
	//��������
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
		//�������ļ�֮������
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

//ֻ�����ظ��ļ��Ľ��
void FileManager::getCopyList()
{
	_filestoMd5.clear();
	//�����÷�Χfor���漰ɾ����������������ʧЧ
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//����ÿһ��md5��Ӧ�������ļ����
		if (_md5toFiles.count(it->first) > 1)
		{
			//equal_range ����ֵ��pair<beginIt, endIt> : ����ҿ�--������������ʱ����
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.second;
			while (begin != pairIt.second)
			{
				//ֻ����ظ��ļ���ӳ���ϵ
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//��һ����ͬ��md5����ʼλ��
			it = pairIt.second;
		}
		else
		{
			//erase ����ֵ����ɾ��Ԫ�ص���һ��λ��
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}

//���е�ɾ��,��֤һ���ļ������ڸ���,����ָ���ļ�
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

	//����_md5toFiles
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
	std::cout << "delete files ��" << count << std::endl;
}

void FileManager::deleteByMD5(const std::string& md5)
{
	//md5 ---��files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	//ɾ��ʱ��Ҫ����һ�ݣ�������һ���ļ�
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "--->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		_files.erase(curIt->second);
		_filestoMd5.erase(curIt->second);
		//�ļ��Ӵ���ɾ��
		deleteFile(curIt->second.c_str);
		++count;
		++curIt;
	}
	//���� md5--> files
	curIt = pairIt.first;
	++curIt;
	//erase(first, last) -->ɾ������ֵ [first, last)
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << "delete files number: " << count << std::endl;
}

void FileManager::deleteByMD5V2(const std::string& md5)
{
	//md5 ---��files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	auto it = _md5toFiles.find(md5);
	deleteByName(it->second);
}

//ÿ���ظ����ļ�ֻ����һ��
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

//ģ��ɾ����ɾ������ģ��ƥ��"matchName"�����ļ��ĸ���
void FileManager::deleteByMatchName(const std::string& matchName)
{
	std::unordered_set<std::string> allFiles;
	//���������ļ�
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
		//MD5ֵ��ͬ����ʾ��һ��
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5: " << it->first << std::endl;
		while (curIt != pairIt.second)
		{
			std::cout << "\t��" << idx << "���ļ���";
			std::cout << curIt->second << std::endl;
			count++;
			++idx;
			++curIt;
		}
		it = pairIt.second;
	}
	std::cout << "�ļ�������" << total << "\t" << count << std::endl;
}

void FileManager::showAllFile()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count: " << _files.size() << std::endl;
}

