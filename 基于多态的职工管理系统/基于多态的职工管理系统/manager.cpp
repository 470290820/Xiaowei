#include<iostream>
#include<string>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int deptno)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptno = deptno;
}
manager::~manager()
{

}
void manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��ҽ����񽻸�Ա����" << endl;


}
//��ȡ��λ����
string manager::getDeptName()
{
	return string("����");
}