#pragma once	//防止头文件重复包含
#include<iostream>
#include"worker.h"
using namespace std;


class workerManager
{
public:
	workerManager();
	~workerManager();
	//初始化员工
	void init_Emp();
	//展示菜单
	void show_Menu();
	//退出系统
	void exitSystem();
	//添加职工
	void add_Emp();
	//保存到文件
	void save();
	//显示职工信息-------功能号为2
	void show_Emp();
	//统计人数
	int get_empNum();
	//删除职工,按照编号删除
	void Del_Emp();
	//查询职工    功能号为5
	void Find_Emp();
	//按照编号排序
	void Sort_Emp();
	//清空文档
	void clewn_File();

	//判断职工是否存在
	int IsExist(int id);
	//职工信息修改
	void Mod_emp();
	//记录职工人数
	int m_empNum;	
	//职工数组的指针
	worker** m_empArray;
	//判断文件是否为空
	bool m_FileIsEmpty;
};
