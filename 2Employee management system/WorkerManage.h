#pragma once
#include<iostream>
#include <fstream>
#define  FILENAME "empFile.txt"

#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

class WorkerManage {
public:
	WorkerManage();
	~WorkerManage();

	void show_Menu();
	void exit();
	void add_Emp();
	void save();
private:
	int m_cnt;
	Worker** m_Array;
};


