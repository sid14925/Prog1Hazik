// -----------------------------------------------------------------------------
// 
/*
	Chapter 20

	Drill 6
	Write a simple copy() operation,

	template<typename Iter1, typename Iter2>
	// requires Input_iterator<iter1>() && Output_iterator<Iter2>()
	Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
	
	that  copies [f1, e1) to [f2, f2+(e1-f1)) and returns f2+(e1 - f1) just like 
	the standard library copy function. Note that if f1==e1 the sequence is empty, 
	so that there is nothing to copy.

	Drill 7
	Use your copy() to copy the array into the vector and to copy the list into the array.

	Drill 8
	Use the standard library function find() to see if the vector contains the value 
	3 and print out its position if it does; use find() to see if the list contains 
	the value 27 and print out it's position if it does. The "position" of the first 
	element  is 0, the position of the second element is 1, etc. Note that if find() 
	returns the end of the sequence, the value wasn't found.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "std_lib_facilities.h"
#include <iterator>

// -----------------------------------------------------------------------------

template<typename Iter1, typename Iter2>
Iter2 IterCopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

// -----------------------------------------------------------------------------

int main()
{
	// array of ints
	array<int, 10> intArray = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// vector of ints
	vector<int> intVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// list of ints
	list<int> intList{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// copies
	array<int, 10> intArray2 = intArray;
	
	vector<int> intVector2 = intVector;

	list<int> intList2 = intList;

	// increase values
	for (int& i : intArray)
		i += 2;

	for (int& i : intVector)
		i += 3;

	for (int& i : intList)
		i += 5;

	// test IterCopy
	IterCopy(intArray.begin(), intArray.end(), intVector2.begin());
	if (intArray[0] != intVector2[0])
		cout << "Error: intArray[0] && intVector2[0] are not the same!" << endl;

	IterCopy(intList.begin(), intList.end(), intArray2.begin());
	if(*(intList.begin()) != intArray2[0])
		cout << "Error: intList[0] && intArray2[0] are not the same!" << endl;

	// find 3 in vector
	auto vecResult = find(begin(intVector), end(intVector), 3);
	if (vecResult != end(intVector))
		cout << "intVector contains 3 at position " << distance(intVector.begin(), vecResult) << endl;
	else
		cout << "intVector does not contain 3" << endl;

	// find 27 in list
	auto listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult contains 27 at position " << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult does not contain 27" << endl;

	intList.push_back(27);
	listResult = find(begin(intList), end(intList), 27);
	if (listResult != end(intList))
		cout << "listResult contains 27 at position " << distance(intList.begin(), listResult) << endl;
	else
		cout << "listResult does not contain 27" << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------