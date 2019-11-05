#include <iostream>
using namespace std;

//�ַ������
#include <algorithm>
class Solution {
public:
	string addStrings(string num1, string num2) {
			int LSize = num1.size();
		int RSize = num2.size();
		// �Գ��ַ�����Ϊ�ⲿѭ��
		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);
		}
		string strRet;
		strRet.reserve(LSize + 1);
		char cRet = 0;
		char cstep = 0;
		for (size_t i = 0; i < LSize; ++i)
		{
			cRet = num1[LSize - i - 1] - '0' + cstep;
			cstep = 0;
			if (i < RSize)
			{
				cRet += num2[RSize - i - 1] - '0';
			}
			if (cRet >= 10)
			{
				cRet -= 10;
				cstep = 1;
			}
			//strRet.insert(strRet.begin(), cRet + '0');
			//�˴�������β��ԭ��Ϊͷ��ʱ�临�Ӷ�Ϊ n��
			//��˳��õ��ַ����Ĵ��ҵ���ĺͣ�ֻ��β��O(1)������ѭ�������ü���
			strRet += cRet + '0';
		}
		if (cstep)
			strRet += '1';
		reverse(strRet.begin(), strRet.end());//�ַ�����ת
		return strRet;
	}
};

class String
{
public:
	String()
		:_str(new char[1])
	{
		*_str = '\0';
	}

	String(char* str)
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[]_str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
		}
		return *this;
	}

	String& operator=(String& str)//����д��
	{
		//String tmp(str._str);
		swap(_str, str._str);
		return *this;
	}

	const char* c_str() const
	{
		return _str;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}

private:
	char* _str;
};
void testString1()
{
	String s;
	String s2;
	cout << s2.c_str() << endl;
	cout << s2.c_str() << endl;
	char* str = new char[10];
}
int main()
{
	testString1();
	return 0;
}

