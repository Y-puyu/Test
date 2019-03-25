#include <iostream>
#include <stdio.h>
using namespace std;



//饿汉模式
//优点：简单
//缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//      启动比较慢，在启动之前就需要进行初始化。有相互依赖的多个对象单例，无法控制其初始化顺序，饿汉模式不适用。
//适用场景：多线程(不去修改，仅有读操作，无线程安全问题）、高并发

//四大实现要点：
//1. 构造函数私有
//2. 定义一个单例静态成员，静态成员在程序运行之前完成初始化
//3. 提供一个静态方法获取单例静态成员
//4. 防拷贝

//class singleton
//{
//public:
//	// 在此返回引用或者指针，保证全局唯一，否则发生拷贝构造
//	// 调用：定义为静态，在类外通过类名进行调用，否则现在还没有对象，需要调用该接口拿到同一个对象，即现在无法通过 对象. 的形式进行调用
//	// 只能通过该接口进行调用，返回此静态成员，保证全局唯一
//	// 现在无法再类外直接创建对象，当然也不能够采用new关键字创建对象
//	static singleton* getinstance()
//	{
//		return &m_instance;
//	}
//
//	//singleton getinstance()        
//	//{
//	//	return m_instance;				// 在此返回不符合要求，无法返回成员本身，其会发生拷贝构造，不为单例本身
//	//}
//
//private:
//	// 1. 构造函数私有 2. 拷贝函数私有，但是赋值运算符没有必要将其封死，其实质为拷贝，但在良好的编程习惯下应将其封死
//	// 1. 构造函数私有
//	singleton() {};
//
//	// 2. c++98 防拷贝 不用，即不需要实现，只声明不实现
//	singleton(singleton const&);
//	singleton& operator=(singleton const&);
//
//	// 或采用 c++11删除函数
//	singleton(singleton const&) = delete;
//	singleton& operator=(singleton const&) = delete;
//
//	static singleton m_instance;       
//};
//
//singleton singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化



//// 静态成员在执行函数之前就已经做好初始化工作
//// 在此需要声明一个静态成员，静态成员还是它本身，等于它里面包含它本身的一个成员
//class Singleton {
//private:
//	Singleton(){}
//	Singleton _sin;   // 如果在此定义普通成员即为非法操作，定义该类时包含其本身，无法计算该类的大小，会引发递归的计算
//};
//
//class Singleton {
//private:
//	Singleton() {}
//	static Singleton _sin;  // 若将其定义为静态成员，静态成员不存在对象当中，其存在数据段，不影响该类的大小                
//};
//
//Singleton Sin;             // 静态成员必须在类外进行初始化，如果不在类体内定义静态成员，在类外定义一个全局的成员
//						   // 此时构造函数已经被封死了，无法进行初始化，而定义在类体内不会受访问限定符的限制。
//void Singleton::fun() {    // 定义函数可以在类外、类内中定义均可。类外所定义的函数可以访问类中的私有成员
//	_sin;				   // 虽然说静态成员是在类外定义的，但是首先它是这个类的成员，它会使用这个类的所有成员（包括私有成员）
//}						   // 只有在类体中定义静态成员才可以在类外进行初始化





// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂

// 五大实现要点
// 1. 构造函数私有
// 2. 封死拷贝构造
// 3. 提供静态线程安全的接口（double-check，提高效率）
// 4. 定义一个静态单例类型的指针，初始化为nullptr
// 5.(可选）定义一个内部类，辅助释放单例指针

class Singleton
{
public:
	static Singleton* getInstance() {
		// 做饭
		// 提高后续线程调用接口的效率
		if (_sin == nullptr) {
			_mtx.lock();                 // 加锁不能在if内，没有意义，还是要创建对象
			if (_sin == nullptr) {       // 第一次为空，创建对象，第二次非空，直接返回，保证单例
				_sin = new Singleton;
			}
			_mtx.unlock();
		}
		return _sin;
	}
	//~Singleton() {           // ~Singleton，会在delete _sin上重复调用析构函数产生递归效应。
	//		delete _sin;       // 因为之前调用析构函数释放的资源不是当前类类型的，不会去递归调用当前类的析构函数，而再次刚好触发了该条件。
	//	if (_sin) {
	//		_sin = nullptr;
	//	}
	//}
	class GC {
	public:
		~GC() {
			if (_sin) {
				delete _sin;
				_sin = nullptr;
			}
		}
	};
private:
	// 1. 构造函数私有化   2. 拷贝构造私有化（不必实现）   3. 赋值运算符无所谓私有化，因为其不创建新的对象
	Singleton() {}
	Singleton(const Singleton& s) = delete;


	// static Singleton _sin;      // 启动之前肯定需要进行初始化，东西已经准备好了，为饿汉模式
	static Singleton* _sin;        // 定义为指针，与对象不为同一类型，其为单独的指针类型
	static mutex _mtx;			   // 全局只有一把锁，限制全部线程
	static GC _gc;
};

Singleton* Singleton::_sin = nullptr;
mutex Singleton::_mtx;
Singleton::GC Singleton::_gc;     // 它是静态成员，其生命周期也是整个程序的生命周期，调用析构函数释放空间


//// 课件懒汉模式代码：
//#include <iostream>
//#include <mutex>
//#include <thread>      // C++11中的线程库   <pthread> Linux下线程...
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();          // 加锁在if外部，注意是否为有效锁
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//
//	// 建立内部类，实现一个内嵌垃圾回收类    
//	class CGarbo {
//	public:
//		~CGarbo() {
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//
//private:
//	// 构造函数私有
//	Singleton() {};
//
//	// 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx;            //互斥锁
//};
//
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//}
//
//// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//
//	t1.join();
//	t2.join();
//
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	system("pause");
//}
//
//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	// 理论上申请了内存没有进行释放导致内存泄露，实际上程序运行完之后，
//	// 栈会将所有资源全部还给系统
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 2.异常安全问题
//	int* p3 = new int[10];
//
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//
//	delete[] p3;
//}


//void fun() {
//	for (int i = 0; i < 10; i++) {
//		cout << i << endl;
//	}
//}

void testsingleton() {
	cout << Singleton::getInstance() << endl;
}



#include <thread>        // C++11 加入线程库，C++98没有   <pthread> Linux中的系统库，两者均可以使用线程
#include <mutex>         // 互斥锁，所有的线程共用同一把锁，全局只有一把锁，用一把锁限制所有线程

int main() {
	//int i = 0;
	//thread t1(fun);      // main为主线程 
	//thread t2(fun);		 // 创建了t1、t2两个线程

	//t1.join();			 // 相当于 会和 的意思，让主线程等待上面两个线程执行完自己的命令一起结束
	//t2.join();

	thread t1(testsingleton);
	thread t2(testsingleton);

	Singleton* ps = Singleton::GetInstance();
	delete ps;
	ps = nullptr;

	system("pause");
	return 0;
}