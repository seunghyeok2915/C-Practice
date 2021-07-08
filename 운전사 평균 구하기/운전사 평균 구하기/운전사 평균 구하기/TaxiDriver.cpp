#include <iostream>
#include "Driver.h"
#include "TaxiDriver.h"

using namespace std;

/*
 함수 이름 : TaxiDriver
 기능 : 생성자 (상속으로 Driver 생성자를 통해 택시 운전사의 이름, 나이, 경력을 초기화하고 기본급여와 보너스는 TaxiDriver 생성자로 초기화한다.)
 인자 : 운전사 이름, 나이, 경력, 기본급여, 보너스
 반환값 : 없음
 */
TaxiDriver::TaxiDriver(const char* driver_name, int driver_age, int driver_exp, int baseSalary, int bonusMoney) : Driver(driver_name, driver_age, driver_exp)
{
	this->baseSalary = baseSalary;
	this->bonusMoney = bonusMoney;
}

/*
 함수 이름 : Get_baseSalary
 기능 : 택시 운전사의 기본급여 반환
 인자 : 없음
 반환값 : 택시 운전사의 기본급여
 */
int TaxiDriver::Get_baseSalary() const
{
	return baseSalary;
}

/*
 함수 이름 : Get_bonusMoney
 기능 : 택시 운전사의 보너스 반환
 인자 : 없음
 반환값 : 택시 운전사의 보너스
 */
int TaxiDriver::Get_bonusMoney() const
{
	return bonusMoney;
}

/*
 함수 이름 : GetSalary
 기능 : 택시 운전사의 총 급여 반환 (기본급여 + 보너스)
 인자 : 없음
 반환값 : 택시 운전사의 총 급여
 */
int TaxiDriver::getSalary() const
{
	return baseSalary + bonusMoney;
}

/*
 함수 이름 : ShowDriverinfo
 기능 : 택시 운전사의 정보 출력
 인자 : 없음
 반환값 : 없음
 */
void TaxiDriver::showDriverInfo() const
{
	cout << "이름: " << Get_driver_name() << ", ";
	cout << "나이: " << Get_driver_age() << "세, ";
	cout << "경력: " << Get_driver_exp() << "개월, ";
	cout << "월급: " << getSalary() << "만원" << endl;
}
