#include <iostream>
#include "DriverList.h"

using namespace std;

/*
 �Լ� �̸� : DriverList
 ��� : ������ (�迭�� �ε��� ��ȣ 0���� �ʱ�ȭ)
 ���� : ����
 ��ȯ�� : ����
*/
DriverList::DriverList()
{
	drivers_array_index = 0;
}

/*
 �Լ� �̸� : addDriver
 ��� : main �Լ��κ��� Driver ��ü�� �Ѱܹ޾� driver_info �迭�� �߰��Ѵ�.
 ���� : Driver ��ü�� �ּ�
 ��ȯ�� : ����
*/
void DriverList::addDriver(Driver* driver)
{
	driver_info[drivers_array_index++] = driver;
}

/*
 �Լ� �̸� :showAllDriversInfo
 ��� : driver_info�� ����� Driver������ ����Ѵ�.(���� ���ε��̱� ������ ���� ������ִ� ���� Bus, Taxi�� �����̴�)
 ���� : ����
 ��ȯ�� : ����
*/
void DriverList::showAllDriversInfo() const
{
	cout << "������ ���� =>" << endl;

	for (int i = 0; i < drivers_array_index; i++)
	{
		driver_info[i]->showDriverInfo();
	}
}
/*
 �Լ� �̸� : ~DriverList
 ��� : �Ҹ���
 ���� : ����
 ��ȯ�� : ����
*/
void DriverList::showAvgDrivers() const {
	double avgAge = 0.0;
	double avgExp = 0.0;
	double avgSalary = 0.0;
	cout << "������ ��� ���� =>\n";
	cout << drivers_array_index;
	for (int i = 0; i < drivers_array_index; i++) {
		avgAge += driver_info[i]->Get_driver_age();
		avgExp += driver_info[i]->Get_driver_exp();
		avgSalary += driver_info[i]->getSalary();
	}
	avgAge /= 6;
	avgExp /= 6;
	avgSalary /= 6;
	cout << fixed;
	cout.precision(1);
	cout << "��� ���� : " << avgAge << "��\n";
	cout.precision(2);
	cout << "��� ��� : " << avgExp << "����\n";
	cout.precision(0);
	cout << "�������� ��� ���� : " << avgSalary << "����\n";
}

DriverList::~DriverList()
{
	for (int i = 0; i < drivers_array_index; i++)
	{
		delete[] driver_info[i];	// �����Ҵ���� �迭�� �����Ѵ�.
	}
}