// -----------------------------------------------------------------------------
// Chapter 18 - Drill 3
/*
	Define variables of types S<int>, S<char>, S<double>, S<string>, and 
	S<vector<int>>; initialise them with values of your choice.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

template<typename T>
struct S
{
	S(T t)
	: val(t)
	{}

	T val;
};

// -----------------------------------------------------------------------------

int main()
{
	S<int> si(101);
	cout << si.val << endl;

	S<char> sc('z');
	cout << sc.val << endl;

	S<double> sd(10.4f);
	cout << sd.val << endl;

	S<string> ss("A String.");
	cout << ss.val << endl;

	S<vector<int>> svi(vector<int>(10,100));
	for(int i : svi.val)
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
