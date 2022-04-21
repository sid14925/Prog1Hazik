/ -----------------------------------------------------------------------------
// 
/*
	Chapter 21

	Drill 8
	Repeat the exercise with a list<Item> rather than a vector<Item>.

*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "std_lib_facilities.h"

//--GLOBALS--//

// -----------------------------------------------------------------------------

struct Item
{
	Item() : name(), value(), id() {}
	Item(string pName, double pValue1, int pID) : name(pName), value(pValue1), id(pID) {}

	string name;
	double value;
	int id;

	friend istream& operator>>(istream& input, Item& item)
	{
		string line;
		getline(input, line);
		if(!line.empty())
		{
			size_t comma1 = line.find(',');
			item.name = line.substr(2, comma1 - 2);

			size_t comma2 = line.find(',', comma1 + 1);
			size_t diff = comma2 - (comma1 + 2);
			item.value = stod(line.substr(comma1 + 2, diff));

			size_t endBracket = line.find('}', comma2);
			diff = endBracket - (comma2 + 2);
			item.id = stoi(line.substr(comma2 + 2, diff));
		}

		return input;
	}

	friend ostream& operator<<(ostream& output, Item& item)
	{
		output << "{ " << item.name << ",\t" << item.value << ",\t" << item.id << " }" ;
		return output;
	}
};

// -----------------------------------------------------------------------------

bool lexicographicalCompare(char a, char b)
{
	return tolower(a) < tolower(b);
}

// -----------------------------------------------------------------------------

struct SortByName
{
	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return std::lexicographical_compare(
			pItem1.name.begin(), pItem1.name.end(),
			pItem2.name.begin(), pItem2.name.end(),
			lexicographicalCompare);
	}
};

// -----------------------------------------------------------------------------

struct SortByID
{
	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return pItem1.id < pItem2.id;
	}
};

// -----------------------------------------------------------------------------

// true == low to high, false == high to low
struct SortByValue
{
	SortByValue(bool pOrder) : order(pOrder) {}

	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return order ? (pItem1.value < pItem2.value) : (pItem1.value > pItem2.value);
	}

	bool order;
};

// -----------------------------------------------------------------------------

struct RemoveByName
{
	RemoveByName(string pName) : s(pName) {}
	bool operator()(const Item& pItem1)
	{
		return pItem1.name == s;
	}
	string s;
};

// -----------------------------------------------------------------------------

struct RemoveByID
{
	RemoveByID(int pID) : i(pID) {}
	bool operator()(const Item& pItem1)
	{
		return pItem1.id == i;
	}
	int i;
};

// -----------------------------------------------------------------------------

void fct()
{
	// Drill 1 - Create Item struct, fill with 10 items
	string fromFile = "ItemList.txt";
	string toFile = "NewItemList.txt";

	ifstream is{ fromFile };
	ofstream os{ toFile };

	istream_iterator<Item> ii{ is };
	istream_iterator<Item> eos;
	ostream_iterator<Item> oo{ os, "\n" };

	list<Item> v{ ii, eos };

	// Drill 5 - Insert two new items
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Insert 2 new items:" << endl;
	auto listIt = v.begin();
	advance(listIt, 2);
	v.insert(listIt, Item{ "horse shoe", 12.34, 99 });
	advance(listIt, 5);
	v.insert(listIt, Item{ "Canon S400", 499.95, 9988 });
	for (Item i : v)
		cout << i << endl;

	// Drill 2 - Sort by name
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Sorting by name:" << endl;
	v.sort(SortByName());
	for (Item i : v)
		cout << i << endl;

	// Drill 3 - Sort by id
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Sorting by id:" << endl;
	v.sort(SortByID());
	for (Item i : v)
		cout << i << endl;

	// Drill 4 - Sort by decreasing value
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Sorting by value(decreasing):" << endl;
	v.sort(SortByValue(false));
	for (Item i : v)
		cout << i << endl;

	// Drill 6 - Remove 2 items by name
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Removing 2 items by name:" << endl;
	auto It = std::find_if(v.begin(), v.end(), RemoveByName("baked beans"));
	v.erase(It);
	It = std::find_if(v.begin(), v.end(), RemoveByName("nutella"));
	v.erase(It);
	for (Item i : v)
		cout << i << endl;

	// Drill 7 - Remove 2 items by ID
	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "Removing 2 items by id:" << endl;
	It = std::find_if(v.begin(), v.end(), RemoveByID(99));	// horse shoe
	v.erase(It);
	It = std::find_if(v.begin(), v.end(), RemoveByID(3));	// cornflakes
	v.erase(It);
	for (Item i : v)
		cout << i << endl;

	cout << "// -----------------------------------------------------------------------------" << endl;
	cout << "End of list. " << endl;
}

// -----------------------------------------------------------------------------

int main()
{
	// done to keep an eye on memory tracking (it will always report as a leak if done in main)
	fct();

	keep_window_open();
	_CrtDumpMemoryLeaks();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------