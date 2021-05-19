#pragma once
/*
 Ŭ���� �̸� : Driver
 ��� : ������ ������ ���� �Ʒ��� ����� ������
		(�߻�Ŭ�����̸� getSalary�� showDriverInfo�� Bus, TaxiDriver Ŭ�������� ������ ���̴�.)
*/
class Driver
{
private:
	char* driver_name;	// ������ �̸�
	int driver_age;		// ������ ����
	int driver_exp;		// ������ ���

public:
	Driver(const char* driver_name, int driver_age, int driver_exp);
	char* Get_driver_name() const;
	int Get_driver_age() const;
	int Get_driver_exp() const;
	virtual int getSalary() const = 0;
	virtual void showDriverInfo() const = 0;
};