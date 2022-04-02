// -----------------------------------------------------------------------------
// 
/*
	Chapter 20 - Drills

	1 - Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
	2 - Define a vector<int> with those ten elements.
	3 - Define a list<int> with those ten elements.
	4 - Define a second array, vector and list, each initialised as a copy of the 
		first array, vector, and list, respectively.
	5 - Increase the value of each element in the array by 2; increase the value of 
		each element in the vector by 3; increase the value of each element in the list by 5.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include"std_lib_facilities.h"

// -----------------------------------------------------------------------------


int main()
{
	// array of ints
	int intArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// vector of ints
	vector<int> intVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// list of ints
	list<int> intList{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// copies
	int intArray2[10];
	copy(begin(intArray), end(intArray), begin(intArray2));

	vector<int> intVector2 = intVector;

	list<int> intList2 = intList;

	// increase values
	for (int& i : intArray)
		i += 2;

	for (int& i : intVector)
		i += 3;

	for (int& i : intList)
		i += 5;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------