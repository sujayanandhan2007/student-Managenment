#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
    char address[100];
    char phone_number[15];   // NOT int
};

void inputStudent(Student &s);
void displayStudent(const Student &s);

#endif
