#pragma once
#include "Driver.h"

/*
 Ŭ���� �̸� : BusDriver
 ��� : ���� �������� �ٹ��ð��� �ð� �� ������ �����Ѵ�.
*/
class BusDriver : public Driver
{
private:
	int workingHours;	// ���� �������� �ٹ��ð�
	int payPerHour;		// ���� �������� �ð� �� ����

public:
	BusDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int payPerHour);
	int Get_workingHours() const;
	int Get_payPerHour() const;
	virtual int getSalary() const;
	virtual void showDriverInfo() const;
};
