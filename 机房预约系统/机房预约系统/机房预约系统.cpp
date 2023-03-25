#include<iostream>
#include "identify.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include "globalfile.h"
#include <fstream>
using namespace std;

//�����ʦ�Ӳ˵�����

void teachermenu(identity* &teacher1) 
{
	
	while (true) 
	{
		teacher1->opermenu();

		teacher* tea = (teacher*)teacher1;
		
		int select = 0;

		cin >> select;

		if (select == 1)//�鿴����ԤԼ
		{
			tea->showallorder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->validorder();
		}
		else
		{
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//����ѧ���Ӳ˵�����
void studentmenu(identity *&student1) 
{
	while (true)
	{

		//ת������ָ�룬���ܲ����������������
		student* stu = (student*)student1;

		//����ѧ���Ӳ˵�
		stu->opermenu();

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyorder();
		}
		else if (select == 2)//�鿴�ҵ�ԤԼ
		{
			stu->showmyorder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showallorder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelorder();
		}
		else//ע����¼
		{
			delete student1;//ɾ�����������������ݣ�
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}

}



//�������Ա�Ӳ˵�����
void managermenu(identity* & manager1)
{
	while (true)
	{

		//������ָ��תΪ����ָ�룬���������������ӿ�
		manager* man = (manager*)manager1;

		//���ù���Ա�Ӳ˵�
		manager1->opermenu();

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
		//	cout << "����˺�" << endl;
			man->addperson();
		}
		else if (select == 2)//�鿴�˺�
		{
		//	cout << "�鿴�˺�" << endl;
			man->showperson();
		}
		else if (select == 3)//�鿴����
		{
		//	cout << "�鿴����" << endl;
			man->showcomputer();
		}
		else if (select == 4)//���ԤԼ
		{
		//	cout << "���ԤԼ" << endl;
			man->cleanfile();
		}
		else {
			//ע��
			delete manager1;//���ٶ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}


 


//��¼����  ����1  �����ļ���  ����2  �����������
void loginin(string filename, int type)
{
	//����ָ�룬����ָ���������
	identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);
	
	//�ж��ļ��Ƿ����
	if (!ifs.is_open() )
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "������������֣�" << endl; 
	cin >> name;


	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fid;
		string fname;
		string fpwd;
		//�ļ��е����ݶ���
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
	/*		cout << fid << endl;
			cout << fname << endl;
			cout << fpwd << endl;*/
			if (fid == id && fname == name && fpwd == pwd)
			{

				
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new student(id,name,pwd);
				//����ѧ������Ӳ˵�
				studentmenu(person);


				return;
			  }
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fid;//���ļ��л�ȡ��id��
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) //������˳�ѭ��
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);//����ָ��ָ���������
				//�����ʦ�Ӳ˵�
				teachermenu(person);

				return; 
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fname;//���ļ��л�ȡ����
		string fpwd;//���ļ��л�ȡ����

		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new manager(name, pwd);
				//�������Ա�Ӳ˵�����
				managermenu(person);


				return;
			}
		}

	}
	
	cout << "��֤��¼ʧ�ܣ�" << endl;
	
	system("pause");
	system("cls");
	return;
}


int main() 
{
	int select = 0;//���ڽ����û�ѡ��

	while (true) {
		cout << "================��ӭʹ�û���ԤԼ����ϵͳ================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t -----------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        1.ѧ��         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        2.��ʦ         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        3.����Ա       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        0.�˳�         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t -----------------------\n";
		cout << "����������ѡ��";

		cin >> select;
		
		switch (select)
		{
		case 1:  //ѧ�����
			loginin(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ���
			loginin(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			loginin(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");
			return 0;//�˳�main����
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
	system("pause");

	return 0;
}