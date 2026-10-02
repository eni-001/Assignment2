#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct STUDENT_DATA
{
    std::string firstName;
    std::string lastName;

#ifdef PRE_RELEASE
    std::string email;
#endif
};

int main()
{
    std::vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    std::cout << "Running pre-release version." << std::endl;
    std::ifstream inputFile("StudentData_Emails.txt");
#else
    std::cout << "Running standard version." << std::endl;
    std::ifstream inputFile("StudentData.txt");
#endif

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::stringstream stream(line);
        STUDENT_DATA student;

        std::getline(stream, student.firstName, ',');
        std::getline(stream, student.lastName, ',');

#ifdef PRE_RELEASE
        std::getline(stream, student.email);
#endif

        students.push_back(student);
    }

    inputFile.close();

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students)
    {
        std::cout << student.firstName << " "
            << student.lastName;

#ifdef PRE_RELEASE
        std::cout << " " << student.email;
#endif

        std::cout << std::endl;
    }
#endif

    return 1;
}