#pragma once
#include<iostream>
#include<string>
#include"worker.h"

class boss :public worker
{
public:
	boss(int id, string name, int deptno);
	~boss();
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
