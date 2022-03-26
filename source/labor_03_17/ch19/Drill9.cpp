// -----------------------------------------------------------------------------
// Chapter 18 - Drill 9
/*
	Add a set() function template so that you can change val.
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

	void set(T t) { val = t; }
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
	si.set(10);
	cout << get(si) << endl;

	S<char> sc('z');
	sc.set('a');
	cout << get(sc) << endl;

	S<double> sd(10.4f);
	sd.set(83.3f);
	cout << get(sd) << endl;

	S<string> ss("A String.");
	ss.set("another string but this one is longer");
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	svi.set(vector<int>(10, 23));
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
