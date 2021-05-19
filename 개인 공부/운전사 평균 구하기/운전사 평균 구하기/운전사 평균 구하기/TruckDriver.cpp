#include <iostream>
#include "Driver.h"
#include "TruckDriver.h"

using namespace std;

TruckDriver::TruckDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int truckWeight)
	: Driver(driver_name, driver_age, driver_exp)
{
	this->workingHours = workingHours;
	this->truckWeight = truckWeight;
}

int TruckDriver::Get_workingHours() const
{
	return workingHours;
}

int TruckDriver::getSalary() const
{
	if (truckWeight >= 10)
	{
		return workingHours * 10;
	}
	else
	{
		return workingHours * 8;
	}
	return workingHours * 8;
}

void TruckDriver::showDriverInfo() const
{
	cout << "이름: " << Get_driver_name() << ", ";
	cout << "나이: " << Get_driver_age() << "세, ";
	cout << "경력: " << Get_driver_exp() << "개월, ";
	cout << "월급: " << getSalary() << "만원" << endl;
}