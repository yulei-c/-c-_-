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

	//Ĭ�Ϲ���
	manager();

	//�вι���
	manager(string name, string pwd);

	//�˵�����
	virtual void opermenu();

	//����˺�
	void addperson();

	//�鿴�˺�
	void showperson();


	//�鿴������Ϣ
	void showcomputer();

	//���ԤԼ��¼
	void cleanfile();

	//����ظ� ����1 ���ѧ��/ְ����  ����2  �������
	bool checkrepeat(int id, int type);

	//��ʼ������
	void initvector();

	//ѧ������
	vector<student> vstu;

	//��ʦ����
	vector<teacher>vtea;

	//������Ϣ
	vector<computerroom>vcom;

};
