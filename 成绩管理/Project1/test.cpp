#include <iostream> 
#include <string> 
#include<fstream> 
#include<iomanip> 
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

int amount = 0;       //记录学生个数 
int const Q = 80;
float A[Q];
struct score {       //各门功课结构体
	float Chinese;
	float Englishscore;
	float Mathscore;
	float Physics;
	float Chemistry;
	float Biology;
	float Usuallyresults;
	/*float m_Totalscore;*/
	struct score *next;
};
struct student {     //学生结构体
	string number;
	string name;
	string sex;
	score Grade;
	float average;
	struct student *next;
};
student *head = (student *)malloc(sizeof(student));

void InputScore();//录入学生信息
void DisplayMainMenu();//显示菜单
void SearchByName();//查询
void SearchByNumber();//查询
void EditByName();//修改
void EditByNumber();//修改
void Delete();//删除学生信息
void save();//保存学生信息
void ShowStudentInfo();//显示学生信息
void FreadFile();//读取文件信息
void Insert();

void DisplayMainMenu() {   //显示菜单
	cout << "\t\t ---------------------------------------------- \n";
	cout << "\t\t｜**************学生成绩管理系统**************｜\n";
	cout << "\t\t｜*------------------------------------------*｜\n";
	cout << "\t\t｜*    a.录入学生信息　　　b.查询学生信息      *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　  　*｜\n";
	cout << "\t\t｜*　  c.修改学生信息　　　d.删除学生信息　    *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　  　*｜\n";
	cout << "\t\t｜*　  e.显示学生信息　　　f.保存学生信息　    *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　  　*｜\n";
	cout << "\t\t｜*　  g.读文件          　 i.插入学生信息　　　*｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　  　　*｜\n";
	cout << "\t\t｜*　  h.退出本软件　                      　*｜\n";
	cout << "\t\t｜*                                        *｜\n";
	cout << "\t\t｜********************************************｜\n";
	cout << "\t\t ----------------------------------------------\n";
}
void ShowStudentInfo() {   //显示学生信息	
	student *stu = head->next;
	cout << "   学号	   姓名   性别	 语文  	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
	int i = 1;
	while (stu != NULL && i <= amount) {
		cout << setw(8) << (*stu).number;
		cout << setw(8) << (*stu).name;
		cout << setw(5) << (*stu).sex;
		cout << setw(7) << (*stu).Grade.Chinese;
		cout << setw(7) << (*stu).Grade.Englishscore;
		cout << setw(8) << (*stu).Grade.Mathscore;
		cout << setw(8) << (*stu).Grade.Physics;
		cout << setw(7) << (*stu).Grade.Chemistry;
		cout << setw(7) << (*stu).Grade.Biology;
		cout << setw(10) << (*stu).Grade.Usuallyresults;
		cout << setw(13) << (*stu).average;
		cout << endl; i++;
		stu = stu->next;
	}
}
void save() {     //保存学生信息
	student *stu = head->next;//从头保存
	ofstream out("成绩管理.txt", ios::out);
	out << amount << "\t";
	int i = 1;
	while (stu != NULL && i <= amount) {
		out << stu->number << "\t" << stu->name << "\t" << stu->sex << "\t" << stu->Grade.m_Chinese << "\t"
			<< stu->Grade.Englishscore << "\t"
			<< stu->Grade.Mathscore << "\t"
			<< stu->Grade.Physics << "\t"
			<< stu->Grade.Chemistry << "\t"
			<< stu->Grade.Biology << "\t"
			<< stu->Grade.Usuallyresults << "\t";
		stu = stu->next;
		i++;
		cout << endl;
	}
	cout << "......成功将学生信息保存到〈成绩管理.txt〉中!!!!" << endl;
	out.close();
}
void InputScore() {   //录入学生数据
	head->next = NULL;//要录入学生信息，必须删除以前所有的信息
	amount = 0;
	char c;
	int j = 0;
	student *p = head;
	do {
		student *stu = new student;
		cout << "请输入学号：(9位)" << setw(4);
		cin >> (*stu).number;
		cout << "请输入姓名： " << setw(4);
		cin >> (*stu).name;
		cout << "请输入性别：" << setw(2);
		cin >> (*stu).sex;
		cout << "请输入语文成绩：" << setw(3);
		cin >> (*stu).Grade.Chinese;
		cout << "请输入英语成绩： " << setw(3);
		cin >> (*stu).Grade.Englishscore;
		cout << "请输入数学成绩： " << setw(3);
		cin >> (*stu).Grade.Mathscore;
		cout << "请输入物理成绩： " << setw(3);
		cin >> (*stu).Grade.Physics;
		cout << "请输入化学成绩： " << setw(3);
		cin >> (*stu).Grade.Chemistry;
		cout << "请输入生物成绩： " << setw(3);
		cin >> (*stu).Grade.Biology;
		cout << "请输入平时成绩： " << setw(3);
		cin >> (*stu).Grade.Usuallyresults;
		(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
			+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
		stu->next = p->next;
		p->next = stu;
		amount++;
		cout << "数据信息录入成功，想继续录入吗?(y/n)";
		cin >> c;
		p = p->next;
		while (c != 'y'&&c != 'n') {
			cout << "指令错误<请输入y/n!>!!!!!!" << endl;
			cout << "数据信息录入成功，想继续录入吗(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
	cout << "输入了" << amount << "个学生的信息." << endl;
}
void SearchByName() {  //按姓名查询
	string name;
	do {
		student *stu = head->next;
		bool flag = 0;
		cout << "请输入您要查询的学生姓名：" << endl;
		cin >> name;
		for (int i2 = 1; i2 <= amount; i2++) {
			if (name == stu->name) {
				flag = 1;
				cout << "您要查询的学生是：" << stu->name << endl;
				cout << "   学号	   姓名   性别	 语文   英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.Chinese;
				cout << setw(12) << (*stu).Grade.Englishscore;
				cout << setw(8) << (*stu).Grade.Mathscore;
				cout << setw(8) << (*stu).Grade.Physics;
				cout << setw(7) << (*stu).Grade.Chemistry;
				cout << setw(7) << (*stu).Grade.Biology;
				cout << setw(9) << (*stu).Grade.Usuallyresults;
				cout << endl;
				break;
			}
			else stu = stu->next;
		}//for
		if (flag == 1) {
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0) {
			cout << "对不起!您要查询的学生不存在!!!!!!!" << endl;
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void SearchByNumber() {    //按学号查询
	char c;
	string  no;
	do {
		student *stu = head->next;
		bool flag = 0;
		cout << "请输入您要查询的学生学号：" << endl;
		cin >> no;
		for (int i2 = 1; i2 <= amount; i2++) {
			if (no == stu->number) {
				flag = 1;
				cout << "您要查询的学生是：" << stu->name << endl;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.Chinese;
				cout << setw(12) << (*stu).Grade.Englishscore;
				cout << setw(8) << (*stu).Grade.Mathscore;
				cout << setw(8) << (*stu).Grade.Physics;
				cout << setw(7) << (*stu).Grade.Chemistry;
				cout << setw(7) << (*stu).Grade.Biology;
				cout << setw(9) << (*stu).Grade.Usuallyresults;
				cout << endl;
				break;
			}
			else stu = stu->next;
		}//for
		if (flag == 1) {
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0) {
			cout << "对不起!您要查询的学生不存在!!!!!!!" << endl;
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void EditByName() {  //修改学生数据,按姓名修改
	string name; char c;
	do {
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "请输入您要修改的学生的姓名：" << endl;
		cin >> name;
		do {
			if (name == (*stu).name) {
				flag = 1;
				cout << "请输入新的语文成绩：" << endl;
				cin >> Grade.Chinese;
				(*stu).Grade.Chinese = Grade.Chinese;
				cout << "请输入新的英语成绩：" << endl;
				cin >> Grade.Englishscore;
				(*stu).Grade.Englishscore = Grade.Englishscore;
				cout << "请输入新的数学成绩：" << endl;
				cin >> Grade.Mathscore;
				(*stu).Grade.Mathscore = Grade.Mathscore;
				cout << "请输入新的物理成绩：" << endl;
				cin >> Grade.Physics;
				(*stu).Grade.Physics = Grade.Physics;
				cout << "请输入新的化学成绩：" << endl;
				cin >> Grade.Chemistry;
				(*stu).Grade.Chemistry = Grade.Chemistry;
				cout << "请输入新的生物成绩：" << endl;
				cin >> Grade.Biology;
				(*stu).Grade.Biology = Grade.Biology;
				cout << "请输入新的平时成绩：" << endl;
				cin >> Grade.Usuallyresults;
				(*stu).Grade.Usuallyresults = Grade.Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
					+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.Chinese;
				cout << setw(12) << (*stu).Grade.Englishscore;
				cout << setw(8) << (*stu).Grade.Mathscore;
				cout << setw(8) << (*stu).Grade.Physics;
				cout << setw(7) << (*stu).Grade.Chemistry;
				cout << setw(7) << (*stu).Grade.Biology;
				cout << setw(9) << (*stu).Grade.Usuallyresults;
				cout << setw(9) << (*stu).average;
				cout << endl;
				cout << ".......数据修改成功!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "对不起，您要修改的学生不存在!请重新输入!!!!!!" << endl;
		cout << "想继续修改吗?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n') {
			cout << "指令错误<请输入y/n!>!!!!!!!" << endl;
			cout << "您想继续修改吗?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void EditByNumber() {
	string number; char c;
	do {
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "请输入您要修改的学生的学号：" << endl;
		cin >> number;
		do {
			if (number == (*stu).number) {
				flag = 1;
				cout << "请输入新的语文成绩：" << endl;
				cin >> Grade.Chinese;
				(*stu).Grade.Chinese = Grade.Chinese;
				cout << "请输入新的英语成绩：" << endl;
				cin >> Grade.Englishscore;
				(*stu).Grade.Englishscore = Grade.Englishscore;
				cout << "请输入新的数学成绩：" << endl;
				cin >> Grade.Mathscore;
				(*stu).Grade.Mathscore = Grade.Mathscore;
				cout << "请输入新的物理成绩：" << endl;
				cin >> Grade.Physics;
				(*stu).Grade.Physics = Grade.Physics;
				cout << "请输入新的化学成绩：" << endl;
				cin >> Grade.Chemistry;
				(*stu).Grade.Chemistry = Grade.Chemistry;
				cout << "请输入新的生物成绩：" << endl;
				cin >> Grade.Biology;
				(*stu).Grade.Biology = Grade.Biology;
				cout << "请输入新的平时成绩：" << endl;
				cin >> Grade.Usuallyresults;
				(*stu).Grade.Usuallyresults = Grade.Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
					+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.Chinese;
				cout << setw(12) << (*stu).Grade.Englishscore;
				cout << setw(8) << (*stu).Grade.Mathscore;
				cout << setw(8) << (*stu).Grade.Physics;
				cout << setw(7) << (*stu).Grade.Chemistry;
				cout << setw(7) << (*stu).Grade.Biology;
				cout << setw(9) << (*stu).Grade.Usuallyresults;
				cout << setw(9) << (*stu).average;
				cout << endl;
				cout << ".......数据修改成功!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "对不起，您要修改的学生不存在!请重新输入!!!!!!" << endl;
		cout << "想继续修改吗?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n') {
			cout << "指令错误<请输入y/n!>!!!!!!!" << endl;
			cout << "您想继续修改吗?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void Delete() {
	char c; string no;
	do {
		bool flag = 0;
		cout << "请输入您要删除的学生的学号：" << endl;
		cin >> no;
		student *q, *p;
		q = head;
		while (q->next != NULL && q->next->number != no)q = q->next;
		if (q->next != NULL) {
			flag = 1;
			p = q->next;
			q->next = q->next->next;
			amount--;
			free(p);
			cout << ".......删除成功!!!!!!" << endl;
		}
		if (flag == 0) {
			cout << "对不起!!!您要删除的学生不存在!!!!!" << endl;
			cout << "您想继续删除吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "指令错误!!!<请输入y/n!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void FreadFile() {
	student *p2, *p1;
	p1 = p2 = new student;
	ifstream fin("成绩管理.txt", ios::out);
	fin >> amount;
	cout << "共读出" << amount << "个学生信息: ";
	cout << endl;
	head = p2;//把头传给head
	if (!fin) {
		cout << "不能打开文件!!!!!!" << endl;
	}
	for (int k = 1; k <= amount; k++) {
		p1 = new  student;
		fin >> p1->number >> p1->name >> p1->sex >> p1->Grade.Chinese >> p1->Grade.Englishscore >> p1->Grade.Mathscore >>
			p1->Grade.Physics >> p1->Grade.Chemistry >> p1->Grade.Biology >> p1->Grade.Usuallyresults >> p1->average;
		p2->next = p1;
		p2 = p1;
	}
	cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
	student	*q = head->next;
	for (int l = 1; l <= amount; l++) {
		cout << setw(8) << q->number;
		cout << setw(8) << q->name;
		cout << setw(5) << q->sex;
		cout << setw(9) << q->Grade.Chinese;
		cout << setw(9) << q->Grade.Englishscore;
		cout << setw(8) << q->Grade.Mathscore;
		cout << setw(8) << q->Grade.Physics;
		cout << setw(7) << q->Grade.Chemistry;
		cout << setw(7) << q->Grade.Biology;
		cout << setw(9) << q->Grade.Usuallyresults;
		cout << setw(9) << q->average;
		cout << endl;
		q = q->next;
	}
	//显示读入数据
	fin.close();
	cout << "...... 数据已经成功读取完毕." << endl;
}
void Insert() {
	char c;
	int j = 0; 
	student *q = head->next;
	for (int i = 1; i <= amount - 1; i++)
		q = q->next;//找文件的尾
	do {
		student *stu = new student;
		cout << "请输入学号：(9位)" << setw(4);
		cin >> (*stu).number;
		cout << "请输入姓名： " << setw(4);
		cin >> (*stu).name;
		cout << "请输入性别：" << setw(2);
		cin >> (*stu).sex;
		cout << "请输入语文成绩：" << setw(3);
		cin >> (*stu).Grade.Chinese;
		cout << "请输入英语成绩： " << setw(3);
		cin >> (*stu).Grade.Englishscore;
		cout << "请输入数学成绩： " << setw(3);
		cin >> (*stu).Grade.Mathscore;
		cout << "请输入物理成绩： " << setw(3);
		cin >> (*stu).Grade.Physics;
		cout << "请输入化学成绩： " << setw(3);
		cin >> (*stu).Grade.Chemistry;
		cout << "请输入生物成绩： " << setw(3);
		cin >> (*stu).Grade.Biology;
		cout << "请输入平时成绩： " << setw(3);
		cin >> (*stu).Grade.Usuallyresults;  //算分数
		(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
			+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
		amount++;
		cout << "数据信息插入成功，想继续插入吗?(y/n)";
		cin >> c;
		q = q->next;
		while (c != 'y'&&c != 'n') {
			cout << "指令错误<请输入y/n!>!!!!!!" << endl;
			cout << "数据信息插入成功，想继续插入吗(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
}


void main() {
	char x;
	bool flag2 = 0;
	DisplayMainMenu();
	do {
		do {
			cin >> x;
			if ((x >= 'a'&&x <= 'z'))flag2 = 1;
			else {
				cout << "指令错误!!!!!!!!!!" << endl;
				cout << " 请选择相应的数字进行操作: " << endl;
			}
		} while (flag2 == 0);
		switch (x) {
		case 'a':
			cout << "******************************现在进行学生信息录入******************************\n";
			InputScore();
			cout << "输入的学生信息为：" << endl;
			ShowStudentInfo();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'b': {
			char z;
			cout << "******************************现在进行学生信息查询******************************\n";
			cout << "请选择查询方式：" << endl;
			cout << "(0)--按姓名查询；   (1)--按学号查询；" << endl;
			cin >> z;
			while (z != '0'&&z != '1') {
				cout << "指令错误(请选择(0)或者(1))!!!!!!!" << endl;
				cout << "请选择查询方式：(0)--按姓名查询；   (1)--按学号查询；";
				cin >> z;
			}
			switch (z) {
			case '0':SearchByName(); break;//按姓名查询
			case '1':SearchByNumber(); break;//按学号查询
			}
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'c': {
			char p;
			cout << "******************************现在进行学生信息修改******************************\n";
			cout << "请选择修改方式：(0)--按姓名修改；     (1)--按学号修改；" << endl;
			cin >> p;
			while (p != '0'&&p != '1') {
				cout << "指令错误(请选择(0)或者(1))!!!!!!!" << endl;
				cout << "请选择修改方式：(0)--按姓名修改；     (1)--按学号修改；" << endl;
				cin >> p;
			}
			switch (p) {
			case  '0': EditByName(); break;//按姓名修改
			case  '1': EditByNumber(); break;//按学号修改 
			}
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'd':
			cout << "******************************现在进行学生信息删除******************************\n";
			Delete();//删除
			ShowStudentInfo();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'e':
			cout << "******************************现在进行显示学生信息******************************\n";
			ShowStudentInfo(); //显示数据 	    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'f':
			cout << "******************************现在进行保存学生信息******************************\n";
			save();//保存学生信息		    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'g':
			cout << "******************************现在进行读取学生信息******************************\n";
			FreadFile();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'h':
			cout << "********************************************************************************\n";
			cout << " 您已退出学生成绩管理系统, 谢谢您的使用! \n";
			cout << "********************************************************************************\n";
			cout << endl;
			exit(0);
			break;
		case 'i':
			cout << "********************************************************************************\n";
			cout << "*****************************现在进行插入学生信息*********************************\n";
			Insert();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
	} while (flag2 == 1);
}