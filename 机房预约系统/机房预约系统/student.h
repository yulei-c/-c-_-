#pragma once  //��ֹͷ�ļ��ظ�
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
	//Ĭ�Ϲ���
	student();

	student(int id, string name, string pwd);
	//�вι���

	//�˵�����
	virtual void opermenu();

	//����ԤԼ
	void applyorder();

	//�鿴����ԤԼ
	void showmyorder();

	//�鿴����ԤԼ
	void showallorder();

	//ȡ��ԤԼ
	void cancelorder();

	//ѧ��ѧ�� 
	int m_id;

	//��������
	vector<computerroom> vcom;
};