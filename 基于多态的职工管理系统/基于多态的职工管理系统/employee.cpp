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
	 cout << "ְ����ţ�" << this->m_id
		 << "\tְ��������" << this->m_name
		 << "\t��λ��" << this->getDeptName()
		 << "\t��λְ����ɾ�����������" << endl;


}
//��ȡ��λ����
string employee::getDeptName()
{
	return string("��ְͨ��");
}