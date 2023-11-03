
#pragma once
#include<iostream>
#include<string>
#include"worker.h"
//普通员工
class manager :public worker
{
public:
	manager(int id, string name, int deptno);
	~manager();
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();

};