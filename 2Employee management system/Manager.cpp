#include"Manager.h"

Manager::Manager(int id, string name, int dept_id) {
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Manager::showInfo() {
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}
string Manager::getDeptName() {
	return string("����");
}