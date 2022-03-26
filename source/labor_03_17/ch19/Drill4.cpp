// -----------------------------------------------------------------------------
// Chapter 18 - Drill 4
/*
	Read those values and print them.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

template<typename T>
struct S
{
	S() {}
	
	S(T t)
	: val(t)
	{}

	istream operator>>(T t) { cin >> val; }

	T val;
};

// -----------------------------------------------------------------------------

int main()
{
	S<int> si;
	cout << "Enter int: "; cin >> si.val;
	cout << si.val << endl;

	S<char> sc;
	cout << "Enter char: "; cin >> sc.val;
	cout << sc.val << endl;

	S<double> sd;
	cout << "Enter double: "; cin >> sd.val;
	cout << sd.val << endl;

	S<string> ss;
	cout << "Enter string: "; cin >> ss.val;
	cout << ss.val << endl;

	S<vector<int>> svi(vector<int>(10,19));
	cout << "Enter 10 ints: ";
	for(int i = 0; i < 10; ++i)
		cin >> svi.val[i];
	for(int i : svi.val)
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
