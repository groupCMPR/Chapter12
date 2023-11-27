//Name: Alexis Martinez and John Kim
//Date: 11/26/2023
//Description: cpp file for class HashTable

#include "HashTable.h"

Student::Student() {
    numElements = 0;
    tableSize = 40;  
    hashTable.resize(tableSize);
}

int Student::hashFunction(int id) {
    return id % tableSize;
}

void Student::resizeHashTable() {
    int oldTableSize = tableSize;
    tableSize *= 2;
    vector<studentInfo> newHashTable(tableSize);

    for (int i = 0; i < oldTableSize; i++) {
        if (hashTable[i].isOccupied) {
            int newIndex = hashFunction(hashTable[i].id);
            while (newHashTable[newIndex].isOccupied) {
                newIndex = (newIndex + 1) % tableSize;
            }
            newHashTable[newIndex] = hashTable[i];
        }
    }

    hashTable = newHashTable;
}

void Student::readDataFile(const string& fileName, int numRecords) {
    ifstream file(fileName);
string line;
if (!file) {
    cout << "ERROR: File, " << fileName << ", not found.\n";
    return;
}
numElements = 0;
tableSize = 40; 
hashTable.clear();
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

void Student::insert(const studentInfo& student) {
   if (numElements >= tableSize) {
    cout << "\n\tERROR: Hash table is full. Cannot insert new student.";
    return;
}

int index = hashFunction(student.id);
int start_index = index;

while (hashTable[index].isOccupied) {
    index = (index + 1) % tableSize;
    if (index == start_index) { 
        cout << "\n\tERROR: Hash table is full. Cannot insert new student.";
        return;
    }
}

hashTable[index] = student;
hashTable[index].isOccupied = true;
hashTable[index].isPreviouslyOccupied = true;
numElements++;
}

bool Student::search(int id){
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

void Student::getStudentInfo(int id) {
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

    cout << "\n\tStudent ID " << id << " not found.";
}

bool Student::remove(int id){
    int index = hashFunction(id);
    int originalIndex = index;

    do {
        if (hashTable[index].isOccupied && hashTable[index].id == id) {
            hashTable[index].isOccupied = false;
            numElements--;
            cout << "\n\tStudent record index #" << index << " with ID: " << id << " has been removed.";
            return true;
        }
        else if (!hashTable[index].isPreviouslyOccupied) {
            break;
        }

        index = (index + 1) % tableSize;
    } while (index != originalIndex);

    cout << "\n\tStudent ID " << id << " not found.";
    return false;
}

void Student::display() const{
    for (int i = 0; i < tableSize; ++i) {
        if (hashTable[i].isOccupied) {
            cout << "\n\t[" << i << "] " << hashTable[i].id << ", " << hashTable[i].name << ", " << hashTable[i].major << ", " << hashTable[i].gpa;
        }
    }
}
