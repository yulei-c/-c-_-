#pragma once  //防止头文件重复
#include <iostream>
#include "identify.h"
using namespace std;
#include<vector>
#include "computerroom.h"
#include "globalfile.h"
#include "orderfile.h"

class student :public identity
{
public:
	//默认构造
	student();

	student(int id, string name, string pwd);
	//有参构造

	//菜单界面
	virtual void opermenu();

	//申请预约
	void applyorder();

	//查看自身预约
	void showmyorder();

	//查看所有预约
	void showallorder();

	//取消预约
	void cancelorder();

	//学生学号 
	int m_id;

	//机房容器
	vector<computerroom> vcom;
};