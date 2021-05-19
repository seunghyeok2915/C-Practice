#pragma once
#include "Driver.h"

/*
 클래스 이름 : DriverList
 기능 : Driver 객체 리스트를 관리하는 클래스

*/
class DriverList
{
private:
	Driver* driver_info[10];	// Driver 객체 포인터배열 생성
	int drivers_array_index;	// Driver 객체 배열의 인덱스

public:
	DriverList();
	void addDriver(Driver* driver);
	void showAllDriversInfo() const;
	void showAvgDrivers() const;
	~DriverList();
};