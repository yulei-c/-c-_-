#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "globalfile.h"
#include <map>


class orderfile
{
public:
	//���캯��
	orderfile();

	//����ԤԼ��¼
	void updataorder();

	//��¼ԤԼ����
	int m_size;

	//��¼����ԤԼ��Ϣ������  key��¼���� value�����¼��ֵ����Ϣ
	map<int, map<string, string>> m_orderdata;
};