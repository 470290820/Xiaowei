#pragma once
#include<iostream>
#include"employee.h"
#include"boss.h"
#include"manager.h"

#include"workerManager.h"
#include<fstream>

#define FILENAME "empFile.txt"


using namespace std;
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;//测试代码
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;//测试代码
		this->m_empNum = 0;
		this->m_empArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，并且记录数据
	int num = this->get_empNum();
	//cout << "职工人数为：" << num << endl;//测试代码
	this->m_empNum = num;
	//开辟空间
	this->m_empArray = new worker * [this->m_empNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	//测试
	/*for (int i = 0; i < this->m_empNum; i++)
	{
		cout << "职工编号：" << this->m_empArray[i]->m_id
			<< "职工姓名：" << this->m_empArray[i]->m_name
			<< "职工职位：" << this->m_empArray[i]->m_deptno << endl;
	}*/


}
//展示菜单
void workerManager::show_Menu()
{
	cout << "**********************************************************" << endl;
	cout << "	********** 欢迎您使用职工管理系统 **********" << endl;
	cout << "	************** 0、退出管理系统 *************" << endl;
	cout << "	************** 1、增加职工信息 *************" << endl;
	cout << "	************** 2、显示职工职工 *************" << endl;
	cout << "	************** 3、删除离职职工 *************" << endl;
	cout << "	************** 4、修改职工信息 *************" << endl;
	cout << "	************** 5、查找职工信息 *************" << endl;
	cout << "	************** 6、按照编号排序 *************" << endl;
	cout << "	************** 7、清空所有文档 *************" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
}

//退出系统·······功能号为0
void workerManager::exitSystem()
{
	cout << "以退出系统，欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
//增加职工-----功能号为1
void workerManager::add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_empNum + addNum;

		//开辟新空间
		worker** newSpace = new worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				newSpace[i] = this->m_empArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << "个新职工编号：" << endl;
			
			while (true)
			{
				int flag = true;
				cin >> id;
				for (int i = 0; i < this->m_empNum; i++)
				{
					if (this->m_empArray[i]->m_id == id)
					{
						cout << "该编号已存在，请重新输入：" << endl;
						flag = false;
						break;
					}
				}
				if (flag == true) break;
			}
			

			cout << "请输入第 " << i + 1 << "个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			worker* work = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				work = new employee(id, name, 1);
				break;
			case 2: //经理
				work = new manager(id, name, 2);
				break;
			case 3:  //老板
				work = new boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_empNum + i] = work;
		}

		//释放原有空间
		delete[] this->m_empArray;

		//更改新空间的指向
		this->m_empArray = newSpace;

		//更新新的个数
		this->m_empNum = newSize;
		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//文件当前不为空
		this->m_FileIsEmpty = false;
		//更新到文件中
		this->save();


	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* work = NULL;
		if (did == 1)
		{
			work = new employee(id, name, did);
		}
		else if (did == 2)
		{
			work = new manager(id, name, did);
		}
		else
		{
			work = new boss(id, name, did);
		}
		this->m_empArray[index] = work;
		index++;
	}
	ifs.close();

}

//显示职工信息---功能号为2
void workerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！！！" << endl;
	}
	else {
		for (int i = 0; i < m_empNum; i++)
		{
			this->m_empArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}


//删除职工-----功能号为3
void workerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//说明职工存在，并且删除的位置为index
		{
			for (int i = index; i < this->m_empNum - 1; i++)
			{
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_empNum--;
			//同步更新到文件
			this->save();
			cout << "删除成功！" << endl;
			//删除成功后按任意键清屏
			system("pause");
			system("cls");
		}
		else
		{
			cout << "删除失败，没有该职工！" << endl;
		}
	}
}

//修改职工信息---功能号为4
void workerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号：" << endl;
		int index = 0;
		cin >> index;
		int ret = this->IsExist(index);
		if (ret != -1)//职工存在
		{
			delete[] this->m_empArray[ret];
			int newid;
			string newname;
			int newdeptno;
			cout << "查询到员工编号为" << index << "的职工信息：" << endl;
			this->m_empArray[index]->showInfo();
			cout << "请重新输入新的员工编号：" << endl;
			cin >> newid;
			cout << "请重新输入新的员工姓名：" << endl;
			cin >> newname;
			cout << "请重新选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newdeptno;
			worker* work = nullptr;
			switch (newdeptno)
			{
			case 1:
				work = new employee(newid, newname, 1);
				break;
			case 2:
				work = new manager(newid, newname, 2);
				break;
			case 3:
				work = new boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_empArray[ret] = work;
			cout << "修改成功！" << this->m_empArray[ret]->m_deptno << endl;
			this->save();

		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");
}


//查询员工---功能号为5
void workerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式:" << endl;
		cout << "1、按照编号查找" << endl;
		cout << "2、按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的员工编号：" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！职工编号为：" << id << "的信息如下：" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else {
				cout << "查无此人！" << endl;
			}

		}
		else
		{
			string name;
			cout << "请输入查找员工的姓名：" << endl;
			cin >> name;
			int flag = false;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i]->m_name == name)
				{
					cout << "查找成功！职工姓名为：" << name << "的信息如下：" << endl;

					this->m_empArray[i]->showInfo();
					flag = true;
				}

			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}

	}
	system("pause");
	system("cls");
}
//按照编号排序--功能号为6
void workerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empNum; i++)
		{
			int minOrMax = i; //声明最小值 或 最大值下标
			for (int j = i + 1; j < this->m_empNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_empArray[minOrMax]->m_id > this->m_empArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (this->m_empArray[minOrMax]->m_id < this->m_empArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			//判断一开始认定 最小值或最大值 是不是 计算的最小值或最大值，如果不是 交换数据
			if (i != minOrMax)
			{
				worker* temp = this->m_empArray[i];
				this->m_empArray[i] = this->m_empArray[minOrMax];
				this->m_empArray[minOrMax] = temp;
			}

		}

		cout << "排序成功！排序后的结果为： " << endl;
		this->save(); //排序后结果保存到文件中
		this->show_Emp();//展示所有职工
	}

}
//清空文档-----功能号为7
void workerManager::clewn_File()
{
	cout << "确认清空！" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i] != NULL)
				{
					delete this->m_empArray[i];

				}
			}
			this->m_empNum = 0;
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_empArray != nullptr)
	{
		for (int i = 0; i < this->m_empNum; i++)
		{
			if (this->m_empArray[i] != NULL)
			{
				delete[] this->m_empArray[i];
				
			}
		}
		delete[] this->m_empArray;
		this->m_empArray = nullptr;
	}
}
//保存文件
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_deptno << endl;
	}
	ofs.close();
}





//统计员工人数
int workerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件  读

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}

	return num;

}
//判断职工是否存在
int workerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->m_empArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


