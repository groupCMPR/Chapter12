//Name: Neidy Malaga & Vivian Huynh
//Date: 11/22/2023
//Description: Header file for class template SearchingDynamicArray

#pragma once
#include <iostream>  //For ostream
#include <vector>    //For vectors
#include <algorithm> //For sort
#include <random>    //For mt randomization
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
	int serial_search(const T&, size_t) const;
	int binary_search(const T&, size_t, size_t) const;

	//MUTATORS
	void fillArray(const size_t&);
	void sortArray();
	void pushElement(const T&);
	void setClear();

	//FRIEND
	template <class T>
	friend ostream& operator <<(ostream&, const SearchingDynamicArray<T>&);
};

#include "SearchingDynamicArray.template"
