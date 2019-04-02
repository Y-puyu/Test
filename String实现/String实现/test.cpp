//#include <iostream>
//using namespace std;
//
//class String {
//public:
//	String()
//		:_str(new char[1])
//	{
//		_str[0] = '\0';
//	}
//	~String() {
//		delete[] _str;
//		_str = nullptr;
//	}
//	// 无参构造：
//	// _str: 如果赋值为nullptr，输出会出问题
//	// char*指针在cout<<_str时候会做解引用，获取指针所指向的字符串内容，空指针解引用会引发异常
//	// char* 类型指针在用输出函数的时候，不同于其他类型的指针，如果是其他类型的指针，直接输出指针存放的地址
//	// 而char*指针输出的为解引用之后的内容
//
//	// STL String 无参构造
//	// 1. 存放一个空串"",包含一个字符'\0'
//	// 2. 申请了一个字节的空间用于存放'\0'
//	// 要使用new char[]申请空间，为了和析构函数释放空间的操作对应new[]要对应delete[]
//
//
//
//
//
//	// s << cout << s2   --->s.opreator<<(&s,cout)
//	// s << cout   --->cout << s2
//	// 如果operator<<定义为成员函数  1. 操作位置上不符合常用的调用逻辑 2. 不能够连续输出
//
//	friend ostream& operator<<(ostream& _cout, String s);
//	char* c_str{
//		return _str;
//	}
//
//private:
//	char* _str;
//};
//
//int main() {
//	String s;
//	cout << s << endl;
//	cout << (void*)s.c_str() << endl;
//
//	String s2;
//	cout << (void*)s2.c_str() << endl;
//	system("pause");
//	return 0;
//}
//
//ostream & operator<<(ostream & _cout, String s)
//{
//	// TODO: 在此处插入 return 语句
//}




#define  _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <string>	
using namespace std;

int main() {

	string str("abcdefg");
	string::iterator ite;

	ite = str.begin();
	for (size_t i = 0; i < str.size(); i++) {
		cout << *ite;
		ite++;
	}
	ite = str.begin();
	cout << endl;
	for (size_t i = 0; i < str.size(); i++) {
		cout << ite[i];
	}
	cout << endl;
	ite = str.begin();
	for (; ite != str.end(); ite++) {
		cout << *ite;
	}

	cout << endl;

	str.append(10, 'a');
	//cout << ite[16] << endl; 迭代器失效

	system("pause");
	return 0;
}