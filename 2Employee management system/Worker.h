#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	//´¿Ðéº¯Êý
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_id;
	string m_name;
	int m_dept_id;
};