#include <iostream>
#include <stdio.h>
using namespace std;



//����ģʽ
//�ŵ㣺��
//ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
//      �����Ƚ�����������֮ǰ����Ҫ���г�ʼ�������໥�����Ķ�����������޷��������ʼ��˳�򣬶���ģʽ�����á�
//���ó��������߳�(��ȥ�޸ģ����ж����������̰߳�ȫ���⣩���߲���

//�Ĵ�ʵ��Ҫ�㣺
//1. ���캯��˽��
//2. ����һ��������̬��Ա����̬��Ա�ڳ�������֮ǰ��ɳ�ʼ��
//3. �ṩһ����̬������ȡ������̬��Ա
//4. ������

//class singleton
//{
//public:
//	// �ڴ˷������û���ָ�룬��֤ȫ��Ψһ����������������
//	// ���ã�����Ϊ��̬��������ͨ���������е��ã��������ڻ�û�ж�����Ҫ���øýӿ��õ�ͬһ�����󣬼������޷�ͨ�� ����. ����ʽ���е���
//	// ֻ��ͨ���ýӿڽ��е��ã����ش˾�̬��Ա����֤ȫ��Ψһ
//	// �����޷�������ֱ�Ӵ������󣬵�ȻҲ���ܹ�����new�ؼ��ִ�������
//	static singleton* getinstance()
//	{
//		return &m_instance;
//	}
//
//	//singleton getinstance()        
//	//{
//	//	return m_instance;				// �ڴ˷��ز�����Ҫ���޷����س�Ա������ᷢ���������죬��Ϊ��������
//	//}
//
//private:
//	// 1. ���캯��˽�� 2. ��������˽�У����Ǹ�ֵ�����û�б�Ҫ�����������ʵ��Ϊ�������������õı��ϰ����Ӧ�������
//	// 1. ���캯��˽��
//	singleton() {};
//
//	// 2. c++98 ������ ���ã�������Ҫʵ�֣�ֻ������ʵ��
//	singleton(singleton const&);
//	singleton& operator=(singleton const&);
//
//	// ����� c++11ɾ������
//	singleton(singleton const&) = delete;
//	singleton& operator=(singleton const&) = delete;
//
//	static singleton m_instance;       
//};
//
//singleton singleton::m_instance;  // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��



//// ��̬��Ա��ִ�к���֮ǰ���Ѿ����ó�ʼ������
//// �ڴ���Ҫ����һ����̬��Ա����̬��Ա������������������������������һ����Ա
//class Singleton {
//private:
//	Singleton(){}
//	Singleton _sin;   // ����ڴ˶�����ͨ��Ա��Ϊ�Ƿ��������������ʱ�����䱾���޷��������Ĵ�С���������ݹ�ļ���
//};
//
//class Singleton {
//private:
//	Singleton() {}
//	static Singleton _sin;  // �����䶨��Ϊ��̬��Ա����̬��Ա�����ڶ����У���������ݶΣ���Ӱ�����Ĵ�С                
//};
//
//Singleton Sin;             // ��̬��Ա������������г�ʼ����������������ڶ��徲̬��Ա�������ⶨ��һ��ȫ�ֵĳ�Ա
//						   // ��ʱ���캯���Ѿ��������ˣ��޷����г�ʼ�����������������ڲ����ܷ����޶��������ơ�
//void Singleton::fun() {    // ���庯�����������⡢�����ж�����ɡ�����������ĺ������Է������е�˽�г�Ա
//	_sin;				   // ��Ȼ˵��̬��Ա�������ⶨ��ģ������������������ĳ�Ա������ʹ�����������г�Ա������˽�г�Ա��
//}						   // ֻ���������ж��徲̬��Ա�ſ�����������г�ʼ��





// ����
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����

// ���ʵ��Ҫ��
// 1. ���캯��˽��
// 2. ������������
// 3. �ṩ��̬�̰߳�ȫ�Ľӿڣ�double-check�����Ч�ʣ�
// 4. ����һ����̬�������͵�ָ�룬��ʼ��Ϊnullptr
// 5.(��ѡ������һ���ڲ��࣬�����ͷŵ���ָ��

class Singleton
{
public:
	static Singleton* getInstance() {
		// ����
		// ��ߺ����̵߳��ýӿڵ�Ч��
		if (_sin == nullptr) {
			_mtx.lock();                 // ����������if�ڣ�û�����壬����Ҫ��������
			if (_sin == nullptr) {       // ��һ��Ϊ�գ��������󣬵ڶ��ηǿգ�ֱ�ӷ��أ���֤����
				_sin = new Singleton;
			}
			_mtx.unlock();
		}
		return _sin;
	}
	//~Singleton() {           // ~Singleton������delete _sin���ظ������������������ݹ�ЧӦ��
	//		delete _sin;       // ��Ϊ֮ǰ�������������ͷŵ���Դ���ǵ�ǰ�����͵ģ�����ȥ�ݹ���õ�ǰ����������������ٴθպô����˸�������
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
	// 1. ���캯��˽�л�   2. ��������˽�л�������ʵ�֣�   3. ��ֵ���������ν˽�л�����Ϊ�䲻�����µĶ���
	Singleton() {}
	Singleton(const Singleton& s) = delete;


	// static Singleton _sin;      // ����֮ǰ�϶���Ҫ���г�ʼ���������Ѿ�׼�����ˣ�Ϊ����ģʽ
	static Singleton* _sin;        // ����Ϊָ�룬�����Ϊͬһ���ͣ���Ϊ������ָ������
	static mutex _mtx;			   // ȫ��ֻ��һ����������ȫ���߳�
	static GC _gc;
};

Singleton* Singleton::_sin = nullptr;
mutex Singleton::_mtx;
Singleton::GC Singleton::_gc;     // ���Ǿ�̬��Ա������������Ҳ������������������ڣ��������������ͷſռ�


//// �μ�����ģʽ���룺
//#include <iostream>
//#include <mutex>
//#include <thread>      // C++11�е��߳̿�   <pthread> Linux���߳�...
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();          // ������if�ⲿ��ע���Ƿ�Ϊ��Ч��
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//
//	// �����ڲ��࣬ʵ��һ����Ƕ����������    
//	class CGarbo {
//	public:
//		~CGarbo() {
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//
//private:
//	// ���캯��˽��
//	Singleton() {};
//
//	// ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // ��������ָ��
//	static mutex m_mtx;            //������
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
//// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
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
//	// 1.�ڴ������������ͷ�
//	// �������������ڴ�û�н����ͷŵ����ڴ�й¶��ʵ���ϳ���������֮��
//	// ջ�Ὣ������Դȫ������ϵͳ
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 2.�쳣��ȫ����
//	int* p3 = new int[10];
//
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
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



#include <thread>        // C++11 �����߳̿⣬C++98û��   <pthread> Linux�е�ϵͳ�⣬���߾�����ʹ���߳�
#include <mutex>         // �����������е��̹߳���ͬһ������ȫ��ֻ��һ��������һ�������������߳�

int main() {
	//int i = 0;
	//thread t1(fun);      // mainΪ���߳� 
	//thread t2(fun);		 // ������t1��t2�����߳�

	//t1.join();			 // �൱�� ��� ����˼�������̵߳ȴ����������߳�ִ�����Լ�������һ�����
	//t2.join();

	thread t1(testsingleton);
	thread t2(testsingleton);

	Singleton* ps = Singleton::GetInstance();
	delete ps;
	ps = nullptr;

	system("pause");
	return 0;
}