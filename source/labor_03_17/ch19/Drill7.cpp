// -----------------------------------------------------------------------------
// Chapter 18 - Drill 7
/*
	Make val private. 
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

private:
	// ---- variables
	T val;
};

// -----------------------------------------------------------------------------

template<typename T>
const T& get(S<T>& s)
{
	return s.get();
}

// -----------------------------------------------------------------------------

int main()
{
	S<int> si(101);
	cout << get(si) << endl;

	S<char> sc('z');
	cout << get(sc) << endl;

	S<double> sd(10.4f);
	cout << get(sd) << endl;

	S<string> ss("A String.");
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
