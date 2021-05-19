#include <iostream>
#include "DriverList.h"

using namespace std;

/*
 함수 이름 : DriverList
 기능 : 생성자 (배열의 인덱스 번호 0으로 초기화)
 인자 : 없음
 반환값 : 없음
*/
DriverList::DriverList()
{
	drivers_array_index = 0;
}

/*
 함수 이름 : addDriver
 기능 : main 함수로부터 Driver 객체를 넘겨받아 driver_info 배열에 추가한다.
 인자 : Driver 객체의 주소
 반환값 : 없음
*/
void DriverList::addDriver(Driver* driver)
{
	driver_info[drivers_array_index++] = driver;
}

/*
 함수 이름 :showAllDriversInfo
 기능 : driver_info에 저장된 Driver정보을 출력한다.(동적 바인딩이기 때문에 실제 저장돼있는 값은 Bus, Taxi의 정보이다)
 인자 : 없음
 반환값 : 없음
*/
void DriverList::showAllDriversInfo() const
{
	cout << "운전사 정보 =>" << endl;

	for (int i = 0; i < drivers_array_index; i++)
	{
		driver_info[i]->showDriverInfo();
	}
}
/*
 함수 이름 : ~DriverList
 기능 : 소멸자
 인자 : 없음
 반환값 : 없음
*/
void DriverList::showAvgDrivers() const {
	double avgAge = 0.0;
	double avgExp = 0.0;
	double avgSalary = 0.0;
	cout << "운전사 통계 정보 =>\n";
	cout << drivers_array_index;
	for (int i = 0; i < drivers_array_index; i++) {
		avgAge += driver_info[i]->Get_driver_age();
		avgExp += driver_info[i]->Get_driver_exp();
		avgSalary += driver_info[i]->getSalary();
	}
	avgAge /= 6;
	avgExp /= 6;
	avgSalary /= 6;
	cout << fixed;
	cout.precision(1);
	cout << "평균 나이 : " << avgAge << "세\n";
	cout.precision(2);
	cout << "평균 경력 : " << avgExp << "개월\n";
	cout.precision(0);
	cout << "운전사의 평균 월급 : " << avgSalary << "만원\n";
}

DriverList::~DriverList()
{
	for (int i = 0; i < drivers_array_index; i++)
	{
		delete[] driver_info[i];	// 동적할당받은 배열을 해제한다.
	}
}