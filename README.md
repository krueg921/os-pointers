# os-pointers
C / C++ Pointers

/*
typedef struct Student defines a student with the characteristcs of a id, first name, last name, number of assignments, and a total of the grades.

int promptInt(std::string message, int min, int max) takes in a message, a minimum value, a maximum value and asks the user the message and returns that value as an int provided that it is within the min and max

double promptDouble(std::string message, double min, double max) takes in a message, a minimum value, a maximum value and asks the user the message and returns that value as double provided that it is within the min and max

void calculateStudentAverage(void *object, double *avg) calculates the student average given a pointer to anything and a pointer to a double.  The object pointer I assigned to the number of assignments eventually and avg I assigned to the grades pointer in student

int main(int argc, char **argv) in main I use the functions from above to prompt the user for an, id number, names, and how many assignments were graded.  At the end a summary is printed out and the average grade is displayed.  
*/