#pragma once
#include<iostream>
#include<string>
#include"worker.h"

class boss :public worker
{
public:
	boss(int id, string name, int deptno);
	~boss();
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
