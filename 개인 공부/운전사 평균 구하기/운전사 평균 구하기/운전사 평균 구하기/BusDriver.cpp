#include <iostream>
#include "Driver.h"
#include "BusDriver.h"

using namespace std;


BusDriver::BusDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int payPerHour)
	: Driver(driver_name, driver_age, driver_exp)
{
	this->workingHours = workingHours;
	this->payPerHour = payPerHour;
}

/*
 �Լ� �̸� : Get_workingHours
 ��� : ���� �������� �ٹ��ð� ��ȯ
 ���� : ����
 ��ȯ�� : ���� �������� �ٹ��ð�
 */
int BusDriver::Get_workingHours() const
{
	return workingHours;
}

/*
 �Լ� �̸� : Get_payPerHour
 ��� : ���� �������� �ð� �� ���� ��ȯ
 ���� : ����
 ��ȯ�� : ���� �������� �ð� �� ����
 */
int BusDriver::Get_payPerHour() const
{
	return payPerHour;
}

/*
 �Լ� �̸� : getSalary
 ��� : ���� �������� �� �޿� ��ȯ (�ٹ��ð� * �ð� �� ����)
 ���� : ����
 ��ȯ�� : ���� �������� �� �޿�
 */
int BusDriver::getSalary() const
{
	return workingHours * payPerHour;
}

/*
�Լ� �̸� : showDriverInfo
��� : ���� �������� ���� ���
���� : ����
��ȯ�� : ����
*/
void BusDriver::showDriverInfo() const
{
	cout << "�̸�: " << Get_driver_name() << ", ";
	cout << "����: " << Get_driver_age() << "��, ";
	cout << "���: " << Get_driver_exp() << "����, ";
	cout << "����: " << getSalary() << "����" << endl;
}