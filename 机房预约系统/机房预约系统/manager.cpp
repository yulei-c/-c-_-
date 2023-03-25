#include "manager.h"
#include <fstream>
#include"globalfile.h"
#include "student.h"
#include "teacher.h"
#include <algorithm>

manager::manager()
{
}
//有参构造
manager::manager(string name, string pwd)
{  

	this->m_name = name;//记住自己的姓名
	this->m_pwd = pwd;//方便二阶段扩展和开发

	//初始化容器  获取到所有文件中老师和学生的信息
	this->initvector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerroom com; //创建一个类成员
	while (ifs >> com.m_cmid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vcom.size() << endl;

}



//菜单界面
void manager::opermenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;

 }

//添加账号
void manager::addperson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	
	string filename;
	string tip;
	ofstream ofs;
	string errortip;//重复错误提示

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//添加的是学生
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入:";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工号重复，请重新输入:";

	}
	//利用追加的方式  写文件
	ofs.open(filename, ios::out|ios::app );

	int id;//学号
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
			break;//退出循环
		}
	}



	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " <<pwd << " "<<endl;
	cout << "添加成功" << endl;

	system("pause");//暂停，按任意键继续
	system("cls");//清除屏幕上所有内容

	ofs.close();

	//调用初始化容器接口，重新验证
	this->initvector();
}

void printstudent(student& s)
{
	cout << "学号：" << s.m_id << " 姓名：" << s.m_name <<" 密码："<<s.m_pwd<< endl;
}
void printteacher(teacher& s)
{
	cout << "工号：" << s.m_empid << " 姓名：" << s.m_name << " 密码：" << s.m_pwd << endl;
}

//查看账号
void manager::showperson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "1、查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);//打印所有学生信息
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下：" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);//打印所有学生信息
	}
	system("pause");
	system("cls");
}

//查看机房信息
void manager::showcomputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号： " << it->m_cmid << " 机房最大容量： " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//清空预约
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void manager::initvector() {

	//将容器清空  insert()插入  erase()删除
	vstu.clear();
	vtea.clear();

	//读取信息  学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vstu.push_back(s);
	}
	cout << "当前学生数量为：" << vstu.size()<<endl;
	ifs.close();
	//从文件中读取信息   老师
	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	//从文件中读入信息
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);//压到容器最后面
	}
	cout << "当前老师数量为：" << vtea.size() << endl;
	ifs.close();

}

//检测重复 参数：（传入id，传入类型）  返回值：（true 代表有重复，false代表没有重复）
bool manager::checkrepeat(int id, int type) {
	if (type == 1)
	{
		//检测学生
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
		//检测老师
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