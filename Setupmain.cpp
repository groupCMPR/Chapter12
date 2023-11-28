//Names: Alexis Martinez, John Kim, Neidy Malaga, & Vivian Huynh
//Date: 11/20/2023
//Description: Chapter 12 Assignment - Searching and Hashing

//The purpose of our project is to better understand how recursive serial and binary search work and hashing works.
// Section 1 and Section 2 both have arrays that employ the two searches, except section 1 has an unsorted array. 
// In both, the serial search is able to find the index of the target, but in section 1, binary search may not find the index
// as the array must be sorted for binary search to work. Section 3 focuses on storing information using id. The ids must be 
// sorted in a hash and it must avoid collisions. 
//Groups:
//Section 1 (unsorted array): Neidy
//Section 2 (sorted array): Vivian
//Section 3 (Hash): John and Alexis
#include <iostream> //For cout

//HEADER FILES
#include "input.h" //For input validation
#include "SearchingDynamicArray.h" //For option 1 & 2
#include "HashTable.h"
using namespace std;

//PROTOTYPES
int menuOption();
//Option 1 - Searching from an unsorted dynamic array
void option1();
//Option 2 - Searching from an sorted dynamic array
void option2();
//Option 3 - Application using hashing
void option3();

//Precondition : N/A
//Postcondition: Calls option 1, 2, and 3
int main()
{
    do
    {
        system("cls");
        switch (menuOption())
        {
        case 0: exit(0);
        case 1: system("cls"); option1(); break;
        case 2: system("cls"); option2(); break;
        case 3: system("cls"); option3(); break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return 0;
}

//Precondition : Calls from main
//Postcondition: Returns integer choice
int menuOption()
{
    cout << "\n\tCMPR131 Chapter 12: Searches and Hashing (Final Group 11)";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1> Searching from an unsorted dynamic array";
    cout << "\n\t\t2> Searching from a sorted dynamic array";
    cout << "\n\t\t3> Application using hashing";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 3);
}

//Precondition : Calls from main
//Postcondition: Add, display, and search unsorted dynamic arrays
void option1()
{
    SearchingDynamicArray<string> unsorted_vector;

    do
    {
        system("cls");
        cout << "\n\t1> Searching unsorted dynamic arrays";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Randomly generate a list of data and store into the dynamic array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDE")))
        {
        case '0': return;
        case 'A':
        {
            unsorted_vector.fillArray(inputInteger("\n\t\tEnter the size of the dynamic array: ", true));
            cout << "\n\t\tRandom elements have been populated into the array.\n";
        }break;
        case 'B':
        {
            string data = inputString("\n\t\tEnter a string element: ", true);
            unsorted_vector.pushElement(data);
            cout << "\n\t\tElement \"" << data << "\" has been added to the array.\n";
        }break;
        case 'C':
        {
            if (unsorted_vector.isEmpty())
            {
                cout << "\n\t\tThe array is empty.\n";
                break;
            }
            cout << unsorted_vector << '\n';
        }break;
        case 'D':
        {
            if (unsorted_vector.isEmpty())
            {
                cout << "\n\t\tThe array is empty.\n";
                break;
            }

            int size = -1;
            string data = "";
            char searchType = inputChar("\n\t\tChoose search type (S)Serial or (B)Binary: ", static_cast<string>("SB"));

            if (searchType == 'S')
            {
                cout << "\n\t\tRecursive serial search";
                cout << "\n\t\t" << string(20, char(196));
                data = inputString("\n\t\tEnter a string element to search: ", true);

                size = unsorted_vector.serial_search(data, 0);
            }
            else {
                cout << "\n\t\tRecursive binary search";
                cout << "\n\t\t" << string(20, char(196));
                data = inputString("\n\t\tEnter a string element to search: ", true);

                size = unsorted_vector.binary_search(data, 0, unsorted_vector.getSize());
            }

            if (size == -1)
                cout << "\n\t\t\"" << data << "\" is not found in the unsorted array.\n";
            else
                cout << "\n\t\t\"" << data << "\" is found at index " << size << " from the unsorted array.\n";
        }break;
        case 'E':
        {
            unsorted_vector.setClear();
            cout << "\n\t\t Elements from the array have been cleared/deleted.\n";
        }break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition : Calls from main
//Postcondition: Add, display, and search sorted dynamic arrays
void option2()
{
    SearchingDynamicArray<string> sortedArray;

    do
    {
        system("cls");
        cout << "\n\t2> Searching sorted dynamic arrays";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Randomly generate a list of data and store into the dynamic array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDE")))
        {
        case '0': return;
        case 'A':
        {
            sortedArray.fillArray(inputInteger("\n\t\tEnter the size of the dynamic array: ", true));
            sortedArray.sortArray();
            cout << "\n\t\tRandom elements have been populated into the array.\n";
        }break;
        case 'B':
        {
            string data = inputString("\n\t\tEnter a string element: ", true);
            sortedArray.pushElement(data);
            sortedArray.sortArray();
            cout << "\n\t\tElement \"" << data << "\" has been added to the array.\n";
        }break;
        case 'C':
        {
            if (sortedArray.isEmpty())
            {
                cout << "\n\t\tThe array is empty.\n";
                break;
            }
            cout << sortedArray << '\n';
        }break;
        case 'D':
        {
            if (sortedArray.isEmpty())
            {
                cout << "\n\t\tThe array is empty.\n";
                break;
            }

            int size = -1;
            string data = "";
            char searchType = inputChar("\n\t\tChoose search type (S)Serial or (B)Binary: ", static_cast<string>("SB"));

            if (searchType == 'S')
            {
                cout << "\n\t\tRecursive serial search";
                cout << "\n\t\t" << string(20, char(196));
                data = inputString("\n\t\tEnter a string element to search: ", true);

                size = sortedArray.serial_search(data, 0);
            }
            else {
                cout << "\n\t\tRecursive binary search";
                cout << "\n\t\t" << string(20, char(196));
                data = inputString("\n\t\tEnter a string element to search: ", true);

                size = sortedArray.binary_search(data, 0, sortedArray.getSize());
            }

            if (size == -1)
                cout << "\n\t\t\"" << data << "\" is not found in the sorted array.\n";
            else
                cout << "\n\t\t\"" << data << "\" is found at index " << size << " from the sorted array.\n";
        }break;
        case 'E':
        {
            sortedArray.setClear();
            cout << "\n\t\t Elements from the array have been cleared/deleted.\n";
        }break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition : Calls from main
//Postcondition: Search, insert, and remove element into dynamic array with hashing
void option3(){
    Student table;
    do
    {

        system("cls");
        cout << "\n\t3> Application using hashing";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Read data file, hash and insert into the dynamic array";
        cout << "\n\t\tB> Search an element from the dynamic array";
        cout << "\n\t\tC> Insert an element into the dynamic array";
        cout << "\n\t\tD> Remove an element from the dynamic array";
        cout << "\n\t\tE> Display all records from the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDE")))
        {
        case '0': return;
        case 'A': {
            int num = inputInteger("\n\tEnter the number of records: ", 1, 40);

            table.readDataFile("Students.dat", num);

            cout << "\n\t" << num << " records have been inserted.";
            table.display();
            break;
        }
        case 'B': {
            int search = inputInteger("\n\tEnter a student ID to search: ");
            if (table.search(search)) {
                table.getStudentInfo(search);
                break;
            }
            else {
                cout << "\n\tStudent record not found.";
                break;
            }
            break;
        }
        case 'C': {
            studentInfo newStudent;
            newStudent.id = inputInteger("\n\tEnter a new student ID: ");
            if (table.search(newStudent.id)) {
                cout << "\n\tAlready in table";
                break;
            }
            newStudent.name = inputString("\n\tEnter the student's name: ", true);
            newStudent.major = inputString("\n\tEnter the student's major: ", true);
            newStudent.gpa = inputDouble("\n\tEnter a student's GPA (1.0..4.0): ", 1.0, 4.0);
            newStudent.isOccupied = true;
            newStudent.isPreviouslyOccupied = true;

            table.set_push(newStudent);
            cout << "\n\tInserted the new record.";
            table.display();
            break;
        }
        case 'D': {
            int toRemove = inputInteger("\n\tEnter a student ID to remove: ");
            table.remove(toRemove);
            table.display();
            break;
        }
        case 'E':
            table.display();
            break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}
