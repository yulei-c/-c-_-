#include "orderfile.h"


//���캯��
orderfile::orderfile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;   //����
	string interval; //ʱ���
	string stuid;  //ѧ�����
	string stuname; //ѧ������
	string roomid;//�������
	string status;//ԤԼ״̬

	this->m_size = 0;
	while (ifs >> data && ifs >> interval && ifs >> stuid &&
		ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		//data::1
		string key;
		string value;
		map<string, string> m;

		//��ȡ����
		int pos = data.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = data.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = data.substr(pos + 1, data.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}

		//cout << "key=" << key << endl;
		//cout << "value=" << value << endl;

		//��ȡʱ���
		pos = interval.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = interval.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = interval.substr(pos + 1, interval.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}

		//��ȡѧ��id
		pos = stuid.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = stuid.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}

		//��ȡѧ������
		pos = stuname.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = stuname.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}

		//��ȡ������
		pos = roomid.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = roomid.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}

		//��ȡԤԼ״̬
		pos = status.find(":");//4  �ҵ��ַ�����λ�ã���0��ʼ
		if (pos != -1)
		{
			key = status.substr(0, pos);//��ȡ0-pos֮����ַ���data
			value = status.substr(pos + 1, status.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair��������
		}
		//��Сmap�������뵽��map������
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();

	//�������map����
	//for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end(); it++)
	//{
	//	cout << "����Ϊ" << it->first << " value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key=" << mit->first << " value=" << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}


void orderfile::updataorder()
{
	if (this->m_size == 0)
	{
		return;
	}
	//���ļ������»�ȡ����
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "data:" << this->m_orderdata[i]["data"] << " ";
		ofs << "interval:" << this->m_orderdata[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderdata[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderdata[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderdata[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderdata[i]["status"] << endl;
	}
	ofs.close();
}