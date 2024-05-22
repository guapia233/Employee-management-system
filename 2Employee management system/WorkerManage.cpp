#include"WorkerManage.h"
using namespace std;

WorkerManage::WorkerManage() {
	this->m_cnt = 0;
	this->m_Array = NULL;
}

WorkerManage::~WorkerManage() {
	if(this->m_Array != NULL) {
		delete[] this->m_Array;
	}
}

void WorkerManage::show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManage::exit() {
	cout << "欢迎您下次使用！" << endl;
}

void WorkerManage::add_Emp() {
	cout << "请输入要增加的职工数量： " << endl;

	int add_cnt = 0;
	cin >> add_cnt;

	if(add_cnt > 0) {
		//计算新空间大小
		int newSize = this->m_cnt + add_cnt;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if(this->m_Array != NULL) {
			for(int i = 0; i < this->m_cnt; i++){
				newSpace[i] = this->m_Array[i];
			}
		}

		//输入新数据
		for(int i = 0; i < add_cnt; i++) {
			int id;
			string name;
			int dept;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dept;


			Worker* worker = NULL;
			switch (dept) {
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_cnt + i] = worker;
		}

		//释放原有空间
		delete[] this->m_Array;

		//更改新空间的指向
		this->m_Array = newSpace;

		//更新新的个数
		this->m_cnt = newSize;

		//保存到文件中


		//提示信息
		cout << "成功添加" << add_cnt << "名新职工！" << endl;
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManage::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for(int i = 0; i < this->m_cnt; i++)
	{
		ofs << this->m_Array[i]->m_id << " "
			<< this->m_Array[i]->m_name << " "
			<< this->m_Array[i]->m_dept_id << endl;
	}

	ofs.close();
}
//lgp