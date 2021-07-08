#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;


int main() 
{
	char print_temp[256];
	FILE* rfp;
	rfp = fopen("test.tmg", "rt");
	system("mode con cols=130");

	if (rfp == NULL)
	{
		cout << "파일읽기 실패";
		return 0;
	}

	while (fgets(print_temp, 255, rfp) != NULL)
	{
		cout << print_temp;
	}
	puts("");
	fclose(rfp);
	return 0;
	
}