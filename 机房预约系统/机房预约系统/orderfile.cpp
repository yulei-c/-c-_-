#include "orderfile.h"


//构造函数
orderfile::orderfile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;   //日期
	string interval; //时间段
	string stuid;  //学生编号
	string stuname; //学生姓名
	string roomid;//机房编号
	string status;//预约状态

	this->m_size = 0;
	while (ifs >> data && ifs >> interval && ifs >> stuid &&
		ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		//data::1
		string key;
		string value;
		map<string, string> m;

		//截取日期
		int pos = data.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = data.substr(0, pos);//截取0-pos之间的字符，data
			value = data.substr(pos + 1, data.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}

		//cout << "key=" << key << endl;
		//cout << "value=" << value << endl;

		//截取时间段
		pos = interval.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = interval.substr(0, pos);//截取0-pos之间的字符，data
			value = interval.substr(pos + 1, interval.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}

		//截取学生id
		pos = stuid.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = stuid.substr(0, pos);//截取0-pos之间的字符，data
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}

		//截取学生姓名
		pos = stuname.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = stuname.substr(0, pos);//截取0-pos之间的字符，data
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}

		//截取机房号
		pos = roomid.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = roomid.substr(0, pos);//截取0-pos之间的字符，data
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}

		//截取预约状态
		pos = status.find(":");//4  找到字符所在位置，从0开始
		if (pos != -1)
		{
			key = status.substr(0, pos);//截取0-pos之间的字符，data
			value = status.substr(pos + 1, status.size() - pos - 1);//size=9;

			m.insert(make_pair(key, value));//make_pair创建队组
		}
		//将小map容器放入到大map容器中
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();

	//测试最大map容器
	//for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end(); it++)
	//{
	//	cout << "条数为" << it->first << " value=" << endl;
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
	//从文件中重新获取数据
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