#pragma once	//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
using namespace std;


class workerManager
{
public:
	workerManager();
	~workerManager();
	//��ʼ��Ա��
	void init_Emp();
	//չʾ�˵�
	void show_Menu();
	//�˳�ϵͳ
	void exitSystem();
	//���ְ��
	void add_Emp();
	//���浽�ļ�
	void save();
	//��ʾְ����Ϣ-------���ܺ�Ϊ2
	void show_Emp();
	//ͳ������
	int get_empNum();
	//ɾ��ְ��,���ձ��ɾ��
	void Del_Emp();
	//��ѯְ��    ���ܺ�Ϊ5
	void Find_Emp();
	//���ձ������
	void Sort_Emp();
	//����ĵ�
	void clewn_File();

	//�ж�ְ���Ƿ����
	int IsExist(int id);
	//ְ����Ϣ�޸�
	void Mod_emp();
	//��¼ְ������
	int m_empNum;	
	//ְ�������ָ��
	worker** m_empArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};
