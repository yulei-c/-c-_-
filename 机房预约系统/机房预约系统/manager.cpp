#include "manager.h"
#include <fstream>
#include"globalfile.h"
#include "student.h"
#include "teacher.h"
#include <algorithm>

manager::manager()
{
}
//�вι���
manager::manager(string name, string pwd)
{  

	this->m_name = name;//��ס�Լ�������
	this->m_pwd = pwd;//������׶���չ�Ϳ���

	//��ʼ������  ��ȡ�������ļ�����ʦ��ѧ������Ϣ
	this->initvector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerroom com; //����һ�����Ա
	while (ifs >> com.m_cmid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vcom.size() << endl;

}



//�˵�����
void manager::opermenu()
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

 }

//����˺�
void manager::addperson()
{
	cout << "����������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	
	string filename;
	string tip;
	ofstream ofs;
	string errortip;//�ظ�������ʾ

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ӵ���ѧ��
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�������������:";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errortip = "ְ�����ظ�������������:";

	}
	//����׷�ӵķ�ʽ  д�ļ�
	ofs.open(filename, ios::out|ios::app );

	int id;//ѧ��
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret=checkrepeat(id,select);
		if (ret)
		{
			cout << errortip << endl;
		
		}
		else  
		{
			break;//�˳�ѭ��
		}
	}



	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " <<pwd << " "<<endl;
	cout << "��ӳɹ�" << endl;

	system("pause");//��ͣ�������������
	system("cls");//�����Ļ����������

	ofs.close();

	//���ó�ʼ�������ӿڣ�������֤
	this->initvector();
}

void printstudent(student& s)
{
	cout << "ѧ�ţ�" << s.m_id << " ������" << s.m_name <<" ���룺"<<s.m_pwd<< endl;
}
void printteacher(teacher& s)
{
	cout << "���ţ�" << s.m_empid << " ������" << s.m_name << " ���룺" << s.m_pwd << endl;
}

//�鿴�˺�
void manager::showperson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "1���鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);//��ӡ����ѧ����Ϣ
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);//��ӡ����ѧ����Ϣ
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void manager::showcomputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ� " << it->m_cmid << " ������������� " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//���ԤԼ
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void manager::initvector() {

	//���������  insert()����  erase()ɾ��
	vstu.clear();
	vtea.clear();

	//��ȡ��Ϣ  ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vstu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vstu.size()<<endl;
	ifs.close();
	//���ļ��ж�ȡ��Ϣ   ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	//���ļ��ж�����Ϣ
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);//ѹ�����������
	}
	cout << "��ǰ��ʦ����Ϊ��" << vtea.size() << endl;
	ifs.close();

}

//����ظ� ������������id���������ͣ�  ����ֵ����true �������ظ���false����û���ظ���
bool manager::checkrepeat(int id, int type) {
	if (type == 1)
	{
		//���ѧ��
		for (vector < student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector < teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}