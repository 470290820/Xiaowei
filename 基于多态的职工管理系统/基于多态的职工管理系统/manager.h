
#pragma once
#include<iostream>
#include<string>
#include"worker.h"
//��ͨԱ��
class manager :public worker
{
public:
	manager(int id, string name, int deptno);
	~manager();
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();

};