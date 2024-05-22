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
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManage::exit() {
	cout << "��ӭ���´�ʹ�ã�" << endl;
}

void WorkerManage::add_Emp() {
	cout << "������Ҫ���ӵ�ְ�������� " << endl;

	int add_cnt = 0;
	cin >> add_cnt;

	if(add_cnt > 0) {
		//�����¿ռ��С
		int newSize = this->m_cnt + add_cnt;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if(this->m_Array != NULL) {
			for(int i = 0; i < this->m_cnt; i++){
				newSpace[i] = this->m_Array[i];
			}
		}

		//����������
		for(int i = 0; i < add_cnt; i++) {
			int id;
			string name;
			int dept;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dept;


			Worker* worker = NULL;
			switch (dept) {
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_cnt + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_Array;

		//�����¿ռ��ָ��
		this->m_Array = newSpace;

		//�����µĸ���
		this->m_cnt = newSize;

		//���浽�ļ���


		//��ʾ��Ϣ
		cout << "�ɹ����" << add_cnt << "����ְ����" << endl;
	}
	else {
		cout << "��������" << endl;
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