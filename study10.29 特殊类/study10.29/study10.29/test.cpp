#include <iostream>
#include <cstdio>
using namespace std;

/*只能在堆上创建对象的类*/
//1.构造私有化
//2.提供一个公有的static接口创建对象的对象
//3.防拷贝
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
	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
	// 2.声明成私有	
	//防拷贝 只声明,不实现
	HeapOnly(const HeapOnly& h) = delete;
	//C++11 3.防拷贝 删除函数的声明
	HeapOnly(const HeapOnly& h) = delete;
};

//int main()
//{
//	//A a;
//	HeapOnly* pa = HeapOnly::CreateObject();
//	return 0;
//}

/*只能在栈上创建对象的类*/
//1.构造函数私有化
//2.提供一个公有的static接口创建对象
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
//	//StackOnly* ps = new StackOnly();  已经声明，不可访问
//	//StackOnly s;  
//	StackOnly s = StackOnly::getStackOnly();
//	StackOnly2 s;
//	//StackOnly2* ps = new StackOnly();  禁用new方式
//	return 0;
//}

/*单例模式*/
//一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全
//局访问点，该实例被所有程序模块共享。比如在某个服务器程序中，该服务器的配置信息存放在一个文件
//中，这些配置数据由一个单例对象统一读取，然后服务进程中的其他对象再通过这个单例对象获取这些配置
//信息，这种方式简化了在复杂环境下的配置管理。

/*饿汉模式*/
//就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象

// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。

//1.构造函数私有化
//2.提供一个公有的static接口返回对象
//3.定义一个static自身成员
//4.防拷贝

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	// 构造函数私有
//	Singleton()
//	{
//		cout << "Singleton()" << endl;
//	};
//	// C++98 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance; // 在程序入口之前就完成单例对象的初始化

//int main()
//{
//	Singleton* p1 = Singleton::GetInstance(); 
//	//Singleton copy(*p2);   防拷贝
//	//Singleton s;   防构造
//	return 0;
//}

/*懒汉模式*/
//如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等
//等，而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，就会导致程序启动时
//非常的缓慢。 所以这种情况使用懒汉模式（延迟加载）更好。
//在对象第一次使用时才创建

// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂

//1.构造函数私有化
//2.提供一个公有的static接口返回对象
//3.定义一个static指针
//4.线程安全：双检查
//5.防拷贝
#include <mutex>
#include <thread>
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) 
		{
			//双检查
			//1.外部检查：提高效率
			//2.內部检查：保证线程安全
			m_mtx.lock();
			if (nullptr == m_pInstance) 
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类
	//用一个类实现析构，防止析构函数走delete时又析构，陷入死循环
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;   //delete：析构+释放
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton()
	{
		cout << "Singleton()" << endl;
	};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;
void func(int n) 
{
	cout << Singleton::GetInstance() << endl;
}
// 多线程环境下演示上面GetInstance()加锁和不加锁的区别
int main()
{
	//多线程 并行
	thread t1(func, 10);
	thread t2(func, 10);

	//串行模式
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}

/*内存泄漏*/
//内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上
//的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费

void MemoryLeaks()
{
	// 1.内存申请了忘记释放
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.异常安全问题
	int* p3 = new int[10];
	//Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
	delete[] p3;
}
//堆内存泄漏(Heap leak)
//堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，
//用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那
//么以后这部分空间将无法再被使用，就会产生Heap Leak

//系统资源泄漏
//指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统
//资源的浪费，严重可导致系统效能减少，系统执行不稳定