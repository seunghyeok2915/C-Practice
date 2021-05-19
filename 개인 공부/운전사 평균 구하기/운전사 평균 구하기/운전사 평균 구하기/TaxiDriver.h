#pragma once
#include "Driver.h"

/*
 클래스 이름 : TaxiDriver
 기능 : 택시 운전사의 기본급여와 보너스를 관리한다.
*/
class TaxiDriver : public Driver
{
private:
	int baseSalary;	 // 택시 운전사의 기본급여
	int bonusMoney; // 택시 운전사의 보너스

public:
	TaxiDriver(const char* driver_name, int driver_age, int driver_exp, int baseSalary, int bonusMoney);
	int Get_baseSalary() const;
	int Get_bonusMoney() const;
	virtual int getSalary() const;
	virtual void showDriverInfo() const;
};