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
//	// �޲ι��죺
//	// _str: �����ֵΪnullptr������������
//	// char*ָ����cout<<_strʱ����������ã���ȡָ����ָ����ַ������ݣ���ָ������û������쳣
//	// char* ����ָ���������������ʱ�򣬲�ͬ���������͵�ָ�룬������������͵�ָ�룬ֱ�����ָ���ŵĵ�ַ
//	// ��char*ָ�������Ϊ������֮�������
//
//	// STL String �޲ι���
//	// 1. ���һ���մ�"",����һ���ַ�'\0'
//	// 2. ������һ���ֽڵĿռ����ڴ��'\0'
//	// Ҫʹ��new char[]����ռ䣬Ϊ�˺����������ͷſռ�Ĳ�����Ӧnew[]Ҫ��Ӧdelete[]
//
//
//
//
//
//	// s << cout << s2   --->s.opreator<<(&s,cout)
//	// s << cout   --->cout << s2
//	// ���operator<<����Ϊ��Ա����  1. ����λ���ϲ����ϳ��õĵ����߼� 2. ���ܹ��������
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
//	// TODO: �ڴ˴����� return ���
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
	//cout << ite[16] << endl; ������ʧЧ

	system("pause");
	return 0;
}