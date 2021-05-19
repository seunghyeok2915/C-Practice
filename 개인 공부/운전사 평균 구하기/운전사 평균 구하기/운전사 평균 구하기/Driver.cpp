#include <iostream>
#include <cstring>
#include "Driver.h"

using namespace std;

/*
 함수 이름 : Driver
 기능 : 생성자 (운전사의 이름, 나이, 경력을 초기화)
 인자 : 운전사 이름, 나이, 경력
 반환값 : 없음
*/
Driver::Driver(const char* driver_name, int driver_age, int driver_exp)
{
	int arrlen = strlen(driver_name) + 1;
	this->driver_name = new char[arrlen];

	strcpy_s(this->driver_name, arrlen, driver_name);
	this->driver_age = driver_age;
	this->driver_exp = driver_exp;
}

/*
 함수 이름 : Get_driver_name
 기능 : 운전사의 이름 반환
 인자 : 없음
 반환값 : 운전사 이름
*/
char* Driver::Get_driver_name() const
{
	return driver_name;
}

/*
 함수 이름 : Get_driver_age
 기능 : 운전사의 나이 반환
 인자 : 없음
 반환값 : 운전사 나이
*/
int Driver::Get_driver_age() const
{
	return driver_age;
}

/*
 함수 이름 : Get_driver_exp
 기능 : 운전사의 경력 반환
 인자 : 없음
 반환값 : 운전사 경력
*/
int Driver::Get_driver_exp() const
{
	return driver_exp;
}