#pragma once
#include "Driver.h"

/*
 클래스 이름 : BusDriver
 기능 : 버스 운전사의 근무시간과 시간 당 보수를 관리한다.
*/
class BusDriver : public Driver
{
private:
	int workingHours;	// 버스 운전사의 근무시간
	int payPerHour;		// 버스 운전사의 시간 당 보수

public:
	BusDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int payPerHour);
	int Get_workingHours() const;
	int Get_payPerHour() const;
	virtual int getSalary() const;
	virtual void showDriverInfo() const;
};
