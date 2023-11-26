#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct studentInfo {
    int id;
    string name;
    string major;
    double gpa;
    bool isOccupied;
    bool isPreviouslyOccupied;
};

class Student {
private:
    vector<studentInfo> hashTable;
    int tableSize;
    int numElements;

    int hashFunction(int id) {
        return id % tableSize;
    }

public:
    Student()  {
        numElements = 0;
    }

    void readDataFile(const string& fileName, int numRecords) {
        ifstream file(fileName);
        string line;
        if (!file) {
            cout << "ERROR: File, " << fileName << ", not found.\n";
            return;
        }

        tableSize = 40; 
        hashTable.resize(tableSize);
        while (getline(file, line) && numElements < numRecords) {
            stringstream content(line);
            studentInfo student;
            char delim;
            content >> student.id >> delim;
            getline(content, student.name, ',');
            getline(content, student.major, ',');
            content >> student.gpa;

            insert(student);
        }
    }

    void insert(const studentInfo& student) {
        if (numElements >= 40) {
            cout << "ERROR: Hash table is full. Cannot insert new student." << endl;
            return;
        }

        int index = hashFunction(student.id);

        hashTable[index] = student;
        hashTable[index].isOccupied = true;
        hashTable[index].isPreviouslyOccupied = true;
        numElements++;
    }


    bool search(int id) {
        int index = hashFunction(id);
        int originalIndex = index;

        do {
            if (hashTable[index].isOccupied && hashTable[index].id == id) {
                return true;
            }
            else if (!hashTable[index].isPreviouslyOccupied) {
                return false;
            }

            index = (index + 1) % tableSize;
        } while (index != originalIndex);

        return false;
    }

    void getStudentInfo(int id) {
        int index = hashFunction(id);
        int originalIndex = index;

        do {
            if (hashTable[index].isOccupied && hashTable[index].id == id) {
                
                const studentInfo& foundStudent = hashTable[index];
                cout << "\n\tStudent record found at index #" << index;
                cout << "\n\tStudentID    : " << foundStudent.id;
                cout << "\n\tName         : " << foundStudent.name;
                cout << "\n\tMajor        : " << foundStudent.major;
                cout << "\n\tGPA          : " << foundStudent.gpa;
                return;
            }
            else if (!hashTable[index].isPreviouslyOccupied) {
                break; 
            }
            index = (index + 1) % tableSize;
        } while (index != originalIndex);

        cout << "\n\tStudent ID " << id << " not found." << endl;
    }

    bool remove(int id) {
        int index = hashFunction(id);
        int originalIndex = index;

        do {
            if (hashTable[index].isOccupied && hashTable[index].id == id) {
                hashTable[index].isOccupied = false;
                numElements--;
                cout << "\n\tStudent record index #" << index << " with ID: " << id << " has been removed." << endl;
                return true;
            }
            else if (!hashTable[index].isPreviouslyOccupied) {
                break; 
            }

            index = (index + 1) % tableSize;
        } while (index != originalIndex);

        cout << "\n\tStudent ID " << id << " not found." << endl;
        return false;
    }


    void display() {
        for (int i = 0; i < tableSize; ++i) {
            if (hashTable[i].isOccupied) {
                cout << "\n\t[" << i << "] " << hashTable[i].id << ", " << hashTable[i].name << ", " << hashTable[i].major << ", " << hashTable[i].gpa;
            }
        }
    }
};
