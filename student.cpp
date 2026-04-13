#include <iostream>
#include "student.h"

using namespace std;

void inputStudent(Student &s) {

    cout << "Enter Student ID: ";
    cin >> s.id;

    cin.ignore();

    cout << "Enter Student Name: ";
    cin.getline(s.name, 50);

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Marks: ";
    cin >> s.marks;

    cin.ignore();

    cout << "Enter Address: ";
    cin.getline(s.address, 100);

    cout << "Enter Phone Number: ";
    cin.getline(s.phone_number, 15);
}

void displayStudent(const Student &s) {

    cout << "\nStudent Details:\n";
    cout << "ID           : " << s.id           << endl;
    cout << "Name         : " << s.name          << endl;
    cout << "Age          : " << s.age            << endl;
    cout << "Marks        : " << s.marks          << endl;
    cout << "Address      : " << s.address        << endl;
    cout << "Phone Number : " << s.phone_number   << endl;
}
