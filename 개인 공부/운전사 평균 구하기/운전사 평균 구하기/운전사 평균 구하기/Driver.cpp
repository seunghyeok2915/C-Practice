#include <iostream>
#include <cstring>
#include "Driver.h"

using namespace std;

/*
 �Լ� �̸� : Driver
 ��� : ������ (�������� �̸�, ����, ����� �ʱ�ȭ)
 ���� : ������ �̸�, ����, ���
 ��ȯ�� : ����
*/
Driver::Driver(const char* driver_name, int driver_age, int driver_exp)
{
	int arrlen = strlen(driver_name) + 1;
	this->driver_name = new char[arrlen];

	strcpy_s(this->driver_name, arrlen, driver_name);
	this->driver_age = driver_age;
	this->driver_exp = driver_exp;
}

/*
 �Լ� �̸� : Get_driver_name
 ��� : �������� �̸� ��ȯ
 ���� : ����
 ��ȯ�� : ������ �̸�
*/
char* Driver::Get_driver_name() const
{
	return driver_name;
}

/*
 �Լ� �̸� : Get_driver_age
 ��� : �������� ���� ��ȯ
 ���� : ����
 ��ȯ�� : ������ ����
*/
int Driver::Get_driver_age() const
{
	return driver_age;
}

/*
 �Լ� �̸� : Get_driver_exp
 ��� : �������� ��� ��ȯ
 ���� : ����
 ��ȯ�� : ������ ���
*/
int Driver::Get_driver_exp() const
{
	return driver_exp;
}