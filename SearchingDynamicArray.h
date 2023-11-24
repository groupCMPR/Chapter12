//Name: Neidy Malaga & Vivian Huynh
//Date: 11/22/2023
//Description: Header file for class template SearchingDynamicArray

#pragma once
#include <iostream>  //For ostream
#include <vector>    //For vectors
#include <algorithm> //For sort
#include <cstdlib>   //For srand
#include <string>    //For to_string
using namespace std;

template <class T>
class SearchingDynamicArray
{
private:
	vector<T> myVector;

public:
	//CONSTRUCTOR
	SearchingDynamicArray();

	//ACCESSORS
	bool isEmpty() const;
	int getSize() const;
	int getElement(char, const T&, int) const; //NOT DONE, binary serial searches

	//MUTATORS
	void fillArray(const size_t&);
	int serial_search(const T&, size_t) {
	int binary_search(const T&, size_t, size_t);
	void sortArray();
	void pushElement(const T&);
	void setClear();

	//FRIEND
	friend ostream& operator <<<>(ostream&, const SearchingDynamicArray<T>&);
};

#include "SearchingDynamicArray.template"
