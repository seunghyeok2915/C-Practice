#pragma once
#include "Driver.h"

/*
 Ŭ���� �̸� : TaxiDriver
 ��� : �ý� �������� �⺻�޿��� ���ʽ��� �����Ѵ�.
*/
class TaxiDriver : public Driver
{
private:
	int baseSalary;	 // �ý� �������� �⺻�޿�
	int bonusMoney; // �ý� �������� ���ʽ�

public:
	TaxiDriver(const char* driver_name, int driver_age, int driver_exp, int baseSalary, int bonusMoney);
	int Get_baseSalary() const;
	int Get_bonusMoney() const;
	virtual int getSalary() const;
	virtual void showDriverInfo() const;
};