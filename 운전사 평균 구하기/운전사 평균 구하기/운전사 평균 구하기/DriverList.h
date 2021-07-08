#pragma once
#include "Driver.h"

/*
 Ŭ���� �̸� : DriverList
 ��� : Driver ��ü ����Ʈ�� �����ϴ� Ŭ����

*/
class DriverList
{
private:
	Driver* driver_info[10];	// Driver ��ü �����͹迭 ����
	int drivers_array_index;	// Driver ��ü �迭�� �ε���

public:
	DriverList();
	void addDriver(Driver* driver);
	void showAllDriversInfo() const;
	void showAvgDrivers() const;
	~DriverList();
};