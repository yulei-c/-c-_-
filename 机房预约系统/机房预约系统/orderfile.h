#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "globalfile.h"
#include <map>


class orderfile
{
public:
	//构造函数
	orderfile();

	//更新预约记录
	void updataorder();

	//记录预约条数
	int m_size;

	//记录所有预约信息的容器  key记录条数 value具体记录键值对信息
	map<int, map<string, string>> m_orderdata;
};