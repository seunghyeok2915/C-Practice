#include <iostream>
#include "Driver.h"
#include "BusDriver.h"

using namespace std;


BusDriver::BusDriver(const char* driver_name, int driver_age, int driver_exp, int workingHours, int payPerHour)
	: Driver(driver_name, driver_age, driver_exp)
{
	this->workingHours = workingHours;
	this->payPerHour = payPerHour;
}

/*
 함수 이름 : Get_workingHours
 기능 : 버스 운전사의 근무시간 반환
 인자 : 없음
 반환값 : 버스 운전사의 근무시간
 */
int BusDriver::Get_workingHours() const
{
	return workingHours;
}

/*
 함수 이름 : Get_payPerHour
 기능 : 버스 운전사의 시간 당 보수 반환
 인자 : 없음
 반환값 : 버스 운전사의 시간 당 보수
 */
int BusDriver::Get_payPerHour() const
{
	return payPerHour;
}

/*
 함수 이름 : getSalary
 기능 : 버스 운전사의 총 급여 반환 (근무시간 * 시간 당 보수)
 인자 : 없음
 반환값 : 버스 운전사의 총 급여
 */
int BusDriver::getSalary() const
{
	return workingHours * payPerHour;
}

/*
함수 이름 : showDriverInfo
기능 : 버스 운전사의 정보 출력
인자 : 없음
반환값 : 없음
*/
void BusDriver::showDriverInfo() const
{
	cout << "이름: " << Get_driver_name() << ", ";
	cout << "나이: " << Get_driver_age() << "세, ";
	cout << "경력: " << Get_driver_exp() << "개월, ";
	cout << "월급: " << getSalary() << "만원" << endl;
}