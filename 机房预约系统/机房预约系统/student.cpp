#include"student.h"
#include <fstream>

student::student() {

}

student::student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	computerroom com;
	while (ifs >> com.m_cmid && ifs >> com.m_maxnum)
	{
		//����ȡ��Ϣ����������
		vcom.push_back(com);
	}
	ifs.close();
}

//�вι���

//�˵�����
void student::opermenu()
{
	cout << "��ӭѧ������" << this->m_name << "��¼" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.����ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.�鿴�ҵ�ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.�鿴����ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.ȡ��ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "���������Ĳ�����";
 }

//����ԤԼ
void student::applyorder()
{

	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vcom.size(); i++){
		cout << vcom[i].m_cmid << "�Ż�������Ϊ��" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= vcom.size())
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); //׷�ӵķ�ʽ��
		ofs << "data:" << data << " ";
		ofs << "interval:" << interval << " ";
		ofs << "stuid:" << this->m_id<< " ";
		ofs << "stuname:" << this->m_name << " ";
		ofs << "roomid:" << room << " ";
		ofs << "status:" << 1 << endl;
		
		ofs.close();
		system("pause");
		system("cls");
}

//�鿴����ԤԼ
void student::showmyorder()
{
	orderfile of;//����һ��ԤԼ�ļ���
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{  //stringת int
		//string���� .c_str()תconst char *
		//����atoi��const char *��תint
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))//�ҵ�����ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["data"];
			cout << " ʱ��Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.m_orderdata[i]["roomid"] ;
			string status = "״̬��";

			if (of.m_orderdata[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderdata[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderdata[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void student::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i+1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["data"];
		cout << " ʱ��Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderdata[i]["stuid"];
		cout << " ������" << of.m_orderdata[i]["stuname"];
		cout << " �����ţ�" << of.m_orderdata[i]["roomid"];

		string status = "״̬��";
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void student::cancelorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;//�������������е�С����
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//�ж��������ѧ��
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))
		{
			//��ɸѡ״̬  ����л�ԤԼ�ɹ�
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["data"];
				cout << " ʱ��Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
				cout << " �����ţ�" << of.m_orderdata[i]["roomid"];

				string status = "״̬��";
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << " "<<status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else {
				of.m_orderdata[v[select - 1]]["status"] = "0";
				of.updataorder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}
