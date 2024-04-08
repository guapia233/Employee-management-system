#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Employee :public Worker {
public:
	Employee(int id, string name, int dept_id); //¹¹Ôìº¯Êý
	virtual void showInfo();
	virtual string getDeptName();
};