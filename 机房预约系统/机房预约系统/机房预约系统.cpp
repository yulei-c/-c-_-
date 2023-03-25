#include<iostream>
#include "identify.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include "globalfile.h"
#include <fstream>
using namespace std;

//进入教师子菜单界面

void teachermenu(identity* &teacher1) 
{
	
	while (true) 
	{
		teacher1->opermenu();

		teacher* tea = (teacher*)teacher1;
		
		int select = 0;

		cin >> select;

		if (select == 1)//查看所有预约
		{
			tea->showallorder();
		}
		else if (select == 2)//审核预约
		{
			tea->validorder();
		}
		else
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//进入学生子菜单界面
void studentmenu(identity *&student1) 
{
	while (true)
	{

		//转成子类指针，才能操作子类里面的内容
		student* stu = (student*)student1;

		//调用学生子菜单
		stu->opermenu();

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyorder();
		}
		else if (select == 2)//查看我的预约
		{
			stu->showmyorder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showallorder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelorder();
		}
		else//注销登录
		{
			delete student1;//删掉传进来堆区的数据；
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}

}



//进入管理员子菜单界面
void managermenu(identity* & manager1)
{
	while (true)
	{

		//将父类指针转为子类指针，调用子类里其他接口
		manager* man = (manager*)manager1;

		//调用管理员子菜单
		manager1->opermenu();

		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
		//	cout << "添加账号" << endl;
			man->addperson();
		}
		else if (select == 2)//查看账号
		{
		//	cout << "查看账号" << endl;
			man->showperson();
		}
		else if (select == 3)//查看机房
		{
		//	cout << "查看机房" << endl;
			man->showcomputer();
		}
		else if (select == 4)//清空预约
		{
		//	cout << "清空预约" << endl;
			man->cleanfile();
		}
		else {
			//注销
			delete manager1;//销毁对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}


 


//登录功能  参数1  操作文件名  参数2  操作身份类型
void loginin(string filename, int type)
{
	//父类指针，用于指向子类对象
	identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	
	//判断文件是否存在
	if (!ifs.is_open() )
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入你的名字：" << endl; 
	cin >> name;


	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fid;
		string fname;
		string fpwd;
		//文件中的数据读入
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
	/*		cout << fid << endl;
			cout << fname << endl;
			cout << fpwd << endl;*/
			if (fid == id && fname == name && fpwd == pwd)
			{

				
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new student(id,name,pwd);
				//进入学生身份子菜单
				studentmenu(person);


				return;
			  }
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fid;//从文件中获取的id号
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) //读完就退出循环
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);//父类指针指向子类对象
				//进入教师子菜单
				teachermenu(person);

				return; 
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fname;//从文件中获取姓名
		string fpwd;//从文件中获取密码

		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new manager(name, pwd);
				//进入管理员子菜单界面
				managermenu(person);


				return;
			}
		}

	}
	
	cout << "验证登录失败！" << endl;
	
	system("pause");
	system("cls");
	return;
}


int main() 
{
	int select = 0;//用于接受用户选择

	while (true) {
		cout << "================欢迎使用机房预约管理系统================" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t -----------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        1.学生         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        2.老师         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        3.管理员       |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|        0.退出         |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t -----------------------\n";
		cout << "请输入您的选择：";

		cin >> select;
		
		switch (select)
		{
		case 1:  //学生身份
			loginin(STUDENT_FILE, 1);
			break;
		case 2: //老师身份
			loginin(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			loginin(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用！" << endl;
			system("pause");
			return 0;//退出main函数
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
	system("pause");

	return 0;
}