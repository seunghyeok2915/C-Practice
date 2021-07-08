#include <iostream>

using namespace std;
int main()
{
    char identity[14];

    string gender;
    int age = 0;
    int birthYear;

    bool isIdentyPosible = false;
    string IdentyPosiblity;

    int birthAreaCode = 0;
    string birthArea;

    cin >> identity;

    if (identity[6] % 2 == 1)
    {
        gender = "남자";
    }
    else
    {
        gender = "여자";
    }

   
    birthYear = (identity[0] - 48) * 10 + identity[1] - 48;
    if (birthYear >= 22)
    {
        birthYear += 1900;
    }
    else
    {
        birthYear += 2000;
    }

    age = 2021 - birthYear;

    birthAreaCode = (identity[7] - 48) * 10 + identity[8] - 48;

    if (birthAreaCode <= 8)
    {
        birthArea = "서울";
    }
    else if (birthAreaCode <= 12)
    {
        birthArea = "부산";
    }
    else if (birthAreaCode <= 15)
    {
        birthArea = "인천";
    }
    else if (birthAreaCode <= 18)
    {
        birthArea = "경기도 주요 도시";
    }
    else if (birthAreaCode <= 25)
    {
        birthArea = "그밖의 경기도";
    }
    else if (birthAreaCode <= 34)
    {
        birthArea = "강원도";
    }
    else if (birthAreaCode <= 39)
    {
        birthArea = "충청북도";
    }
    else if (birthAreaCode <= 47)
    {
        birthArea = "충청남도";
    }
    else if (birthAreaCode <= 54)
    {
        birthArea = "전라북도";
    }   
    else if (birthAreaCode <= 66)
    {
        birthArea = "전라남도";
    }
    else if (birthAreaCode <= 90)
    {
        birthArea = "경상도";
    }
    if (identity[12] - 48 == (11 - (((identity[0] - 48) * 2 + (identity[1] - 48) * 3 + (identity[2] - 48) * 4 + (identity[3] - 48) * 5 + (identity[4] - 48) * 6 + (identity[5] - 48) * 7 + (identity[6] - 48) * 8 + (identity[7] - 48) * 9 + (identity[8] - 48) * 2 + (identity[9] - 48) * 3 + (identity[10] - 48) * 4 + (identity[11] - 48) * 5) % 11)) % 10)
    {
        IdentyPosiblity = "유효";
    }
    else
    {
        IdentyPosiblity = "가짜";
    }
    cout << "성별" << gender << "나이" << age << "출생연도" << birthYear << "출생지역" << birthArea << "주민등록번호유효성" << IdentyPosiblity;
    



}