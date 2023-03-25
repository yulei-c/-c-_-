#pragma once
#include<iostream>
using namespace std;
#include"identify.h"
#include<string>
#include<fstream>
#include"orderfile.h"
#include<vector>

class teacher :public identity
{
public:
	teacher();

	//有参构造
	teacher(int empid, string name, string pwd);

	//菜单界面
	virtual void opermenu();

	//查看所有学生预约
	void showallorder();

	//审核预约
	void validorder();

	//职工号
	int m_empid;

};
