//Name: Neidy Malaga & Vivian Huynh
//Date: 11/22/2023
//Description: Header file for class template SearchingDynamicArray

#pragma once
#include <iostream>  //For ostream
#include <vector>    //For vectors
#include <algorithm> //For sort
#include <random>
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
	T getElement(char) const; //NOT DONE, binary serial searches

	//MUTATORS
	void set_Elements(const size_t& size) ;
	void sortArray();
	void pushElement(const T&);
	void setClear();

	//FRIEND
	template <class T>
	friend ostream& operator <<(ostream&, const SearchingDynamicArray<T>&);
};

#include "SearchingDynamicArray.template"
