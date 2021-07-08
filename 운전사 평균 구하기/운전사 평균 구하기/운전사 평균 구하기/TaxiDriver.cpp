#include <iostream>
#include "Driver.h"
#include "TaxiDriver.h"

using namespace std;

/*
 �Լ� �̸� : TaxiDriver
 ��� : ������ (������� Driver �����ڸ� ���� �ý� �������� �̸�, ����, ����� �ʱ�ȭ�ϰ� �⺻�޿��� ���ʽ��� TaxiDriver �����ڷ� �ʱ�ȭ�Ѵ�.)
 ���� : ������ �̸�, ����, ���, �⺻�޿�, ���ʽ�
 ��ȯ�� : ����
 */
TaxiDriver::TaxiDriver(const char* driver_name, int driver_age, int driver_exp, int baseSalary, int bonusMoney) : Driver(driver_name, driver_age, driver_exp)
{
	this->baseSalary = baseSalary;
	this->bonusMoney = bonusMoney;
}

/*
 �Լ� �̸� : Get_baseSalary
 ��� : �ý� �������� �⺻�޿� ��ȯ
 ���� : ����
 ��ȯ�� : �ý� �������� �⺻�޿�
 */
int TaxiDriver::Get_baseSalary() const
{
	return baseSalary;
}

/*
 �Լ� �̸� : Get_bonusMoney
 ��� : �ý� �������� ���ʽ� ��ȯ
 ���� : ����
 ��ȯ�� : �ý� �������� ���ʽ�
 */
int TaxiDriver::Get_bonusMoney() const
{
	return bonusMoney;
}

/*
 �Լ� �̸� : GetSalary
 ��� : �ý� �������� �� �޿� ��ȯ (�⺻�޿� + ���ʽ�)
 ���� : ����
 ��ȯ�� : �ý� �������� �� �޿�
 */
int TaxiDriver::getSalary() const
{
	return baseSalary + bonusMoney;
}

/*
 �Լ� �̸� : ShowDriverinfo
 ��� : �ý� �������� ���� ���
 ���� : ����
 ��ȯ�� : ����
 */
void TaxiDriver::showDriverInfo() const
{
	cout << "�̸�: " << Get_driver_name() << ", ";
	cout << "����: " << Get_driver_age() << "��, ";
	cout << "���: " << Get_driver_exp() << "����, ";
	cout << "����: " << getSalary() << "����" << endl;
}
