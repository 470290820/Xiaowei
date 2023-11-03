#pragma once
#include<iostream>
#include<string>
#include"worker.h"
//普通员工
class employee:public worker
{
public:
	employee(int id,string name ,int deptno);
	~employee();
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();

};