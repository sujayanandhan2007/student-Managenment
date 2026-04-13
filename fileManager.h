#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "student.h"

void saveStudentToFile(const Student &s);
void displayAllStudents();
void searchStudentById(int id);
void updateStudentById(int id);
void deleteStudentById(int id);

#endif
