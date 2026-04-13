#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include "fileManager.h"

using namespace std;

// ─── Helper: parse a line from students.txt into a Student struct ─────────────
static bool parseLine(const string &line, Student &s) {
    // Format: id | name | age | marks | address | phone_number
    stringstream ss(line);
    string token;

    try {
        getline(ss, token, '|'); s.id = stoi(token);
        getline(ss, token, '|');
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        strncpy(s.name, token.c_str(), 49); s.name[49] = '\0';

        getline(ss, token, '|'); s.age = stoi(token);
        getline(ss, token, '|'); s.marks = stof(token);

        getline(ss, token, '|');
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        strncpy(s.address, token.c_str(), 99); s.address[99] = '\0';

        getline(ss, token);
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        strncpy(s.phone_number, token.c_str(), 14); s.phone_number[14] = '\0';

        return true;
    } catch (...) {
        return false;
    }
}

// ─── Helper: format a Student into a file line ────────────────────────────────
static string formatLine(const Student &s) {
    return to_string(s.id) + " | " +
           s.name        + " | " +
           to_string(s.age)   + " | " +
           to_string(s.marks) + " | " +
           s.address     + " | " +
           s.phone_number;
}

// ─── Helper: load all records ─────────────────────────────────────────────────
static vector<string> loadAllLines() {
    ifstream file("students.txt");
    vector<string> lines;
    string line;
    while (getline(file, line))
        if (!line.empty()) lines.push_back(line);
    return lines;
}

// ─── Helper: write all records back ──────────────────────────────────────────
static void writeAllLines(const vector<string> &lines) {
    ofstream file("students.txt", ios::trunc);
    for (const auto &l : lines)
        file << l << "\n";
}

// ─── 1. Save ──────────────────────────────────────────────────────────────────
void saveStudentToFile(const Student &s) {
    // Duplicate ID check
    vector<string> lines = loadAllLines();
    for (const auto &l : lines) {
        size_t pos = l.find('|');
        if (pos != string::npos && stoi(l.substr(0, pos)) == s.id) {
            cout << "Error: Student with ID " << s.id << " already exists!\n";
            return;
        }
    }

    ofstream file("students.txt", ios::app);
    if (!file) { cout << "Error opening file!\n"; return; }
    file << formatLine(s) << "\n";
    cout << "Student saved successfully.\n";
}

// ─── 2. Display all ───────────────────────────────────────────────────────────
void displayAllStudents() {
    vector<string> lines = loadAllLines();
    if (lines.empty()) { cout << "No students found.\n"; return; }

    cout << "\n========== All Students ==========\n";
    cout << left;
    cout.width(6);  cout << "ID";
    cout.width(20); cout << "Name";
    cout.width(6);  cout << "Age";
    cout.width(8);  cout << "Marks";
    cout.width(20); cout << "Address";
    cout << "Phone\n";
    cout << string(70, '-') << "\n";

    for (const auto &l : lines) {
        Student s;
        if (parseLine(l, s)) {
            cout.width(6);  cout << s.id;
            cout.width(20); cout << s.name;
            cout.width(6);  cout << s.age;
            cout.width(8);  cout << s.marks;
            cout.width(20); cout << s.address;
            cout << s.phone_number << "\n";
        }
    }
    cout << "==================================\n";
}

// ─── 3. Search ────────────────────────────────────────────────────────────────
void searchStudentById(int id) {
    vector<string> lines = loadAllLines();
    for (const auto &l : lines) {
        size_t pos = l.find('|');
        if (pos != string::npos && stoi(l.substr(0, pos)) == id) {
            Student s;
            parseLine(l, s);
            cout << "\n--- Student Found ---\n";
            cout << "ID           : " << s.id          << "\n";
            cout << "Name         : " << s.name         << "\n";
            cout << "Age          : " << s.age           << "\n";
            cout << "Marks        : " << s.marks         << "\n";
            cout << "Address      : " << s.address       << "\n";
            cout << "Phone Number : " << s.phone_number  << "\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

// ─── 4. Update ────────────────────────────────────────────────────────────────
void updateStudentById(int id) {
    vector<string> lines = loadAllLines();
    bool found = false;

    for (auto &l : lines) {
        size_t pos = l.find('|');
        if (pos != string::npos && stoi(l.substr(0, pos)) == id) {
            Student s;
            parseLine(l, s);

            cout << "\nCurrent record:\n";
            cout << "  Name         : " << s.name         << "\n";
            cout << "  Age          : " << s.age           << "\n";
            cout << "  Marks        : " << s.marks         << "\n";
            cout << "  Address      : " << s.address       << "\n";
            cout << "  Phone Number : " << s.phone_number  << "\n";

            cout << "\nEnter new details (press Enter to keep current value):\n";

            cin.ignore();

            // Name
            cout << "New Name [" << s.name << "]: ";
            string tmp; getline(cin, tmp);
            if (!tmp.empty()) strncpy(s.name, tmp.c_str(), 49);

            // Age
            cout << "New Age [" << s.age << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) s.age = stoi(tmp);

            // Marks
            cout << "New Marks [" << s.marks << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) s.marks = stof(tmp);

            // Address
            cout << "New Address [" << s.address << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) strncpy(s.address, tmp.c_str(), 99);

            // Phone
            cout << "New Phone Number [" << s.phone_number << "]: ";
            getline(cin, tmp);
            if (!tmp.empty()) strncpy(s.phone_number, tmp.c_str(), 14);

            l = formatLine(s);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    writeAllLines(lines);
    cout << "Student updated successfully.\n";
}

// ─── 5. Delete ────────────────────────────────────────────────────────────────
void deleteStudentById(int id) {
    vector<string> lines = loadAllLines();
    size_t before = lines.size();

    lines.erase(
        remove_if(lines.begin(), lines.end(), [&](const string &l) {
            size_t pos = l.find('|');
            return pos != string::npos && stoi(l.substr(0, pos)) == id;
        }),
        lines.end()
    );

    if (lines.size() == before) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    writeAllLines(lines);
    cout << "Student with ID " << id << " deleted successfully.\n";
}
