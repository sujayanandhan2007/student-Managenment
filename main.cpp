#include <iostream>
#include "student.h"
#include "fileManager.h"

using namespace std;

int main() {

    Student s;
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "  Student Management System  \n";
        cout << "==============================\n";
        cout << " 1. Add Student\n";
        cout << " 2. Display All Students\n";
        cout << " 3. Search Student by ID\n";
        cout << " 4. Update Student\n";
        cout << " 5. Delete Student\n";
        cout << " 6. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\n--- Add Student ---\n";
                inputStudent(s);
                saveStudentToFile(s);
                break;

            case 2:
                displayAllStudents();
                break;

            case 3: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                searchStudentById(id);
                break;
            }

            case 4: {
                int id;
                cout << "Enter Student ID to update: ";
                cin >> id;
                updateStudentById(id);
                break;
            }

            case 5: {
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;

                // Confirm before deleting
                searchStudentById(id);
                cout << "\nAre you sure you want to delete this student? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                    deleteStudentById(id);
                else
                    cout << "Deletion cancelled.\n";
                break;
            }

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }

    } while (choice != 6);

    return 0;
}
