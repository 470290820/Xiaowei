#pragma once
#include<iostream>
#include<string>
#include"worker.h"
//��ͨԱ��
class employee:public worker
{
public:
	employee(int id,string name ,int deptno);
	~employee();
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();

};