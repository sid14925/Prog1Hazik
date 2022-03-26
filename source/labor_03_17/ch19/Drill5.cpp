// -----------------------------------------------------------------------------
// Chapter 18 - Drill 5
/*
	Add a function template get() that returns a reference to val.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

template<typename T>
struct S
{
	// ---- constructors
	S() {}
	
	S(T t)
	: val(t)
	{}

	// ---- methods
	istream operator>>(T t) { cin >> val; }

	const T& get() const { return val; }

	// ---- variables
	T val;
};

// -----------------------------------------------------------------------------

int main()
{
	S<int> si(101);
	cout << si.get() << endl;

	S<char> sc('z');
	cout << sc.get() << endl;

	S<double> sd(10.4f);
	cout << sd.get() << endl;

	S<string> ss("A String.");
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	for (int i : svi.get())
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
