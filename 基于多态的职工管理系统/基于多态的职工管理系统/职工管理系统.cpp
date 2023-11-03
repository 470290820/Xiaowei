#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//测试代码
	/*worker* work = new employee(1, "张三", 1);
	work->showInfo();
	delete work;
	worker* ma = new manager(2, "李四", 1);
	ma->showInfo();
	delete ma;
	worker* bo = new boss(3, "吴伟", 2);
	bo->showInfo();
	delete bo;*/

	workerManager wm;
	while (true)
	{
		
		wm.show_Menu();
		int choice;
		cout << "请输入您的选项：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//退出系统
			wm.exitSystem();
			break;
		case 1:		//增加职工
			wm.add_Emp();
			break;
		case 2:		//显示职工
			wm.show_Emp();
			break;
		case 3:		//删除职工
			wm.Del_Emp();
			break;
		case 4:		//修改职工
			wm.Mod_emp();
			break;
		case 5:		//查询职工
			wm.Find_Emp();
			break;
		case 6:		//排序职工
			wm.Sort_Emp();
			break;
		case 7:		//清空文件
			wm.clewn_File();
			break;
		default:
			system("cls");//清屏
			break;


		}
	}
	system("pause");
	return 0;
}