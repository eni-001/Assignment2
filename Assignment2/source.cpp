#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct STUDENT_DATA
{
    std::string firstName;
    std::string lastName;
};

int main()
{
    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("StudentData.txt");
    std::string line;

    while (std::getline(inputFile, line))
    {
        size_t commaPosition = line.find(',');

        if (commaPosition != std::string::npos)
        {
            STUDENT_DATA student;

            student.firstName = line.substr(0, commaPosition);
            student.lastName = line.substr(commaPosition + 1);

            students.push_back(student);
        }
    }

    inputFile.close();

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students)
    {
        std::cout << student.firstName << " "
            << student.lastName << std::endl;
    }
#endif

    return 1;
}