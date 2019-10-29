#include <iostream>
#include <cstdio>
using namespace std;

/*ֻ���ڶ��ϴ����������*/
//1.����˽�л�
//2.�ṩһ�����е�static�ӿڴ�������Ķ���
//3.������
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() 
	{
		cout << "HeapOnly()" << endl;
	}
	// C++98
	// 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
	// 2.������˽��	
	//������ ֻ����,��ʵ��
	HeapOnly(const HeapOnly& h) = delete;
	//C++11 3.������ ɾ������������
	HeapOnly(const HeapOnly& h) = delete;
};

//int main()
//{
//	//A a;
//	HeapOnly* pa = HeapOnly::CreateObject();
//	return 0;
//}

/*ֻ����ջ�ϴ����������*/
//1.���캯��˽�л�
//2.�ṩһ�����е�static�ӿڴ�������
class StackOnly
{
public:
	static StackOnly getStackOnly()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};

class StackOnly2
{
private:
	void* operator new(size_t size);
	//C++11
	void* operator new(size_t size) = delete;
};

//int main()
//{
//	//StackOnly* ps = new StackOnly();  �Ѿ����������ɷ���
//	//StackOnly s;  
//	StackOnly s = StackOnly::getStackOnly();
//	StackOnly2 s;
//	//StackOnly2* ps = new StackOnly();  ����new��ʽ
//	return 0;
//}

/*����ģʽ*/
//һ����ֻ�ܴ���һ�����󣬼�����ģʽ����ģʽ���Ա�֤ϵͳ�и���ֻ��һ��ʵ�������ṩһ����������ȫ
//�ַ��ʵ㣬��ʵ�������г���ģ�鹲��������ĳ�������������У��÷�������������Ϣ�����һ���ļ�
//�У���Щ����������һ����������ͳһ��ȡ��Ȼ���������е�����������ͨ��������������ȡ��Щ����
//��Ϣ�����ַ�ʽ�����ڸ��ӻ����µ����ù���

/*����ģʽ*/
//����˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������

// �ŵ㣺��
// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����

//1.���캯��˽�л�
//2.�ṩһ�����е�static�ӿڷ��ض���
//3.����һ��static�����Ա
//4.������

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	// ���캯��˽��
//	Singleton()
//	{
//		cout << "Singleton()" << endl;
//	};
//	// C++98 ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��

//int main()
//{
//	Singleton* p1 = Singleton::GetInstance(); 
//	//Singleton copy(*p2);   ������
//	//Singleton s;   ������
//	return 0;
//}

/*����ģʽ*/
//�������������ʮ�ֺ�ʱ����ռ�úܶ���Դ��������ز������ ��ʼ���������Ӱ�����ȡ�ļ�����
//�ȣ����п��ܸö����������ʱ�����õ�����ôҲҪ�ڳ���һ��ʼ�ͽ��г�ʼ�����ͻᵼ�³�������ʱ
//�ǳ��Ļ����� �����������ʹ������ģʽ���ӳټ��أ����á�
//�ڶ����һ��ʹ��ʱ�Ŵ���

// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����

//1.���캯��˽�л�
//2.�ṩһ�����е�static�ӿڷ��ض���
//3.����һ��staticָ��
//4.�̰߳�ȫ��˫���
//5.������
#include <mutex>
#include <thread>
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) 
		{
			//˫���
			//1.�ⲿ��飺���Ч��
			//2.�Ȳ���飺��֤�̰߳�ȫ
			m_mtx.lock();
			if (nullptr == m_pInstance) 
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������
	//��һ����ʵ����������ֹ����������deleteʱ��������������ѭ��
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;   //delete������+�ͷ�
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton()
	{
		cout << "Singleton()" << endl;
	};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;
void func(int n) 
{
	cout << Singleton::GetInstance() << endl;
}
// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
int main()
{
	//���߳� ����
	thread t1(func, 10);
	thread t2(func, 10);

	//����ģʽ
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}

/*�ڴ�й©*/
//�ڴ�й©ָ��Ϊ����������ɳ���δ���ͷ��Ѿ�����ʹ�õ��ڴ��������ڴ�й©������ָ�ڴ���������
//����ʧ������Ӧ�ó������ĳ���ڴ����Ϊ��ƴ���ʧȥ�˶Ըö��ڴ�Ŀ��ƣ����������ڴ���˷�

void MemoryLeaks()
{
	// 1.�ڴ������������ͷ�
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.�쳣��ȫ����
	int* p3 = new int[10];
	//Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
	delete[] p3;
}
//���ڴ�й©(Heap leak)
//���ڴ�ָ���ǳ���ִ����������Ҫ����ͨ��malloc / calloc / realloc / new�ȴӶ��з����һ���ڴ棬
//��������ͨ��������Ӧ�� free����delete ɾ��������������ƴ������ⲿ���ڴ�û�б��ͷţ���
//ô�Ժ��ⲿ�ֿռ佫�޷��ٱ�ʹ�ã��ͻ����Heap Leak

//ϵͳ��Դй©
//ָ����ʹ��ϵͳ�������Դ���ȷ��׽��֡��ļ����������ܵ���û��ʹ�ö�Ӧ�ĺ����ͷŵ�������ϵͳ
//��Դ���˷ѣ����ؿɵ���ϵͳЧ�ܼ��٣�ϵͳִ�в��ȶ�