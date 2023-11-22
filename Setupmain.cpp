//Names: Alexis Martinez, John Kim, Neidy Malaga, & Vivian Huynh
//Date: 11/20/2023
//Description: Chapter 12 Assignment - Searching and Hashing

#include <iostream> //For cout

//HEADER FILES
#include "input.h" //For input validation

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
        case 'A': break;
        case 'B': break;
        case 'C': break;
        case 'D': break;
        case 'E': break;
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
    do
    {
        system("cls");
        cout << "\n\t2> Searching sorted dynamic arrays";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Randomly generate a list of data and store into the dynamic array"";
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
        case 'A': break;
        case 'B': break;
        case 'C': break;
        case 'D': break;
        case 'E': break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition : Calls from main
//Postcondition: Search, insert, and remove element into dynamic array with hashing
void option3()
{
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
        case 'A': break;
        case 'B': break;
        case 'C': break;
        case 'D': break;
        case 'E': break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}
