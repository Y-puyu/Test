#include <iostream> 
#include <string> 
#include<fstream> 
#include<iomanip> 
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

int amount = 0; //��¼ѧ������ 
int const Q = 80;
float A[Q];
struct score//���Ź��νṹ��
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
struct student//ѧ���ṹ��
{
	string number;
	string name;
	string sex;
	score Grade;
	float average;
	struct student *next;
};
student *head = (student *)malloc(sizeof(student));
void InputScore();//¼��ѧ����Ϣ
void DisplayMainMenu();//��ʾ�˵�
void SearchByName();//��ѯ
void SearchByNumber();//��ѯ
void EditByName();//�޸�
void EditByNumber();//�޸�
void Delete();//ɾ��ѧ����Ϣ
void save();//����ѧ����Ϣ
//void Sort_DataStructrue();//�����ݽṹ����
//void Sort_Englishi();//��Ӣ������
//void Sort_Math();//����ѧ����
//void Sort_PE();//����������
//void Sort_Probability();//����������
void Sort_Average();//��ƽ��������
//void Statistics();//ͳ��ѧ����Ϣ
void ShowStudentInfo();//��ʾѧ����Ϣ
void FreadFile();//��ȡ�ļ���Ϣ
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
				cout << "ָ�����!!!!!!!!!!" << endl;
				cout << " ��ѡ����Ӧ�����ֽ��в���: " << endl;
			}
		} while (flag2 == 0);
		switch (x)
		{
		case 'a':
			cout << "******************************���ڽ���ѧ����Ϣ¼��******************************\n";
			InputScore();
			cout << "�����ѧ����ϢΪ��" << endl;
			ShowStudentInfo();          
			cout << "********************************************************************************\n";
			DisplayMainMenu(); 
			break;
		case 'b':
		{
			char z;
			cout << "******************************���ڽ���ѧ����Ϣ��ѯ******************************\n";
			cout << "��ѡ���ѯ��ʽ��" << endl;
			cout << "(0)--��������ѯ��   (1)--��ѧ�Ų�ѯ��" << endl;
			cin >> z;
			while (z != '0'&&z != '1')
			{
				cout << "ָ�����(��ѡ��(0)����(1))!!!!!!!" << endl;
				cout << "��ѡ���ѯ��ʽ��(0)--��������ѯ��   (1)--��ѧ�Ų�ѯ��";
				cin >> z;
			}
			switch (z)
			{
			case '0':SearchByName(); break;//��������ѯ
			case '1':SearchByNumber(); break;//��ѧ�Ų�ѯ
			}
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'c':
		{
			char p;
		    cout << "******************************���ڽ���ѧ����Ϣ�޸�******************************\n";
			cout << "��ѡ���޸ķ�ʽ��(0)--�������޸ģ�     (1)--��ѧ���޸ģ�" << endl;
			cin >> p;
			while (p != '0'&&p != '1')
				{
					cout << "ָ�����(��ѡ��(0)����(1))!!!!!!!" << endl;
					cout << "��ѡ���޸ķ�ʽ��(0)--�������޸ģ�     (1)--��ѧ���޸ģ�" << endl;
					cin >> p;
				}
			switch (p)
			{
				case  '0': EditByName(); break;//�������޸�
				case  '1': EditByNumber(); break;//��ѧ���޸� 
			}					 cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'd': 
			cout << "******************************���ڽ���ѧ����Ϣɾ��******************************\n";
			Delete();//ɾ��
			ShowStudentInfo();			    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'e': 
			cout << "******************************���ڽ�����ʾѧ����Ϣ******************************\n";
			ShowStudentInfo(); //��ʾ���� 	    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'f':
			cout << "******************************���ڽ��б���ѧ����Ϣ******************************\n";
			save();//����ѧ����Ϣ		    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'g':
			cout << "******************************���ڽ��ж�ȡѧ����Ϣ******************************\n";
			FreadFile();	   cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'h':
			cout << "******************************���ڽ���ͳ��ѧ����Ϣ******************************\n";
			//Statistics();//ͳ��ѧ����Ϣ	   		    cout<<"********************************************************************************\n"; 
			DisplayMainMenu();
			break;
		case 'i':
			cout << "******************************���ڽ�������******************************\n";
			//cout << "��ѡ������ʽ��" << endl;
			//cout << "1  �����ݽṹ�ɼ����� " << endl;
			//cout << "2  ��Ӣ��ɼ����� " << endl;
			//cout << "3  ����ѧ�ɼ����� " << endl;
			//cout << "4  �������ɼ����� " << endl;
			//cout << "5  �����ʳɼ����� " << endl;
			cout << " ���ܳɼ����� " << endl;
			Sort_Average();
			//cin >> a;
			//while (a<'1' || a>'6')
			//{
			//	//cout << "ָ�����(��ѡ��(1-6))!!!!!!!" << endl;
			//	//cout << "1  �����ݽṹ�ɼ����� " << endl;
			//	//cout << "2  ��Ӣ��ɼ����� " << endl;
			//	//cout << "3  ����ѧ�ɼ����� " << endl;
			//	//cout << "4  �������ɼ����� " << endl;
			//	//cout << "5  �����ʳɼ����� " << endl;
			//	cout << "6  ��ƽ�������� " << endl;
			//	cin >> a;
			//}
			//switch (a)
			//{
			////case  '1': Sort_DataStructrue(); break;// �����ݽṹ�ɼ�����
			////case  '2': Sort_Englishi(); break;//��Ӣ��ɼ����� 
			////case  '3': Sort_Math(); break;//����ѧ�ɼ�����
			////case  '4': Sort_PE(); break;//�������ɼ�����
			////case  '5': Sort_Probability(); break;//�����ʳɼ�����
			//case  '6': Sort_Average(); break;//��ƽ��������

			//}    cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;	
		case 'j':
			cout << "********************************************************************************\n";
			cout << " �����˳�ѧ���ɼ�����ϵͳ, лл����ʹ��! \n";    
			cout << "********************************************************************************\n";
			cout << endl;
			exit(0);
			break;
		case 'k':	      
			cout << "********************************************************************************\n";
			cout << "*****************************���ڽ��в���ѧ����Ϣ*********************************\n";
			Insert();    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
	} while (flag2 == 1);
}
void DisplayMainMenu()//��ʾ�˵�
{
	cout << "\t\t ---------------------------------------------- \n";
	cout << "\t\t��****************ѧ���ɼ�����ϵͳ************��\n";
	cout << "\t\t��*------------------------------------------*��\n";
	cout << "\t\t��*  a.¼��ѧ����Ϣ������b.��ѯѧ����Ϣ      *��\n";
	cout << "\t\t��*������������������������������������������*��\n";
	cout << "\t\t��*��c.�޸�ѧ����Ϣ������d.ɾ��ѧ����Ϣ��    *��\n";
	cout << "\t\t��*������������������������������������������*��\n";
	cout << "\t\t��*��e.��ʾѧ����Ϣ������f.����ѧ����Ϣ��    *��\n";
	cout << "\t\t��*������������������������������������������*��\n";
	cout << "\t\t��*��g.���ļ�            h.ͳ��ѧ����Ϣ������*��\n";
	cout << "\t\t��*������������������������������������������*��\n";
	cout << "\t\t��*��i.���򡡡�����������k.����ѧ����Ϣ������*��\n";
	cout << "\t\t��*                                          *��\n";
	cout << "\t\t��*  j.�˳����������������������������������*��\n";
	cout << "\t\t��********************************************��\n";
	cout << "\t\t ----------------------------------------------\n";
}
void ShowStudentInfo()//��ʾѧ����Ϣ	
{
	student *stu = head->next;
	cout << "   ѧ��	   ����   �Ա�	 ����  	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
void save()//����ѧ����Ϣ
{
	student *stu = head->next;//��ͷ����
	ofstream out("�ɼ�����.txt", ios::out);
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
			//<< stu->Grade.m_Totalscore << "\t";   //û��ѧ������ĳɼ�
		stu = stu->next; 
		i++;
		cout << endl;
	}
	cout << "......�ɹ���ѧ����Ϣ���浽���ɼ�����.txt����!!!!" << endl;
	out.close();
}
void InputScore()//¼��ѧ������
{
	head->next = NULL;//Ҫ¼��ѧ����Ϣ������ɾ����ǰ���е���Ϣ
	amount = 0;
	char c;
	int j = 0;
	student *p = head;
	do
	{
		student *stu = new student;
		cout << "������ѧ�ţ�(8λ)" << setw(4);
		cin >> (*stu).number;
		cout << "������������ " << setw(4);
		cin >> (*stu).name;
		cout << "�������Ա�" << setw(2);
		cin >> (*stu).sex;
		cout << "���������ĳɼ���" << setw(3);
		cin >> (*stu).Grade.m_Chinese;
		cout << "������Ӣ��ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Englishscore;
		cout << "��������ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Mathscore;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Physics;
		cout << "�����뻯ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Chemistry;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Biology;
		cout << "������ƽʱ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Usuallyresults;
		//cout << "�����������ɼ��� " << setw(3);
		//cin >> (*stu).Grade.m_Totalscore;
		(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
			+ (*stu).Grade.m_Biology)/6 + 0.3*(*stu).Grade.m_Usuallyresults;
		stu->next = p->next;
		p->next = stu;
		amount++;
		cout << "������Ϣ¼��ɹ��������¼����?(y/n)";
		cin >> c;
		p = p->next;
		while (c != 'y'&&c != 'n')
		{
			cout << "ָ�����<������y/n!>!!!!!!" << endl;
			cout << "������Ϣ¼��ɹ��������¼����(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
	cout << "������" << amount << "��ѧ������Ϣ." << endl;
}
void  SearchByName()//��������ѯ
{
	char c;
	string name;
	do
	{
		student *stu = head->next;
		bool flag = 0;
		cout << "��������Ҫ��ѯ��ѧ��������" << endl;
		cin >> name;
		for (int i2 = 1; i2 <= amount; i2++)
		{

			if (name == stu->name)
			{
				flag = 1;
				cout << "��Ҫ��ѯ��ѧ���ǣ�" << stu->name << endl;
				cout << "   ѧ��	   ����   �Ա�	 ����   Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0)
		{
			cout << "�Բ���!��Ҫ��ѯ��ѧ��������!!!!!!!" << endl;
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void SearchByNumber()//��ѧ�Ų�ѯ
{
	char c;
	string  no;
	do
	{
		student *stu = head->next;
		bool flag = 0;
		cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�" << endl;
		cin >> no;
		for (int i2 = 1; i2 <= amount; i2++)
		{
			if (no == stu->number)
			{
				flag = 1;
				cout << "��Ҫ��ѯ��ѧ���ǣ�" << stu->name << endl;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0)
		{
			cout << "�Բ���!��Ҫ��ѯ��ѧ��������!!!!!!!" << endl;
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void EditByName()//�޸�ѧ������,�������޸�
{
	string name; char c;
	do
	{
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "��������Ҫ�޸ĵ�ѧ����������" << endl;
		cin >> name;
		do
		{
			if (name == (*stu).name)
			{
				flag = 1;
				cout << "�������µ����ĳɼ���" << endl;
				cin >> Grade.m_Chinese;
				(*stu).Grade.m_Chinese = Grade.m_Chinese;
				cout << "�������µ�Ӣ��ɼ���" << endl;
				cin >> Grade.m_Englishscore;
				(*stu).Grade.m_Englishscore = Grade.m_Englishscore;
				cout << "�������µ���ѧ�ɼ���" << endl;
				cin >> Grade.m_Mathscore;
				(*stu).Grade.m_Mathscore = Grade.m_Mathscore;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.m_Physics;
				(*stu).Grade.m_Physics = Grade.m_Physics;
				cout << "�������µĻ�ѧ�ɼ���" << endl;
				cin >> Grade.m_Chemistry;
				(*stu).Grade.m_Chemistry = Grade.m_Chemistry;	
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.m_Biology;
				(*stu).Grade.m_Biology = Grade.m_Biology;
				cout << "�������µ�ƽʱ�ɼ���" << endl;
				cin >> Grade.m_Usuallyresults;
				(*stu).Grade.m_Usuallyresults = Grade.m_Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
					+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
				cout << ".......�����޸ĳɹ�!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "�Բ�����Ҫ�޸ĵ�ѧ��������!����������!!!!!!" << endl;
		cout << "������޸���?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n')
		{
			cout << "ָ�����<������y/n!>!!!!!!!" << endl;
			cout << "��������޸���?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void EditByNumber()//�޸�ѧ������,��ѧ���޸�
{
	string number; char c;
	do
	{
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�" << endl;
		cin >> number;
		do
		{
			if (number == (*stu).number)
			{
				flag = 1;
				cout << "�������µ����ĳɼ���" << endl;
				cin >> Grade.m_Chinese;
				(*stu).Grade.m_Chinese = Grade.m_Chinese;
				cout << "�������µ�Ӣ��ɼ���" << endl;
				cin >> Grade.m_Englishscore;
				(*stu).Grade.m_Englishscore = Grade.m_Englishscore;
				cout << "�������µ���ѧ�ɼ���" << endl;
				cin >> Grade.m_Mathscore;
				(*stu).Grade.m_Mathscore = Grade.m_Mathscore;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.m_Physics;
				(*stu).Grade.m_Physics = Grade.m_Physics;
				cout << "�������µĻ�ѧ�ɼ���" << endl;
				cin >> Grade.m_Chemistry;
				(*stu).Grade.m_Chemistry = Grade.m_Chemistry;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.m_Biology;
				(*stu).Grade.m_Biology = Grade.m_Biology;
				cout << "�������µ�ƽʱ�ɼ���" << endl;
				cin >> Grade.m_Usuallyresults;
				(*stu).Grade.m_Usuallyresults = Grade.m_Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
					+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
				cout << ".......�����޸ĳɹ�!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "�Բ�����Ҫ�޸ĵ�ѧ��������!����������!!!!!!" << endl;
		cout << "������޸���?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n')
		{
			cout << "ָ�����<������y/n!>!!!!!!!" << endl;
			cout << "��������޸���?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void Delete()//ɾ��ѧ����Ϣ
{
	char c; string no;
	do
	{
		bool flag = 0;
		cout << "��������Ҫɾ����ѧ����ѧ�ţ�" << endl;
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
			cout << ".......ɾ���ɹ�!!!!!!" << endl;
		}
		if (flag == 0)
		{
			cout << "�Բ���!!!��Ҫɾ����ѧ��������!!!!!" << endl;
			cout << "�������ɾ����?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n')
			{
				cout << "ָ�����!!!<������y/n!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
//void Statistics()
//{
//	student *p = head->next;
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (int i1 = 1; i1 <= amount; i1++) { if (p->Grade.m_DataStructurescore < 60)a++; p = p->next; }//��¼���ݽṹ����������
//	student *p1 = head->next;
//	for (int i2 = 1; i2 <= amount; i2++) { if (p1->Grade.m_Englishscore < 60)b++; p1 = p1->next; }//��¼Ӣ�ﲻ��������
//	student *p2 = head->next;
//	for (int i3 = 1; i3 <= amount; i3++) { if (p2->Grade.m_Mathscore < 60)c++; p2 = p2->next; }//��¼��ѧ����������
//	student *p3 = head->next;
//	for (int i4 = 1; i4 <= amount; i4++) { if (p3->Grade.m_PE < 60)d++; p3 = p3->next; }//��¼��������������
//	student *p4 = head->next;
//	for (int i5 = 1; i5 <= amount; i5++) { if (p4->Grade.m_Probability < 60)e++; p4 = p4->next; }//��¼���ʲ���������
//	cout << "���ݽṹ����������: " << a << endl;
//	cout << "Ӣ�ﲻ���������� " << b << endl;
//	cout << "��ѧ������������ " << c << endl;
//	cout << "���������������� " << d << endl;
//	cout << "���ʲ����������� " << e << endl;
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
//		cout << p5->name << "ͬѧ������������ " << f;
//		if (f != 0)cout << "  �ֱ��ǣ�";
//		if (p5->Grade.m_DataStructurescore < 60)cout << " ���ݽṹ  ";
//		if (p5->Grade.m_Englishscore < 60)cout << "  Ӣ�� ";
//		if (p5->Grade.m_Mathscore < 60)cout << "  ��ѧ  ";
//		if (p5->Grade.m_PE < 60)cout << "  ����  ";
//		if (p5->Grade.m_Probability < 60)cout << "  ����  ";
//		cout << endl; j++;
//		p5 = p5->next;
//	}
//}
void FreadFile()
{
	student *p2, *p1;
	p1 = p2 = new student;
	ifstream fin("�ɼ�����.txt", ios::out);
	fin >> amount;
	cout << "������" << amount << "��ѧ����Ϣ: "; cout << endl;
	head = p2;//��ͷ����head
	if (!fin)
	{
		cout << "���ܴ��ļ�!!!!!!" << endl;
	}
	for (int k = 1; k <= amount; k++)
	{
		p1 = new  student;
		fin >> p1->number >> p1->name >> p1->sex >> p1->Grade.m_Chinese >> p1->Grade.m_Englishscore >> p1->Grade.m_Mathscore >> p1->Grade.m_Physics >> p1->Grade.m_Chemistry >> p1->Grade.m_Biology >> p1->Grade.m_Usuallyresults >> p1->average;
		p2->next = p1;
 p2 = p1;
	}
	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����" << endl;
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
	//��ʾ��������
	fin.close();
	cout << "...... �����Ѿ��ɹ���ȡ���." << endl;
}
void Insert()
{
	char c;
	int j = 0; student *q = head->next;
	for (int i = 1; i <= amount - 1; i++)
		q = q->next;//���ļ���β
	do
	{
		student *stu = new student;
		cout << "������ѧ�ţ�(8λ)" << setw(4);
		cin >> (*stu).number;
		cout << "������������ " << setw(4);
		cin >> (*stu).name;
		cout << "�������Ա�" << setw(2);
		cin >> (*stu).sex;
		cout << "���������ĳɼ���" << setw(3);
		cin >> (*stu).Grade.m_Chinese;
		cout << "������Ӣ��ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Englishscore;
		cout << "��������ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Mathscore;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Physics;
		cout << "�����뻯ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Chemistry;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Biology;
		cout << "������ƽʱ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.m_Usuallyresults;  //�����
		(*stu).average = 0.7*((*stu).Grade.m_Chinese + (*stu).Grade.m_Englishscore + (*stu).Grade.m_Mathscore + (*stu).Grade.m_Physics + (*stu).Grade.m_Chemistry
			+ (*stu).Grade.m_Biology) + 0.3*(*stu).Grade.m_Usuallyresults;
		amount++;
		cout << "������Ϣ����ɹ��������������?(y/n)";
		cin >> c;
		q = q->next;
		while (c != 'y'&&c != 'n')
		{
			cout << "ָ�����<������y/n!>!!!!!!" << endl;
			cout << "������Ϣ����ɹ��������������(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
}
//void Sort_DataStructrue()//�����ݽṹ����
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_DataStructurescore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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
//void Sort_Englishi()//��Ӣ������
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Englishscore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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
//void Sort_Math()//����ѧ����
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Mathscore;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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
//void Sort_PE()//����������
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_PE;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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
//void Sort_Probability()//����������
//{
//	int j = 0;
//	student *q = head->next; float B[Q];
//	for (int g = 1; g <= amount; g++)
//	{
//		A[g] = q->Grade.m_Probability;
//		q = q->next;
//	}
//	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
//		if (A[i] <= A[i - 1]) {
//			A[0] = A[i];
//			A[i] = A[i - 1];
//			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
//			A[j + 1] = A[0];
//		}
//	B[1] = A[1];
//	for (int i2 = 1, j = 1; i2 <= amount; i2++)
//		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
//	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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
void Sort_Average()//��ƽ��������
{
	int j = 0;
	student *q = head->next; float B[Q];
	for (int g = 1; g <= amount; g++)
	{
		A[g] = q->average;
		q = q->next;
	}
	for (int i = 2; i <= amount; ++i)//ֱ��ѡ������
		if (A[i] <= A[i - 1]) {
			A[0] = A[i];
			A[i] = A[i - 1];
			for (int j = i - 2; A[0] <= A[j]; --j)A[j + 1] = A[j];//Ԫ�غ���
			A[j + 1] = A[0];
		}
	B[1] = A[1];
	for (int i2 = 1, j = 1; i2 <= amount; i2++)
		if (A[i2] > B[j]) { j++; B[j] = A[i2]; }
	cout << "   ѧ��	   ����   �Ա�	 ���ݽṹ   Ӣ��    ��ѧ    ����   ����   ƽ����   ����" << endl;
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