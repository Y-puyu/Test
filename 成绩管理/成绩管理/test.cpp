#include <iostream> 
#include <string> 
#include<fstream> 
#include<iomanip> 
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

int amount = 0; //记录学生个数 
int const Q = 80;
float A[Q];
struct score//各门功课结构体
{
	float m_Chinese;
	float m_Englishscore;
	float m_Mathscore;
	float m_Physics;
	float m_Chemistry;
	float m_Biology;
	float m_Usuallyresults;
	/*float m_Totalscore;*/
	struct score *next;
};
struct student//学生结构体
{
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
//void Sort_DataStructrue();//按数据结构排序
//void Sort_Englishi();//按英语排序
//void Sort_Math();//按数学排序
//void Sort_PE();//按体育排序
//void Sort_Probability();//按概率排序
void Sort_Average();//按平均分排序
//void Statistics();//统计学生信息
void ShowStudentInfo();//显示学生信息
void FreadFile();//读取文件信息
void Insert();

void main()
{
	char x;
	bool flag2 = 0;
	DisplayMainMenu();
	do
	{
		do
		{
			cin >> x;
			if ((x >= 'a'&&x <= 'z'))flag2 = 1;
			else
			{
				cout << "指令错误!!!!!!!!!!" << endl;
				cout << " 请选择相应的数字进行操作: " << endl;
			}
		} while (flag2 == 0);
		switch (x)
		{
		case 'a':
			cout << "******************************现在进行学生信息录入******************************\n";
			InputScore();
			cout << "输入的学生信息为：" << endl;
			ShowStudentInfo();          
			cout << "********************************************************************************\n";
			DisplayMainMenu(); 
			break;
		case 'b':
		{
			char z;
			cout << "******************************现在进行学生信息查询******************************\n";
			cout << "请选择查询方式：" << endl;
			cout << "(0)--按姓名查询；   (1)--按学号查询；" << endl;
			cin >> z;
			while (z != '0'&&z != '1')
			{
				cout << "指令错误(请选择(0)或者(1))!!!!!!!" << endl;
				cout << "请选择查询方式：(0)--按姓名查询；   (1)--按学号查询；";
				cin >> z;
			}
			switch (z)
			{
			case '0':SearchByName(); break;//按姓名查询
			case '1':SearchByNumber(); break;//按学号查询
			}
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'c':
		{
			char p;
		    cout << "******************************现在进行学生信息修改******************************\n";
			cout << "请选择修改方式：(0)--按姓名修改；     (1)--按学号修改；" << endl;
			cin >> p;
			while (p != '0'&&p != '1')
				{
					cout << "指令错误(请选择(0)或者(1))!!!!!!!" << endl;
					cout << "请选择修改方式：(0)--按姓名修改；     (1)--按学号修改；" << endl;
					cin >> p;
				}
			switch (p)
			{
				case  '0': EditByName(); break;//按姓名修改
				case  '1': EditByNumber(); break;//按学号修改 
			}					 cout << "********************************************************************************\n";
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
			ShowStudentInfo(); //显示数据 	    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'f':
			cout << "******************************现在进行保存学生信息******************************\n";
			save();//保存学生信息		    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'g':
			cout << "******************************现在进行读取学生信息******************************\n";
			FreadFile();	   cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'h':
			cout << "******************************现在进行统计学生信息******************************\n";
			//Statistics();//统计学生信息	   		    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'i':
			cout << "******************************现在进行排序******************************\n";
			//cout << "请选择排序方式：" << endl;
			//cout << "1  按数据结构成绩排序 " << endl;
			//cout << "2  按英语成绩排序 " << endl;
			//cout << "3  按数学成绩排序 " << endl;
			//cout << "4  按体育成绩排序 " << endl;
			//cout << "5  按概率成绩排序 " << endl;
			cout << " 按总成绩排序 " << endl;
			Sort_Average();
			//cin >> a;
			//while (a<'1' || a>'6')
			//{
			//	//cout << "指令错误(请选择(1-6))!!!!!!!" << endl;
			//	//cout << "1  按数据结构成绩排序 " << endl;
			//	//cout << "2  按英语成绩排序 " << endl;
			//	//cout << "3  按数学成绩排序 " << endl;
			//	//cout << "4  按体育成绩排序 " << endl;
			//	//cout << "5  按概率成绩排序 " << endl;
			//	cout << "6  按平均分排序 " << endl;
			//	cin >> a;
			//}
			//switch (a)
			//{
			////case  '1': Sort_DataStructrue(); break;// 按数据结构成绩排序
			////case  '2': Sort_Englishi(); break;//按英语成绩排序 
			////case  '3': Sort_Math(); break;//按数学成绩排序
			////case  '4': Sort_PE(); break;//按体育成绩排序
			////case  '5': Sort_Probability(); break;//按概率成绩排序
			//case  '6': Sort_Average(); break;//按平均分排序

			//}    cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;	
		case 'j':
			cout << "********************************************************************************\n";
			cout << " 您已退出学生成绩管理系统, 谢谢您的使用! \n";    
			cout << "********************************************************************************\n";
			cout << endl;
			exit(0);
			break;
		case 'k':	      
			cout << "********************************************************************************\n";
			cout << "*****************************现在进行插入学生信息*********************************\n";
			Insert();    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
	} while (flag2 == 1);
}
void DisplayMainMenu()//显示菜单
{
	cout << "\t\t ---------------------------------------------- \n";
	cout << "\t\t｜****************学生成绩管理系统************｜\n";
	cout << "\t\t｜*------------------------------------------*｜\n";
	cout << "\t\t｜*  a.录入学生信息　　　b.查询学生信息      *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　　*｜\n";
	cout << "\t\t｜*　c.修改学生信息　　　d.删除学生信息　    *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　　*｜\n";
	cout << "\t\t｜*　e.显示学生信息　　　f.保存学生信息　    *｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　　*｜\n";
	cout << "\t\t｜*　g.读文件            h.统计学生信息　　　*｜\n";
	cout << "\t\t｜*　　　　　　　　　　　　　　　　　　　　　*｜\n";
	cout << "\t\t｜*　i.排序　　　　　　　k.插入学生信息　　　*｜\n";
	cout << "\t\t｜*                                          *｜\n";
	cout << "\t\t｜*  j.退出本软件　　　　　　　　　　　　　　*｜\n";
	cout << "\t\t｜********************************************｜\n";
	cout << "\t\t ----------------------------------------------\n";
}
void ShowStudentInfo()//显示学生信息	
{
	student *stu = head->next;
	cout << "   学号	   姓名   性别	 语文  	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
	int i = 1;
	while (stu != NULL && i <= amount) {
		cout << setw(8) << (*stu).number;
		cout << setw(8) << (*stu).name;
		cout << setw(5) << (*stu).sex;
		cout << setw(7) << (*stu).Grade.m_Chinese;
		cout << setw(7) << (*stu).Grade.m_Englishscore;
		cout << setw(8) << (*stu).Grade.m_Mathscore;
		cout << setw(8) << (*stu).Grade.m_Physics;
		cout << setw(7) << (*stu).Grade.m_Chemistry;
		cout << setw(7) << (*stu).Grade.m_Biology;
		cout << setw(10) << (*stu).Grade.m_Usuallyresults;
		cout << setw(13) << (*stu).average;
		cout << endl; i++;
		stu = stu->next;
	}
}
void save()//保存学生信息
{
	student *stu = head->next;//从头保存
	ofstream out("成绩管理.txt", ios::out);
	out << amount << "\t";
	int i = 1;
	while (stu != NULL && i <= amount)
	{
		out << stu->number << "\t" << stu->name << "\t" << stu->sex << "\t" << stu->Grade.m_Chinese << "\t"
			<< stu->Grade.m_Englishscore << "\t"
			<< stu->Grade.m_Mathscore << "\t"
			<< stu->Grade.m_Physics << "\t"
			<< stu->Grade.m_Chemistry << "\t"
			<< stu->Grade.m_Biology << "\t"
			<< stu->Grade.m_Usuallyresults << "\t";
			//<< stu->Grade.m_Totalscore << "\t";   //没有学生里面的成绩
		stu = stu->next; 
		i++;
		cout << endl;
	}
	cout << "......成功将学生信息保存到〈成绩管理.txt〉中!!!!" << endl;
	out.close();
}
void InputScore()//录入学生数据
{
	head->next = NULL;//要录入学生信息，必须删除以前所有的信息
	amount = 0;
	char c;
	int j = 0;
	student *p = head;
	do
	{
		student *stu = new student;
		cout << "请输入学号：(8位)" << setw(4);
		cin >> (*stu).number;
		cout << "请输入姓名： " << setw(4);
		cin >> (*stu).name;
		cout << "请输入性别：" << setw(2);
		cin >> (*stu).sex;
		cout << "请输入语文成绩：" << setw(3);
		cin >> (*stu).Grade.m_Chinese;
		cout << "请输入英语成绩： " << setw(3);
		cin >> (*stu).Grade.m_Englishscore;
		cout << "请输入数学成绩： " << setw(3);
		cin >> (*stu).Grade.m_Mathscore;
		cout << "请输入物理成绩： " << setw(3);
		cin >> (*stu).Grade.m_Physics;
		cout << "请输入化学成绩： " << setw(3);
		cin >> (*stu).Grade.m_Chemistry;
		cout << "请输入生物成绩： " << setw(3);
		cin >> (*stu).Grade.m_Biology;
		cout << "请输入平时成绩： " << setw(3);
		cin >> (*stu).Grade.m_Usuallyresults;
		//cout << "请输入总评成绩： " << setw(3);
		//cin >> (*stu).Grade.m_Totalscore;
		(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
			+ (*stu).Grade.m_Biology)/6 + 0.3*(*stu).Grade.m_Usuallyresults;
		stu->next = p->next;
		p->next = stu;
		amount++;
		cout << "数据信息录入成功，想继续录入吗?(y/n)";
		cin >> c;
		p = p->next;
		while (c != 'y'&&c != 'n')
		{
			cout << "指令错误<请输入y/n!>!!!!!!" << endl;
			cout << "数据信息录入成功，想继续录入吗(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
	cout << "输入了" << amount << "个学生的信息." << endl;
}
void  SearchByName()//按姓名查询
{
	char c;
	string name;
	do
	{
		student *stu = head->next;
		bool flag = 0;
		cout << "请输入您要查询的学生姓名：" << endl;
		cin >> name;
		for (int i2 = 1; i2 <= amount; i2++)
		{

			if (name == stu->name)
			{
				flag = 1;
				cout << "您要查询的学生是：" << stu->name << endl;
				cout << "   学号	   姓名   性别	 语文   英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.m_Chinese;
				cout << setw(12) << (*stu).Grade.m_Englishscore;
				cout << setw(8) << (*stu).Grade.m_Mathscore;
				cout << setw(8) << (*stu).Grade.m_Physics;
				cout << setw(7) << (*stu).Grade.m_Chemistry;
				cout << setw(7) << (*stu).Grade.m_Biology;
				cout << setw(9) << (*stu).Grade.m_Usuallyresults;
				cout << endl;
				break;
			}
			else stu = stu->next;
		}//for
		if (flag == 1)
		{
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0)
		{
			cout << "对不起!您要查询的学生不存在!!!!!!!" << endl;
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void SearchByNumber()//按学号查询
{
	char c;
	string  no;
	do
	{
		student *stu = head->next;
		bool flag = 0;
		cout << "请输入您要查询的学生学号：" << endl;
		cin >> no;
		for (int i2 = 1; i2 <= amount; i2++)
		{
			if (no == stu->number)
			{
				flag = 1;
				cout << "您要查询的学生是：" << stu->name << endl;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.m_Chinese;
				cout << setw(12) << (*stu).Grade.m_Englishscore;
				cout << setw(8) << (*stu).Grade.m_Mathscore;
				cout << setw(8) << (*stu).Grade.m_Physics;
				cout << setw(7) << (*stu).Grade.m_Chemistry;
				cout << setw(7) << (*stu).Grade.m_Biology;
				cout << setw(9) << (*stu).Grade.m_Usuallyresults;
				cout << endl;
				break;
			}
			else stu = stu->next;
		}//for
		if (flag == 1)
		{
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0)
		{
			cout << "对不起!您要查询的学生不存在!!!!!!!" << endl;
			cout << "您想继续查询吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "指令错误!!!!!<请输入y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void EditByName()//修改学生数据,按姓名修改
{
	string name; char c;
	do
	{
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "请输入您要修改的学生的姓名：" << endl;
		cin >> name;
		do
		{
			if (name == (*stu).name)
			{
				flag = 1;
				cout << "请输入新的语文成绩：" << endl;
				cin >> Grade.m_Chinese;
				(*stu).Grade.m_Chinese = Grade.m_Chinese;
				cout << "请输入新的英语成绩：" << endl;
				cin >> Grade.m_Englishscore;
				(*stu).Grade.m_Englishscore = Grade.m_Englishscore;
				cout << "请输入新的数学成绩：" << endl;
				cin >> Grade.m_Mathscore;
				(*stu).Grade.m_Mathscore = Grade.m_Mathscore;
				cout << "请输入新的物理成绩：" << endl;
				cin >> Grade.m_Physics;
				(*stu).Grade.m_Physics = Grade.m_Physics;
				cout << "请输入新的化学成绩：" << endl;
				cin >> Grade.m_Chemistry;
				(*stu).Grade.m_Chemistry = Grade.m_Chemistry;	
				cout << "请输入新的生物成绩：" << endl;
				cin >> Grade.m_Biology;
				(*stu).Grade.m_Biology = Grade.m_Biology;
				cout << "请输入新的平时成绩：" << endl;
				cin >> Grade.m_Usuallyresults;
				(*stu).Grade.m_Usuallyresults = Grade.m_Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
					+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.m_Chinese;
				cout << setw(12) << (*stu).Grade.m_Englishscore;
				cout << setw(8) << (*stu).Grade.m_Mathscore;
				cout << setw(8) << (*stu).Grade.m_Physics;
				cout << setw(7) << (*stu).Grade.m_Chemistry;
				cout << setw(7) << (*stu).Grade.m_Biology;
				cout << setw(9) << (*stu).Grade.m_Usuallyresults;
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
		while (c != 'y'&&c != 'n')
		{
			cout << "指令错误<请输入y/n!>!!!!!!!" << endl;
			cout << "您想继续修改吗?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void EditByNumber()//修改学生数据,按学号修改
{
	string number; char c;
	do
	{
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "请输入您要修改的学生的学号：" << endl;
		cin >> number;
		do
		{
			if (number == (*stu).number)
			{
				flag = 1;
				cout << "请输入新的语文成绩：" << endl;
				cin >> Grade.m_Chinese;
				(*stu).Grade.m_Chinese = Grade.m_Chinese;
				cout << "请输入新的英语成绩：" << endl;
				cin >> Grade.m_Englishscore;
				(*stu).Grade.m_Englishscore = Grade.m_Englishscore;
				cout << "请输入新的数学成绩：" << endl;
				cin >> Grade.m_Mathscore;
				(*stu).Grade.m_Mathscore = Grade.m_Mathscore;
				cout << "请输入新的物理成绩：" << endl;
				cin >> Grade.m_Physics;
				(*stu).Grade.m_Physics = Grade.m_Physics;
				cout << "请输入新的化学成绩：" << endl;
				cin >> Grade.m_Chemistry;
				(*stu).Grade.m_Chemistry = Grade.m_Chemistry;
				cout << "请输入新的生物成绩：" << endl;
				cin >> Grade.m_Biology;
				(*stu).Grade.m_Biology = Grade.m_Biology;
				cout << "请输入新的平时成绩：" << endl;
				cin >> Grade.m_Usuallyresults;
				(*stu).Grade.m_Usuallyresults = Grade.m_Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
					+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
				cout << "   学号	   姓名   性别	  语文   	英语    数学    物理   化学   生物    平时成绩   总评成绩" << endl;
				cout << setw(8) << (*stu).number;
				cout << setw(8) << (*stu).name;
				cout << setw(5) << (*stu).sex;
				cout << setw(10) << (*stu).Grade.m_Chinese;
				cout << setw(12) << (*stu).Grade.m_Englishscore;
				cout << setw(8) << (*stu).Grade.m_Mathscore;
				cout << setw(8) << (*stu).Grade.m_Physics;
				cout << setw(7) << (*stu).Grade.m_Chemistry;
				cout << setw(7) << (*stu).Grade.m_Biology;
				cout << setw(9) << (*stu).Grade.m_Usuallyresults;
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
		while (c != 'y'&&c != 'n')
		{
			cout << "指令错误<请输入y/n!>!!!!!!!" << endl;
			cout << "您想继续修改吗?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void Delete()//删除学生信息
{
	char c; string no;
	do
	{
		bool flag = 0;
		cout << "请输入您要删除的学生的学号：" << endl;
		cin >> no;
		student *q, *p;
		q = head;
		while (q->next != NULL && q->next->number != no)q = q->next;
		if (q->next != NULL)
		{
			flag = 1;
			p = q->next;
			q->next = q->next->next;
			amount--;
			free(p);
			cout << ".......删除成功!!!!!!" << endl;
		}
		if (flag == 0)
		{
			cout << "对不起!!!您要删除的学生不存在!!!!!" << endl;
			cout << "您想继续删除吗?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "指令错误!!!<请输入y/n!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
//void Statistics()
//{
//	student *p = head->next;
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (int i1 = 1; i1 <= amount; i1++) { if (p->Grade.m_DataStructurescore < 60)a++; p = p->next; }//记录数据结构不及格人数
//	student *p1 = head->next;
//	for (int i2 = 1; i2 <= amount; i2++) { if (p1->Grade.m_Englishscore < 60)b++; p1 = p1->next; }//记录英语不及格人数
//	student *p2 = head->next;
//	for (int i3 = 1; i3 <= amount; i3++) { if (p2->Grade.m_Mathscore < 60)c++; p2 = p2->next; }//记录数学不及格人数
//	student *p3 = head->next;
//	for (int i4 = 1; i4 <= amount; i4++) { if (p3->Grade.m_PE < 60)d++; p3 = p3->next; }//记录体育不及格人数
//	student *p4 = head->next;
//	for (int i5 = 1; i5 <= amount; i5++) { if (p4->Grade.m_Probability < 60)e++; p4 = p4->next; }//记录概率不及格人数
//	cout << "数据结构不及格人数: " << a << endl;
//	cout << "英语不及格人数： " << b << endl;
//	cout << "数学不及格人数： " << c << endl;
//	cout << "体育不及格人数： " << d << endl;
//	cout << "概率不及格人数： " << e << endl;
//	student *p5 = head->next;
//	int j = 1;
//	while (p5 != NULL && j <= amount)
//	{
//		int f = 0;
//		if (p5->Grade.m_DataStructurescore < 60)f++;
//		if (p5->Grade.m_Englishscore < 60)f++;
//		if (p5->Grade.m_Mathscore < 60)f++;
//		if (p5->Grade.m_PE < 60)f++;
//		if (p5->Grade.m_Probability < 60)f++;
//		cout << p5->name << "同学不及格门数： " << f;
//		if (f != 0)cout << "  分别是：";
//		if (p5->Grade.m_DataStructurescore < 60)cout << " 数据结构  ";
//		if (p5->Grade.m_Englishscore < 60)cout << "  英语 ";
//		if (p5->Grade.m_Mathscore < 60)cout << "  数学  ";
//		if (p5->Grade.m_PE < 60)cout << "  体育  ";
//		if (p5->Grade.m_Probability < 60)cout << "  概率  ";
//		cout << endl; j++;
//		p5 = p5->next;
//	}
//}
void FreadFile()
{
	student *p2, *p1;
	p1 = p2 = new student;
	ifstream fin("成绩管理.txt", ios::out);
	fin >> amount;
	cout << "共读出" << amount << "个学生信息: "; cout << endl;
	head = p2;//把头传给head
	if (!fin)
	{
		cout << "不能打开文件!!!!!!" << endl;
	}
	for (int k = 1; k <= amount; k++)
	{
		p1 = new  student;
		fin >> p1->number >> p1->name >> p1->sex >> p1->Grade.m_Chinese >> p1->Grade.m_Englishscore >> p1->Grade.m_Mathscore >> p1->Grade.m_Physics >> p1->Grade.m_Chemistry >> p1->Grade.m_Biology >> p1->Grade.m_Usuallyresults >> p1->average;
		p2->next = p1;
 p2 = p1;
	}
	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分" << endl;
	student	*q = head->next;
	for (int l = 1; l <= amount; l++)
	{
		cout << setw(8) << q->number;
		cout << setw(8) << q->name;
		cout << setw(5) << q->sex;
		cout << setw(9) << q->Grade.m_Chinese;
		cout << setw(9) << q->Grade.m_Englishscore;
		cout << setw(8) << q->Grade.m_Mathscore;
		cout << setw(8) << q->Grade.m_Physics;
		cout << setw(7) << q->Grade.m_Chemistry;
		cout << setw(7) << q->Grade.m_Biology;
		cout << setw(9) << q->Grade.m_Usuallyresults;
		cout << setw(9) << q->average;
		cout << endl;
		q = q->next;
	}
	//显示读入数据
	fin.close();
	cout << "...... 数据已经成功读取完毕." << endl;
}
void Insert()
{
	char c;
	int j = 0; student *q = head->next;
	for (int i = 1; i <= amount - 1; i++)
		q = q->next;//找文件的尾
	do
	{
		student *stu = new student;
		cout << "请输入学号：(8位)" << setw(4);
		cin >> (*stu).number;
		cout << "请输入姓名： " << setw(4);
		cin >> (*stu).name;
		cout << "请输入性别：" << setw(2);
		cin >> (*stu).sex;
		cout << "请输入语文成绩：" << setw(3);
		cin >> (*stu).Grade.m_Chinese;
		cout << "请输入英语成绩： " << setw(3);
		cin >> (*stu).Grade.m_Englishscore;
		cout << "请输入数学成绩： " << setw(3);
		cin >> (*stu).Grade.m_Mathscore;
		cout << "请输入物理成绩： " << setw(3);
		cin >> (*stu).Grade.m_Physics;
		cout << "请输入化学成绩： " << setw(3);
		cin >> (*stu).Grade.m_Chemistry;
		cout << "请输入生物成绩： " << setw(3);
		cin >> (*stu).Grade.m_Biology;
		cout << "请输入平时成绩： " << setw(3);
		cin >> (*stu).Grade.m_Usuallyresults;  //算分数
		(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
			+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
		amount++;
		cout << "数据信息插入成功，想继续插入吗?(y/n)";
		cin >> c;
		q = q->next;
		while (c != 'y'&&c != 'n')
		{
			cout << "指令错误<请输入y/n!>!!!!!!" << endl;
			cout << "数据信息插入成功，想继续插入吗(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
}
//void Sort_DataStructrue()//按数据结构排序
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_DataStructurescore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//直接选择排序
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
//	for (int i1 = amount; i1 >= 1; i1--)
//	{
//		student *p = head->next;
//		for (int y = 1; y <= amount; y++)
//		{
//			if (p->Grade.m_DataStructurescore == B[i1])
//			{
//				cout << setw(8) << p->number;
//				cout << setw(8) << p->name;
//				cout << setw(5) << p->sex;
//				cout << setw(9) << p->Grade.m_DataStructurescore;
//				cout << setw(9) << p->Grade.m_Englishscore;
//				cout << setw(8) << p->Grade.m_Mathscore;
//				cout << setw(8) << p->Grade.m_PE;
//				cout << setw(7) << p->Grade.m_Probability;
//				cout << setw(9) << p->average;
//				cout << setw(7) << j - i1 + 1;
//				cout << endl;
//			}//if
//			p = p->next;
//		}
//	}
//}
//void Sort_Englishi()//按英语排序
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Englishscore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//直接选择排序
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
//	for (int i1 = amount; i1 >= 1; i1--)
//	{
//		student *p = head->next;
//		for (int y = 1; y <= amount; y++)
//		{
//			if (p->Grade.m_Englishscore == B[i1])
//			{
//				cout << setw(8) << p->number;
//				cout << setw(8) << p->name;
//				cout << setw(5) << p->sex;
//				cout << setw(9) << p->Grade.m_DataStructurescore;
//				cout << setw(9) << p->Grade.m_Englishscore;
//				cout << setw(8) << p->Grade.m_Mathscore;
//				cout << setw(8) << p->Grade.m_PE;
//				cout << setw(7) << p->Grade.m_Probability;
//				cout << setw(9) << p->average;
//				cout << setw(7) << j - i1 + 1;
//				cout << endl;
//			}//if
//			p = p->next;
//		}
//	}
//}
//void Sort_Math()//按数学排序
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Mathscore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//直接选择排序
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
//	for (int i1 = amount; i1 >= 1; i1--)
//	{
//		student *p = head->next;
//		for (int y = 1; y <= amount; y++)
//		{
//			if (p->Grade.m_Mathscore == B[i1])
//			{
//				cout << setw(8) << p->number;
//				cout << setw(8) << p->name;
//				cout << setw(5) << p->sex;
//				cout << setw(9) << p->Grade.m_DataStructurescore;
//				cout << setw(9) << p->Grade.m_Englishscore;
//				cout << setw(8) << p->Grade.m_Mathscore;
//				cout << setw(8) << p->Grade.m_PE;
//				cout << setw(7) << p->Grade.m_Probability;
//				cout << setw(9) << p->average;
//				cout << setw(7) << j - i1 + 1;
//				cout << endl;
//			}//if
//			p = p->next;
//		}
//	}
//}
//void Sort_PE()//按体育排序
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_PE;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//直接选择排序
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
//	for (int i1 = amount; i1 >= 1; i1--)
//	{
//		student *p = head->next;
//		for (int y = 1; y <= amount; y++)
//		{
//			if (p->Grade.m_PE == B[i1])
//			{
//				cout << setw(8) << p->number;
//				cout << setw(8) << p->name;
//				cout << setw(5) << p->sex;
//				cout << setw(9) << p->Grade.m_DataStructurescore;
//				cout << setw(9) << p->Grade.m_Englishscore;
//				cout << setw(8) << p->Grade.m_Mathscore;
//				cout << setw(8) << p->Grade.m_PE;
//				cout << setw(7) << p->Grade.m_Probability;
//				cout << setw(9) << p->average;
//				cout << setw(7) << j - i1 + 1;
//				cout << endl;
//			}//if
//			p = p->next;
//		}
//	}
//
//}
//void Sort_Probability()//按概率排序
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Probability;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//直接选择排序
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
//	for (int i1 = amount; i1 >= 1; i1--)
//	{
//		student *p = head->next;
//		for (int y = 1; y <= amount; y++)
//		{
//			if (p->Grade.m_Probability == B[i1])
//			{
//				cout << setw(8) << p->number;
//				cout << setw(8) << p->name;
//				cout << setw(5) << p->sex;
//				cout << setw(9) << p->Grade.m_DataStructurescore;
//				cout << setw(9) << p->Grade.m_Englishscore;
//				cout << setw(8) << p->Grade.m_Mathscore;
//				cout << setw(8) << p->Grade.m_PE;
//				cout << setw(7) << p->Grade.m_Probability;
//				cout << setw(9) << p->average;
//				cout << setw(7) << j - i1 + 1;
//				cout << endl;
//			}//if
//			p = p->next;
//		}
//	}
//}
void Sort_Average()//按平均分排序
{
	int j = 0;
	student *q = head->next; float B[Q];
	for (int g = 1; g <= amount; g++)
	{
		A[g] = q->average;
		q = q->next;
	}
	for (int i = 2; i <= amount; ++i)//直接选择排序
		if (A[i] <= A[i - 1]) {
			A[0] = A[i];
			A[i] = A[i - 1];
			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//元素后移
			A[j + 1] = A[0];
		}
	B[1] = A[1];
	for (int i2 = 1, j = 1; i2 <= amount; i2++)
		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
	cout << "   学号	   姓名   性别	 数据结构   英语    数学    体育   概率   平均分   名次" << endl;
	for (int i1 = amount; i1 >= 1; i1--)
	{
		student *p = head->next;
		for (int y = 1; y <= amount; y++)
		{
			if (p->average == B[i1])
			{
				cout << setw(8) << p->number;
				cout << setw(8) << p->name;
				cout << setw(5) << p->sex;
				cout << setw(10) << p->Grade.m_Chinese;
				cout << setw(12) << p->Grade.m_Englishscore;
				cout << setw(8) << p->Grade.m_Mathscore;
				cout << setw(8) << p->Grade.m_Physics;
				cout << setw(7) << p->Grade.m_Chemistry;
				cout << setw(7) << p->Grade.m_Biology;
				cout << setw(9) << p->Grade.m_Usuallyresults;
				cout << setw(9) << p->average;
				cout << setw(7) << j - i1 + 1;
				cout << endl;
			}//if
			p = p->next;
		}
	}
}