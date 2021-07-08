#pragma once
#include "Driver.h"

class TruckDriver : public Driver
{
private:
	int workingHours;	
	int truckWeight;		

public:
	TruckDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int payPerHour);
	int Get_workingHours() const;
	int Get_payPerHour() const;
	virtual int getSalary() const;
	virtual void showDriverInfo() const;
};
