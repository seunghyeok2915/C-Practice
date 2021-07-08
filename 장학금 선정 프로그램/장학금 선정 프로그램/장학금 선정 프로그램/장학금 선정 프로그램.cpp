#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;

class Student
{
public:
    bool isScholarship = false;
    string name; //이름
    int majorCredits = 0; //전공학점
    int liberalArtsCredits = 0; //교양학점
    float majorRating = 0; // 전공평점
    float liberalArtsRating = 0; //교양평점
    virtual string getStudentInfo() = 0;
    virtual float getGPA() = 0;
    virtual int getTuition() = 0;
};

class UndergraduateStudent : public Student
{
public:
    string clubAffiliation; // 소속동아리

    virtual string getStudentInfo()
    {
        string n = name + " " 
            + to_string(majorCredits) + " " 
            + to_string(ceil(liberalArtsCredits)) + " "
            + to_string(majorRating) + " " 
            + to_string(liberalArtsRating) + " " 
            + clubAffiliation;
        return n;
    }
    virtual float getGPA()
    {
        return (majorCredits * majorRating + liberalArtsCredits * liberalArtsRating) / 15;
    };
    virtual int getTuition()
    {
        return majorCredits * 10 + liberalArtsCredits * 6;
    };
};

class GraduateStudent : public Student
{
public:
    string affiliationLab; //소속 연구실
    string degreeProgram; //학위과정

    virtual string getStudentInfo()
    {
        string n = name + " "
            + to_string(majorCredits) + " "
            + to_string(liberalArtsCredits) + " "
            + to_string(majorRating) + " "
            + to_string(liberalArtsRating) + " "
            + affiliationLab + " "
            + degreeProgram;
        return n;
    }
    virtual float getGPA()
    {
        return (majorCredits * majorRating + liberalArtsCredits * liberalArtsRating) / 12;
    };
    virtual int getTuition()
    {
        return majorCredits * 10 + liberalArtsCredits * 6;
    };
};

bool  compare(Student* studentA, Student* studentB)
{
    return studentA->getGPA() > studentB->getGPA();
}
class ScholarshipManagement
{
    int n = 0;
    int temp = 0;
public:
    Student** studentList;
    int num_of_students;
    ScholarshipManagement(Student** student, int num_of_students)
    {
        studentList = student;
        this->num_of_students = num_of_students;
    };
    void run()
    {
        while (true)
        {
            cout << "메뉴:" << endl;
            cout << "1. 장학금 지원" << endl;
            cout << "2. 장학금 지원자 정보" << endl;
            cout << "3. 장학금 선정" << endl;
            cout << "4. 종료하기" << endl;
            cout << "* 연산을 입력하시오:";
            cin >> n;
            switch (n)
            {
            case 1:
                for (int i = 0; i < num_of_students; i++)
                {
                    cout << i + 1 << ") " << studentList[i]->getStudentInfo() << endl;
                }
                cout << "* 지원 대상 학생들의 수와 각각의 번호를 연속해서 입력하시오: ";
                do {
                    cin >> temp;
                    studentList[temp - 1]->isScholarship = true;

                } while (getc(stdin) == ' ');
                break;
            case 2:
                for (int i = 0; i < num_of_students; i++)
                {
                    if (studentList[i]->isScholarship)
                    {
                        cout << "-" << studentList[i]->getStudentInfo() << " " << studentList[i]->getGPA() << " " << studentList[i]->getTuition()<< "만원" << endl;
                    }
                }
                break;
            case 3:
                temp = 0;
                sort(studentList, studentList + 6,compare);
                for (int i = 0; i < 6; i++)
                {
                    if (studentList[i]->isScholarship)
                    {
                        if (temp >= 2)
                            break;
                        cout << "-" << studentList[i]->getStudentInfo() << " " << studentList[i]->getGPA() << " " << studentList[i]->getTuition() << "만원" << endl;
                        ++temp;
                    }
                }
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
        }
    }
};

int main()
{
    Student* students[6] = {};
    UndergraduateStudent undergraduateStudents[3] = {};
    GraduateStudent graduateStudents[3] = {};

    undergraduateStudents[0].isScholarship = false;
    undergraduateStudents[0].name = "Kim";
    undergraduateStudents[0].majorCredits = 9;
    undergraduateStudents[0].liberalArtsCredits = 6;
    undergraduateStudents[0].majorRating = 3.75f;
    undergraduateStudents[0].liberalArtsRating = 4.0f;
    undergraduateStudents[0].clubAffiliation = "FootBall";

    undergraduateStudents[1].isScholarship = false;
    undergraduateStudents[1].name = "Park";
    undergraduateStudents[1].majorCredits = 6;
    undergraduateStudents[1].liberalArtsCredits = 9;
    undergraduateStudents[1].majorRating = 3.75f;
    undergraduateStudents[1].liberalArtsRating = 3.5f;
    undergraduateStudents[1].clubAffiliation = "BaseBall";

    undergraduateStudents[2].isScholarship = false;
    undergraduateStudents[2].name = "Lee";
    undergraduateStudents[2].majorCredits = 12;
    undergraduateStudents[2].liberalArtsCredits = 3;
    undergraduateStudents[2].majorRating = 4.0f;
    undergraduateStudents[2].liberalArtsRating = 3.75f;
    undergraduateStudents[2].clubAffiliation = "VolleyBall";

    graduateStudents[0].isScholarship = false;
    graduateStudents[0].name = "Yoon";
    graduateStudents[0].majorCredits = 6;
    graduateStudents[0].liberalArtsCredits = 6;
    graduateStudents[0].majorRating = 4.0f;
    graduateStudents[0].liberalArtsRating = 3.5f;
    graduateStudents[0].affiliationLab = "Database";
    graduateStudents[0].degreeProgram = "석사";

    graduateStudents[1].isScholarship = false;
    graduateStudents[1].name = "Hong";
    graduateStudents[1].majorCredits = 9;
    graduateStudents[1].liberalArtsCredits = 3;
    graduateStudents[1].majorRating = 4.0f;
    graduateStudents[1].liberalArtsRating = 3.5f;
    graduateStudents[1].affiliationLab = "Algorithm";
    graduateStudents[1].degreeProgram = "박사";

    graduateStudents[2].isScholarship = false;
    graduateStudents[2].name = "Min";
    graduateStudents[2].majorCredits = 9;
    graduateStudents[2].liberalArtsCredits = 3;
    graduateStudents[2].majorRating = 3.5f;
    graduateStudents[2].liberalArtsRating = 3.75f;
    graduateStudents[2].affiliationLab = "OS";
    graduateStudents[2].degreeProgram = "석사";

    
     students[0] = &undergraduateStudents[0];
     students[1] = &undergraduateStudents[1];
     students[2] = &undergraduateStudents[2];
     students[3] = &graduateStudents[0];
     students[4] = &graduateStudents[1];
     students[5] = &graduateStudents[2];

    ScholarshipManagement scholarshipManagement(students, 6);
    scholarshipManagement.run();

    return 0;
}
