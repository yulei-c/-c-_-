#include"student.h"
#include <fstream>

student::student() {

}

student::student(int id, string name, string pwd)
{
	//初始化属性
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	computerroom com;
	while (ifs >> com.m_cmid && ifs >> com.m_maxnum)
	{
		//将读取信息放入容器中
		vcom.push_back(com);
	}
	ifs.close();
}

//有参构造

//菜单界面
void student::opermenu()
{
	cout << "欢迎学生代表：" << this->m_name << "登录" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.申请预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.查看我的预约      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.查看所有预约      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.取消预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.注销登录          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "请输入您的操作：";
 }

//申请预约
void student::applyorder()
{

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int data = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vcom.size(); i++){
		cout << vcom[i].m_cmid << "号机房容量为：" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= vcom.size())
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); //追加的方式打开
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

//查看自身预约
void student::showmyorder()
{
	orderfile of;//创建一个预约文件类
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{  //string转 int
		//string利用 .c_str()转const char *
		//利用atoi（const char *）转int
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))//找到自身预约
		{
			cout << "预约日期：周" << of.m_orderdata[i]["data"];
			cout << " 时间段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号：" << of.m_orderdata[i]["roomid"] ;
			string status = "状态：";

			if (of.m_orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderdata[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderdata[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void student::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i+1 << "、";
		cout << "预约日期：周" << of.m_orderdata[i]["data"];
		cout << " 时间段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderdata[i]["stuid"];
		cout << " 姓名：" << of.m_orderdata[i]["stuname"];
		cout << " 机房号：" << of.m_orderdata[i]["roomid"];

		string status = "状态：";
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void student::cancelorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;//存放在最大容器中的小标编号
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//判断是自身的学号
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()))
		{
			//先筛选状态  审核中或预约成功
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderdata[i]["data"];
				cout << " 时间段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号：" << of.m_orderdata[i]["roomid"];

				string status = "状态：";
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << " "<<status << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
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
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}
