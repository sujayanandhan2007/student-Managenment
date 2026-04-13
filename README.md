# Student Management System

A simple console-based Student Management System written in C++. This was built as a mini project to practice file handling, structs, and modular programming in C++.

It lets you add students, view all of them, search by ID, update their details, and delete records — all stored in a plain text file so the data sticks around even after you close the program.

---

## What it can do

- **Add a student** — enter ID, name, age, marks, address, and phone number
- **Display all students** — shows everyone in a clean formatted table
- **Search by ID** — quickly find a specific student
- **Update a student** — change any field; just press Enter to keep the current value
- **Delete a student** — shows the record first and asks for confirmation before deleting

---

## Project Structure

```
student_management_system/
├── main.cpp          # Entry point, menu loop
├── student.h         # Student struct definition
├── student.cpp       # Input and display functions
├── fileManager.h     # File operation declarations
├── fileManager.cpp   # Save, search, update, delete logic
├── students.txt      # Where student records are stored
└── Makefile          # For easy compilation
```

---

## How to Compile and Run

**Using Make:**
```bash
make
./student_management
```

**Or manually with g++:**
```bash
g++ -std=c++17 -Wall -o student_management main.cpp student.cpp fileManager.cpp
./student_management
```

> Requires g++ with C++17 support. Works on Linux and macOS. On Windows, use MinGW or WSL.

---

## How data is stored

All student records are saved in `students.txt` in this format:

```
101 | Sujay | 18 | 95.5 | Chennai | 9876543210
```

The file is created automatically when you add your first student. Don't delete it or the records will be gone — but the program will just create a fresh one if it's missing.

---

## Example Usage

```
==============================
  Student Management System  
==============================
 1. Add Student
 2. Display All Students
 3. Search Student by ID
 4. Update Student
 5. Delete Student
 6. Exit
==============================
Enter your choice: 1

--- Add Student ---
Enter Student ID: 102
Enter Student Name: Arjun
Enter Age: 19
Enter Marks: 88.5
Enter Address: Madurai
Enter Phone Number: 9876500001
Student saved successfully.
```

---

## Things to keep in mind

- Student IDs must be unique — the program won't let you add a duplicate
- Phone number field holds up to 14 characters
- Name field holds up to 49 characters
- Address field holds up to 99 characters

---

## Built with

- C++ (C++17)
- Standard file I/O (`fstream`)
- No external libraries needed

---

Made by Sujay
