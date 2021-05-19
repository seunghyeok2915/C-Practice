#pragma once
/*
 클래스 이름 : Driver
 기능 : 운전사 정보에 대한 아래의 기능을 구현함
		(추상클래스이며 getSalary와 showDriverInfo는 Bus, TaxiDriver 클래스에서 구현할 것이다.)
*/
class Driver
{
private:
	char* driver_name;	// 운전사 이름
	int driver_age;		// 운전사 나이
	int driver_exp;		// 운전사 경력

public:
	Driver(const char* driver_name, int driver_age, int driver_exp);
	char* Get_driver_name() const;
	int Get_driver_age() const;
	int Get_driver_exp() const;
	virtual int getSalary() const = 0;
	virtual void showDriverInfo() const = 0;
};