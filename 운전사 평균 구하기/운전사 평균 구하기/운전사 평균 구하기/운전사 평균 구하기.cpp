#include <iostream>
#include "DriverList.h"
#include "TaxiDriver.h"
#include "BusDriver.h"
#include "TruckDriver.h"

using namespace std;


int main(void)
{
	DriverList drivers;				
	Driver* pNewDriver = nullptr;	

	pNewDriver = new TaxiDriver("Kim", 33, 47, 300, 50);
	drivers.addDriver(pNewDriver);	

	pNewDriver = new TaxiDriver("Lee", 45, 67, 350, 60);
	drivers.addDriver(pNewDriver);	

	pNewDriver = new BusDriver("Park", 36, 27, 40, 5);
	drivers.addDriver(pNewDriver);	

	pNewDriver = new BusDriver("Yoo", 40, 68, 30, 6);
	drivers.addDriver(pNewDriver);	

	pNewDriver = new TruckDriver("Sung", 39, 47, 25, 12);
	drivers.addDriver(pNewDriver);	

	pNewDriver = new TruckDriver("Han", 50, 97, 33, 8);
	drivers.addDriver(pNewDriver);	

	drivers.showAllDriversInfo();
	drivers.showAvgDrivers();

	return 0;
}