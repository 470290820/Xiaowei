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
	 cout << "职工编号：" << this->m_id
		 << "\t职工姓名：" << this->m_name
		 << "\t岗位：" << this->getDeptName()
		 << "\t岗位职责：管理公司，并且给经理交待任务！" << endl;


}
//获取岗位名称
string boss::getDeptName()
{
	return string("老板");
}

boss::~boss()
{
}
