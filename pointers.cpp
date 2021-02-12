// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <math.h>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    std::string out;
    int i;

    student.f_name = new char[128];
    student.l_name = new char[128];
    student.grades = new double[1000];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    std::cout << "Please enter the studnet's first name: ";
    std::cin.getline(student.f_name, 128);
    std::cout << "Please enter the student's last name: ";
    std::cin.ignore();
    std::cin.getline(student.l_name, 128);
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    for(i = 0; i < student.n_assignments; i++)
    {
        std::string message;
        std::string hold;
        double result;
        message = "Please enter grade for assignment ";
        hold = std::to_string(i + 1);
        message.append(hold);
        message.append(": ");
        result = promptDouble(message, 0, 1000);
        *student.grades += result;
    }

    // Call `CalculateStudentAverage(???, ???)`
    int *numGradesPointer;
    void *voidPointer;
    numGradesPointer = &student.n_assignments;

    calculateStudentAverage(numGradesPointer, student.grades);

    // Output `average`
    average = *student.grades;

    //round average
    average = floor(average * 10 + .5) / 10;

    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
    std::cout << "\tAverage grade: " << average << "\n"; 
    
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int result = 0;
    char *tempResult;
    tempResult = new char[128];
    std::cout << message;
    std::cin.getline(tempResult, max);
    result = atoi(tempResult);
    while(result < min || result > max)
    {
        std::cout << "Sorry, I cannot understand your answer\n";
        std::cout << message;
        std::cin.ignore();
        std::cin.getline(tempResult, max);
        result = atoi(tempResult);
    }
    
    return result;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double result = 0.0;
    char *tempResult;
    tempResult = new char[128];
    std::cout << message;
    std::cin.getline(tempResult, max);
    result = std::stod(tempResult);
    while(result < min || result > max)
    {
        std::cout << "Sorry, I cannot understand your answer\n";
        std::cout << message;
        std::cin.ignore();
        std::cin.getline(tempResult, max);
        result = std::stod(tempResult);
    }
    
    return result;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    // Get the *grades double and divide that by n_assignments both from student
    // reassign *grades to the average as that is the only one that is a double which the answer must be
    int numGrades = 0;
    double average = 0;

    int *voidInt = (int*)object;

    average = *avg / *voidInt;

    *avg = average;

    return;
}