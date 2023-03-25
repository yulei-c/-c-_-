#include"teacher.h"


teacher::teacher()
{

}

//�вι���
teacher::teacher(int empid, string name, string pwd)
{
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}

//�˵�����
void teacher::opermenu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.�鿴����ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.���ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
 }

//�鿴����ѧ��ԤԼ
void teacher::showallorder()
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
		cout << i + 1 << " ��";
		cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["data"];
		cout << " ʱ���" << (of.m_orderdata[i]["interval"]== "1" ? "����" : "����");
		cout << " ѧ��" << of.m_orderdata[i]["stuid"];
		cout << " ����" << of.m_orderdata[i]["stuname"];
		cout << " �������" << of.m_orderdata[i]["roomid"];
		string status = " ״̬��";

		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}

		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if  (of.m_orderdata[i]["status"] == "-1")
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

//���ԤԼ
void teacher::validorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int> v;
	int index = 0;
	cout << "����˵�ԤԼ��¼���£�" << endl;

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ��";
			cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["data"];
			cout << " ʱ��Σ�" <<( of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ����ţ�" << of.m_orderdata[i]["stuid"];
			cout << " ѧ��������" << of.m_orderdata[i]["stuname"];
			cout << " ������ţ�" << of.m_orderdata[i]["roomid"];
			string status = " ״̬�������";
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�����
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderdata[v[select - 1]]["status"] = "-1";
				}
				of.updataorder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}