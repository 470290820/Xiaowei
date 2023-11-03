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
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;//���Դ���
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;//���Դ���
		this->m_empNum = 0;
		this->m_empArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_empNum();
	//cout << "ְ������Ϊ��" << num << endl;//���Դ���
	this->m_empNum = num;
	//���ٿռ�
	this->m_empArray = new worker * [this->m_empNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	//����
	/*for (int i = 0; i < this->m_empNum; i++)
	{
		cout << "ְ����ţ�" << this->m_empArray[i]->m_id
			<< "ְ��������" << this->m_empArray[i]->m_name
			<< "ְ��ְλ��" << this->m_empArray[i]->m_deptno << endl;
	}*/


}
//չʾ�˵�
void workerManager::show_Menu()
{
	cout << "**********************************************************" << endl;
	cout << "	********** ��ӭ��ʹ��ְ������ϵͳ **********" << endl;
	cout << "	************** 0���˳�����ϵͳ *************" << endl;
	cout << "	************** 1������ְ����Ϣ *************" << endl;
	cout << "	************** 2����ʾְ��ְ�� *************" << endl;
	cout << "	************** 3��ɾ����ְְ�� *************" << endl;
	cout << "	************** 4���޸�ְ����Ϣ *************" << endl;
	cout << "	************** 5������ְ����Ϣ *************" << endl;
	cout << "	************** 6�����ձ������ *************" << endl;
	cout << "	************** 7����������ĵ� *************" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ�����������������ܺ�Ϊ0
void workerManager::exitSystem()
{
	cout << "���˳�ϵͳ����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
//����ְ��-----���ܺ�Ϊ1
void workerManager::add_Emp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_empNum + addNum;

		//�����¿ռ�
		worker** newSpace = new worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				newSpace[i] = this->m_empArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << "����ְ����ţ�" << endl;
			
			while (true)
			{
				int flag = true;
				cin >> id;
				for (int i = 0; i < this->m_empNum; i++)
				{
					if (this->m_empArray[i]->m_id == id)
					{
						cout << "�ñ���Ѵ��ڣ����������룺" << endl;
						flag = false;
						break;
					}
				}
				if (flag == true) break;
			}
			

			cout << "������� " << i + 1 << "����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			worker* work = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				work = new employee(id, name, 1);
				break;
			case 2: //����
				work = new manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				work = new boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_empNum + i] = work;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_empArray;

		//�����¿ռ��ָ��
		this->m_empArray = newSpace;

		//�����µĸ���
		this->m_empNum = newSize;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		//�ļ���ǰ��Ϊ��
		this->m_FileIsEmpty = false;
		//���µ��ļ���
		this->save();


	}
	else
	{
		cout << "��������" << endl;
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

//��ʾְ����Ϣ---���ܺ�Ϊ2
void workerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�����" << endl;
	}
	else {
		for (int i = 0; i < m_empNum; i++)
		{
			this->m_empArray[i]->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}


//ɾ��ְ��-----���ܺ�Ϊ3
void workerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//˵��ְ�����ڣ�����ɾ����λ��Ϊindex
		{
			for (int i = index; i < this->m_empNum - 1; i++)
			{
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_empNum--;
			//ͬ�����µ��ļ�
			this->save();
			cout << "ɾ���ɹ���" << endl;
			//ɾ���ɹ������������
			system("pause");
			system("cls");
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�û�и�ְ����" << endl;
		}
	}
}

//�޸�ְ����Ϣ---���ܺ�Ϊ4
void workerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int index = 0;
		cin >> index;
		int ret = this->IsExist(index);
		if (ret != -1)//ְ������
		{
			delete[] this->m_empArray[ret];
			int newid;
			string newname;
			int newdeptno;
			cout << "��ѯ��Ա�����Ϊ" << index << "��ְ����Ϣ��" << endl;
			this->m_empArray[index]->showInfo();
			cout << "�����������µ�Ա����ţ�" << endl;
			cin >> newid;
			cout << "�����������µ�Ա��������" << endl;
			cin >> newname;
			cout << "������ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ���" << this->m_empArray[ret]->m_deptno << endl;
			this->save();

		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}

	system("pause");
	system("cls");
}


//��ѯԱ��---���ܺ�Ϊ5
void workerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ:" << endl;
		cout << "1�����ձ�Ų���" << endl;
		cout << "2��������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�Ա����ţ�" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���ְ�����Ϊ��" << id << "����Ϣ���£�" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else {
				cout << "���޴��ˣ�" << endl;
			}

		}
		else
		{
			string name;
			cout << "���������Ա����������" << endl;
			cin >> name;
			int flag = false;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ������Ϊ��" << name << "����Ϣ���£�" << endl;

					this->m_empArray[i]->showInfo();
					flag = true;
				}

			}
			if (flag == false)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}

	}
	system("pause");
	system("cls");
}
//���ձ������--���ܺ�Ϊ6
void workerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empNum; i++)
		{
			int minOrMax = i; //������Сֵ �� ���ֵ�±�
			for (int j = i + 1; j < this->m_empNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_empArray[minOrMax]->m_id > this->m_empArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (this->m_empArray[minOrMax]->m_id < this->m_empArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ��������� ��������
			if (i != minOrMax)
			{
				worker* temp = this->m_empArray[i];
				this->m_empArray[i] = this->m_empArray[minOrMax];
				this->m_empArray[minOrMax] = temp;
			}

		}

		cout << "����ɹ��������Ľ��Ϊ�� " << endl;
		this->save(); //����������浽�ļ���
		this->show_Emp();//չʾ����ְ��
	}

}
//����ĵ�-----���ܺ�Ϊ7
void workerManager::clewn_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
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
		cout << "��ճɹ���" << endl;
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
//�����ļ�
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





//ͳ��Ա������
int workerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�  ��

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ����������
		num++;
	}

	return num;

}
//�ж�ְ���Ƿ����
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


