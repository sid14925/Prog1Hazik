#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

struct Person
{
public:
	Person() {}
	Person(string first, string last, int n) { init(first, last, n); }

	void init(string first, string last, int n)
	{
		checkName(first, last);
		checkAge(n);

		m_firstname = first;
		m_lastname = last;
		m_age = n;
	}

	string getFirstName() const { return m_firstname; }
	string getLastName() const { return m_lastname; }
	int getAge() const { return m_age; }

private:
	void checkAge(int n);
	void checkName(string first, string last);

	string m_firstname, m_lastname;
	int m_age;
};

void Person::checkAge(int n)
{
	unsigned int difference = 150 - n;
	if (difference > 150)
		error("Age needs to be in range 0 - 150");
}

void Person::checkName(string first, string last)
{
	if (first == "")
		error("first name cannot be blank");
	size_t result = first.find_first_of(";:\"\'[]*&^%$#@!");
	if (result == string::npos)
	{
		if (last == "")
			error("Last name cannot be blank");

		result = last.find_first_of(";:\"\'[]*&^%$#@!");
		if (result == string::npos)
			return;
	}

	error("Names cannot contain the following: ;:\"\'[]*&^%$#@!");
}

ostream& operator<<(ostream& o, const Person& p) 
{ 
	o << p.getFirstName() << " " << p.getLastName() << ": " << p.getAge() << endl; 
	return o; 
}

istream& operator>>(istream& i, Person& p)
{
	string first, last;
	int a;
	cout << "First name: "; cin >> first;
	cout << "Last name: "; cin >> last;
	cout << "Age: "; i >> a; 

	p.init(first, last, a);

	return i;
}

// -----------------------------------------------------------------------------

int main()
{
	Person p1;
	cin >> p1;
	cout << p1;
	
	getc;
	return 0;
}