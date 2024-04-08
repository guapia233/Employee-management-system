#include<iostream>
using namespace std;
#include"WorkerManage.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

void test01() {
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	/*worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;*/
}

int main() {
	test01();

	/*WorkerManage wm;
	wm.show_Menu();

	int choice = 0;
	cout << "请输入你的选项：";
	cin >> choice;
	switch (choice) {
		case 0: 
			wm.exit();
			return 0;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		default:
			system("cls");
			break;
	}

	system("pause");
	*/
	return 0;
}
