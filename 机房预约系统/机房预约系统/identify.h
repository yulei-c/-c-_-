#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

//��ݳ������
class identity {
public:
	//�����˵�  ���麯��
	virtual void opermenu() = 0;

	//�û���
	string m_name;

	//����
	string m_pwd;
};