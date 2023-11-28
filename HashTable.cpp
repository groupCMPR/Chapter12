#include "HashTable.h"

Student::Student() {
    tableSize = 0;
    numElements = 0;
}

int Student::hashFunction(int id) {
    if (tableSize == 0)
        return 0;

    return id % tableSize;
}

void Student::readDataFile(const string& fileName, int numRecords) {
    hashTable.clear();

    ifstream file(fileName);
    string line;
    if (!file) {
        cout << "ERROR: File, " << fileName << ", not found.\n";
        return;
    }

    tableSize = numRecords;
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
    int index = hashFunction(student.id);

    if (hashTable[index].isOccupied == true) {
        for (int i = student.id + 1; i != student.id; ++i) {
            if (i == tableSize)
                i = 0;
            index = hashFunction(i);

            if (hashTable[index].isOccupied == false) {
                break;
            }
                
        }
    }

    hashTable[index] = student;
    hashTable[index].isOccupied = true;
    hashTable[index].isPreviouslyOccupied = true;
    numElements++;
}

void Student::set_push(const studentInfo& student) {
    if (tableSize == 0) {
        hashTable.push_back(student);

        hashTable[hashTable.size() - 1] = student;
        hashTable[hashTable.size() - 1].isOccupied = true;
        hashTable[hashTable.size() - 1].isPreviouslyOccupied = true;
        ++tableSize;
    }
    else {
        int index = hashFunction(student.id);
        hashTable[index] = student;
        hashTable[index].isOccupied = true;
        hashTable[index].isPreviouslyOccupied = true;

    }
}
bool Student::search(int id){
    int index = hashFunction(id);
    int originalIndex = index;

    if (index >= tableSize) {
        cout << "\n\tStudent ID " << id << " not found.";
        return false;
    }

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

    if (index >= tableSize) {
        cout << "\n\tStudent ID " << id << " not found.";
        return;
    }

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

    if (index >= tableSize) {
        cout << "\n\tStudent ID " << id << " not found.";
        return false;
    }

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
            cout << "\n\t[" << i + 1 << "] " << hashTable[i].id << ", " << hashTable[i].name << ", " << hashTable[i].major << ", " << hashTable[i].gpa;
        }
    }
}
