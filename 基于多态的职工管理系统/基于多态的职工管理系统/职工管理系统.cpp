#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//���Դ���
	/*worker* work = new employee(1, "����", 1);
	work->showInfo();
	delete work;
	worker* ma = new manager(2, "����", 1);
	ma->showInfo();
	delete ma;
	worker* bo = new boss(3, "��ΰ", 2);
	bo->showInfo();
	delete bo;*/

	workerManager wm;
	while (true)
	{
		
		wm.show_Menu();
		int choice;
		cout << "����������ѡ�" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:		//����ְ��
			wm.add_Emp();
			break;
		case 2:		//��ʾְ��
			wm.show_Emp();
			break;
		case 3:		//ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:		//�޸�ְ��
			wm.Mod_emp();
			break;
		case 5:		//��ѯְ��
			wm.Find_Emp();
			break;
		case 6:		//����ְ��
			wm.Sort_Emp();
			break;
		case 7:		//����ļ�
			wm.clewn_File();
			break;
		default:
			system("cls");//����
			break;


		}
	}
	system("pause");
	return 0;
}