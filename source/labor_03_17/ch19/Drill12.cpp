// -----------------------------------------------------------------------------
// Chapter 18 - Drill 12
/*
	Define a function template<typename T> read_val(T& v) that reads from cin 
	into v.
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
	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) { cin >> val; }

	void set(T t) { val = t; }
	const T& get() const { return val; }

	// returns non-const reference to val
	T& getRef() {return val;}	

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

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

// -----------------------------------------------------------------------------

int main()
{
	S<int> si;
	cout << "Enter int: "; read_val(si.getRef());
	cout << si.get() << endl;

	S<char> sc;
	cout << "Enter char: "; read_val(sc.getRef());
	cout << sc.get() << endl;

	S<double> sd;
	cout << "Enter double: "; read_val(sd.getRef());
	cout << sd.get() << endl;

	S<string> ss;
	cout << "Enter string: "; read_val(ss.getRef());
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10, 19));
	cout << "Enter 10 ints: ";
	for (int i = 0; i < 10; ++i)
		read_val(svi.getRef()[i]);
	for (int i : svi.get())
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
