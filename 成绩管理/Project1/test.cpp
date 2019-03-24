#include <iostream> 
#include <string> 
#include<fstream> 
#include<iomanip> 
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

int amount = 0;       //��¼ѧ������ 
int const Q = 80;
float A[Q];
struct score {       //���Ź��νṹ��
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
struct student {     //ѧ���ṹ��
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
void ShowStudentInfo();//��ʾѧ����Ϣ
void FreadFile();//��ȡ�ļ���Ϣ
void Insert();

void DisplayMainMenu() {   //��ʾ�˵�
	cout << "\t\t ---------------------------------------------- \n";
	cout << "\t\t��**************ѧ���ɼ�����ϵͳ**************��\n";
	cout << "\t\t��*------------------------------------------*��\n";
	cout << "\t\t��*    a.¼��ѧ����Ϣ������b.��ѯѧ����Ϣ      *��\n";
	cout << "\t\t��*����������������������������������������  ��*��\n";
	cout << "\t\t��*��  c.�޸�ѧ����Ϣ������d.ɾ��ѧ����Ϣ��    *��\n";
	cout << "\t\t��*����������������������������������������  ��*��\n";
	cout << "\t\t��*��  e.��ʾѧ����Ϣ������f.����ѧ����Ϣ��    *��\n";
	cout << "\t\t��*����������������������������������������  ��*��\n";
	cout << "\t\t��*��  g.���ļ�          �� i.����ѧ����Ϣ������*��\n";
	cout << "\t\t��*��������������������������������������  ����*��\n";
	cout << "\t\t��*��  h.�˳��������                      ��*��\n";
	cout << "\t\t��*                                        *��\n";
	cout << "\t\t��********************************************��\n";
	cout << "\t\t ----------------------------------------------\n";
}
void ShowStudentInfo() {   //��ʾѧ����Ϣ	
	student *stu = head->next;
	cout << "   ѧ��	   ����   �Ա�	 ����  	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
void save() {     //����ѧ����Ϣ
	student *stu = head->next;//��ͷ����
	ofstream out("�ɼ�����.txt", ios::out);
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
	cout << "......�ɹ���ѧ����Ϣ���浽���ɼ�����.txt����!!!!" << endl;
	out.close();
}
void InputScore() {   //¼��ѧ������
	head->next = NULL;//Ҫ¼��ѧ����Ϣ������ɾ����ǰ���е���Ϣ
	amount = 0;
	char c;
	int j = 0;
	student *p = head;
	do {
		student *stu = new student;
		cout << "������ѧ�ţ�(9λ)" << setw(4);
		cin >> (*stu).number;
		cout << "������������ " << setw(4);
		cin >> (*stu).name;
		cout << "�������Ա�" << setw(2);
		cin >> (*stu).sex;
		cout << "���������ĳɼ���" << setw(3);
		cin >> (*stu).Grade.Chinese;
		cout << "������Ӣ��ɼ��� " << setw(3);
		cin >> (*stu).Grade.Englishscore;
		cout << "��������ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Mathscore;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.Physics;
		cout << "�����뻯ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Chemistry;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.Biology;
		cout << "������ƽʱ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Usuallyresults;
		(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
			+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
		stu->next = p->next;
		p->next = stu;
		amount++;
		cout << "������Ϣ¼��ɹ��������¼����?(y/n)";
		cin >> c;
		p = p->next;
		while (c != 'y'&&c != 'n') {
			cout << "ָ�����<������y/n!>!!!!!!" << endl;
			cout << "������Ϣ¼��ɹ��������¼����(y/n)";
			cin >> c;
		}
	} while (c == 'y');
	j++;
	cout << "������" << amount << "��ѧ������Ϣ." << endl;
}
void SearchByName() {  //��������ѯ
	string name;
	do {
		student *stu = head->next;
		bool flag = 0;
		cout << "��������Ҫ��ѯ��ѧ��������" << endl;
		cin >> name;
		for (int i2 = 1; i2 <= amount; i2++) {
			if (name == stu->name) {
				flag = 1;
				cout << "��Ҫ��ѯ��ѧ���ǣ�" << stu->name << endl;
				cout << "   ѧ��	   ����   �Ա�	 ����   Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0) {
			cout << "�Բ���!��Ҫ��ѯ��ѧ��������!!!!!!!" << endl;
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void SearchByNumber() {    //��ѧ�Ų�ѯ
	char c;
	string  no;
	do {
		student *stu = head->next;
		bool flag = 0;
		cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�" << endl;
		cin >> no;
		for (int i2 = 1; i2 <= amount; i2++) {
			if (no == stu->number) {
				flag = 1;
				cout << "��Ҫ��ѯ��ѧ���ǣ�" << stu->name << endl;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
		if (flag == 0) {
			cout << "�Բ���!��Ҫ��ѯ��ѧ��������!!!!!!!" << endl;
			cout << "���������ѯ��?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "ָ�����!!!!!<������y/n!!!!!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void EditByName() {  //�޸�ѧ������,�������޸�
	string name; char c;
	do {
		bool flag = 0;
		student *stu = head;
		score Grade;
		cout << "��������Ҫ�޸ĵ�ѧ����������" << endl;
		cin >> name;
		do {
			if (name == (*stu).name) {
				flag = 1;
				cout << "�������µ����ĳɼ���" << endl;
				cin >> Grade.Chinese;
				(*stu).Grade.Chinese = Grade.Chinese;
				cout << "�������µ�Ӣ��ɼ���" << endl;
				cin >> Grade.Englishscore;
				(*stu).Grade.Englishscore = Grade.Englishscore;
				cout << "�������µ���ѧ�ɼ���" << endl;
				cin >> Grade.Mathscore;
				(*stu).Grade.Mathscore = Grade.Mathscore;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.Physics;
				(*stu).Grade.Physics = Grade.Physics;
				cout << "�������µĻ�ѧ�ɼ���" << endl;
				cin >> Grade.Chemistry;
				(*stu).Grade.Chemistry = Grade.Chemistry;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.Biology;
				(*stu).Grade.Biology = Grade.Biology;
				cout << "�������µ�ƽʱ�ɼ���" << endl;
				cin >> Grade.Usuallyresults;
				(*stu).Grade.Usuallyresults = Grade.Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
					+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
				cout << ".......�����޸ĳɹ�!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "�Բ�����Ҫ�޸ĵ�ѧ��������!����������!!!!!!" << endl;
		cout << "������޸���?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n') {
			cout << "ָ�����<������y/n!>!!!!!!!" << endl;
			cout << "��������޸���?(y/n)" << endl;
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
		cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�" << endl;
		cin >> number;
		do {
			if (number == (*stu).number) {
				flag = 1;
				cout << "�������µ����ĳɼ���" << endl;
				cin >> Grade.Chinese;
				(*stu).Grade.Chinese = Grade.Chinese;
				cout << "�������µ�Ӣ��ɼ���" << endl;
				cin >> Grade.Englishscore;
				(*stu).Grade.Englishscore = Grade.Englishscore;
				cout << "�������µ���ѧ�ɼ���" << endl;
				cin >> Grade.Mathscore;
				(*stu).Grade.Mathscore = Grade.Mathscore;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.Physics;
				(*stu).Grade.Physics = Grade.Physics;
				cout << "�������µĻ�ѧ�ɼ���" << endl;
				cin >> Grade.Chemistry;
				(*stu).Grade.Chemistry = Grade.Chemistry;
				cout << "�������µ�����ɼ���" << endl;
				cin >> Grade.Biology;
				(*stu).Grade.Biology = Grade.Biology;
				cout << "�������µ�ƽʱ�ɼ���" << endl;
				cin >> Grade.Usuallyresults;
				(*stu).Grade.Usuallyresults = Grade.Usuallyresults;
				(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
					+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
				cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
				cout << ".......�����޸ĳɹ�!\n";
				break;
			}
			stu = stu->next;
		} while (stu != NULL);
		if (flag == 0)
			cout << "�Բ�����Ҫ�޸ĵ�ѧ��������!����������!!!!!!" << endl;
		cout << "������޸���?(y/n)" << endl;
		cin >> c;
		while (c != 'y'&&c != 'n') {
			cout << "ָ�����<������y/n!>!!!!!!!" << endl;
			cout << "��������޸���?(y/n)" << endl;
			cin >> c;
		}
	} while (c == 'y');
}
void Delete() {
	char c; string no;
	do {
		bool flag = 0;
		cout << "��������Ҫɾ����ѧ����ѧ�ţ�" << endl;
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
			cout << ".......ɾ���ɹ�!!!!!!" << endl;
		}
		if (flag == 0) {
			cout << "�Բ���!!!��Ҫɾ����ѧ��������!!!!!" << endl;
			cout << "�������ɾ����?(y/n)" << endl;
			cin >> c;
			while (c != 'y'&&c != 'n') {
				cout << "ָ�����!!!<������y/n!!>" << endl;
				cin >> c;
			}
		}
	} while (c == 'y');
}
void FreadFile() {
	student *p2, *p1;
	p1 = p2 = new student;
	ifstream fin("�ɼ�����.txt", ios::out);
	fin >> amount;
	cout << "������" << amount << "��ѧ����Ϣ: ";
	cout << endl;
	head = p2;//��ͷ����head
	if (!fin) {
		cout << "���ܴ��ļ�!!!!!!" << endl;
	}
	for (int k = 1; k <= amount; k++) {
		p1 = new  student;
		fin >> p1->number >> p1->name >> p1->sex >> p1->Grade.Chinese >> p1->Grade.Englishscore >> p1->Grade.Mathscore >>
			p1->Grade.Physics >> p1->Grade.Chemistry >> p1->Grade.Biology >> p1->Grade.Usuallyresults >> p1->average;
		p2->next = p1;
		p2 = p1;
	}
	cout << "   ѧ��	   ����   �Ա�	  ����   	Ӣ��    ��ѧ    ����   ��ѧ   ����    ƽʱ�ɼ�   �����ɼ�" << endl;
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
	//��ʾ��������
	fin.close();
	cout << "...... �����Ѿ��ɹ���ȡ���." << endl;
}
void Insert() {
	char c;
	int j = 0; 
	student *q = head->next;
	for (int i = 1; i <= amount - 1; i++)
		q = q->next;//���ļ���β
	do {
		student *stu = new student;
		cout << "������ѧ�ţ�(9λ)" << setw(4);
		cin >> (*stu).number;
		cout << "������������ " << setw(4);
		cin >> (*stu).name;
		cout << "�������Ա�" << setw(2);
		cin >> (*stu).sex;
		cout << "���������ĳɼ���" << setw(3);
		cin >> (*stu).Grade.Chinese;
		cout << "������Ӣ��ɼ��� " << setw(3);
		cin >> (*stu).Grade.Englishscore;
		cout << "��������ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Mathscore;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.Physics;
		cout << "�����뻯ѧ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Chemistry;
		cout << "����������ɼ��� " << setw(3);
		cin >> (*stu).Grade.Biology;
		cout << "������ƽʱ�ɼ��� " << setw(3);
		cin >> (*stu).Grade.Usuallyresults;  //�����
		(*stu).average = 0.7*((*stu).Grade.Chinese + (*stu).Grade.Englishscore + (*stu).Grade.Mathscore + (*stu).Grade.Physics + (*stu).Grade.Chemistry
			+ (*stu).Grade.Biology) / 6 + 0.3*(*stu).Grade.Usuallyresults;
		amount++;
		cout << "������Ϣ����ɹ��������������?(y/n)";
		cin >> c;
		q = q->next;
		while (c != 'y'&&c != 'n') {
			cout << "ָ�����<������y/n!>!!!!!!" << endl;
			cout << "������Ϣ����ɹ��������������(y/n)";
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
				cout << "ָ�����!!!!!!!!!!" << endl;
				cout << " ��ѡ����Ӧ�����ֽ��в���: " << endl;
			}
		} while (flag2 == 0);
		switch (x) {
		case 'a':
			cout << "******************************���ڽ���ѧ����Ϣ¼��******************************\n";
			InputScore();
			cout << "�����ѧ����ϢΪ��" << endl;
			ShowStudentInfo();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'b': {
			char z;
			cout << "******************************���ڽ���ѧ����Ϣ��ѯ******************************\n";
			cout << "��ѡ���ѯ��ʽ��" << endl;
			cout << "(0)--��������ѯ��   (1)--��ѧ�Ų�ѯ��" << endl;
			cin >> z;
			while (z != '0'&&z != '1') {
				cout << "ָ�����(��ѡ��(0)����(1))!!!!!!!" << endl;
				cout << "��ѡ���ѯ��ʽ��(0)--��������ѯ��   (1)--��ѧ�Ų�ѯ��";
				cin >> z;
			}
			switch (z) {
			case '0':SearchByName(); break;//��������ѯ
			case '1':SearchByNumber(); break;//��ѧ�Ų�ѯ
			}
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
		case 'c': {
			char p;
			cout << "******************************���ڽ���ѧ����Ϣ�޸�******************************\n";
			cout << "��ѡ���޸ķ�ʽ��(0)--�������޸ģ�     (1)--��ѧ���޸ģ�" << endl;
			cin >> p;
			while (p != '0'&&p != '1') {
				cout << "ָ�����(��ѡ��(0)����(1))!!!!!!!" << endl;
				cout << "��ѡ���޸ķ�ʽ��(0)--�������޸ģ�     (1)--��ѧ���޸ģ�" << endl;
				cin >> p;
			}
			switch (p) {
			case  '0': EditByName(); break;//�������޸�
			case  '1': EditByNumber(); break;//��ѧ���޸� 
			}
			cout << "********************************************************************************\n";
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
			ShowStudentInfo(); //��ʾ���� 	    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'f':
			cout << "******************************���ڽ��б���ѧ����Ϣ******************************\n";
			save();//����ѧ����Ϣ		    
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'g':
			cout << "******************************���ڽ��ж�ȡѧ����Ϣ******************************\n";
			FreadFile();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		case 'h':
			cout << "********************************************************************************\n";
			cout << " �����˳�ѧ���ɼ�����ϵͳ, лл����ʹ��! \n";
			cout << "********************************************************************************\n";
			cout << endl;
			exit(0);
			break;
		case 'i':
			cout << "********************************************************************************\n";
			cout << "*****************************���ڽ��в���ѧ����Ϣ*********************************\n";
			Insert();
			cout << "********************************************************************************\n";
			DisplayMainMenu();
			break;
		}
	} while (flag2 == 1);
}