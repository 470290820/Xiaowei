#include<iostream>
#include<string>
#include"employee.h"
#include "boss.h"
using namespace std;

boss::boss(int id, string name, int deptno)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptno = deptno;
}

 void boss::showInfo()
{
	 cout << "ְ����ţ�" << this->m_id
		 << "\tְ��������" << this->m_name
		 << "\t��λ��" << this->getDeptName()
		 << "\t��λְ�𣺹���˾�����Ҹ�����������" << endl;


}
//��ȡ��λ����
string boss::getDeptName()
{
	return string("�ϰ�");
}

boss::~boss()
{
}
