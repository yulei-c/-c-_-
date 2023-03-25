#pragma once
#include "identify.h"
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerroom.h"

class manager :public identity
{
public:

	//默认构造
	manager();

	//有参构造
	manager(string name, string pwd);

	//菜单界面
	virtual void opermenu();

	//添加账号
	void addperson();

	//查看账号
	void showperson();


	//查看机房信息
	void showcomputer();

	//清空预约记录
	void cleanfile();

	//检测重复 参数1 检测学号/职工号  参数2  检测类型
	bool checkrepeat(int id, int type);

	//初始化容器
	void initvector();

	//学生容器
	vector<student> vstu;

	//教师容器
	vector<teacher>vtea;

	//机房信息
	vector<computerroom>vcom;

};
