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

	//�вι���
	teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void opermenu();

	//�鿴����ѧ��ԤԼ
	void showallorder();

	//���ԤԼ
	void validorder();

	//ְ����
	int m_empid;

};
