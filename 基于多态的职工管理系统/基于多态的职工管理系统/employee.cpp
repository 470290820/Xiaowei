#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

employee::employee(int id, string name, int deptno)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptno = deptno;
}
employee::~employee()
{

}
 void employee::showInfo()
{
	 cout << "职工编号：" << this->m_id
		 << "\t职工姓名：" << this->m_name
		 << "\t岗位：" << this->getDeptName()
		 << "\t岗位职责：完成经理交给的任务！" << endl;


}
//获取岗位名称
string employee::getDeptName()
{
	return string("普通职工");
}