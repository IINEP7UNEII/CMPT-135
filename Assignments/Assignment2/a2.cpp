// a2.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Daniel Tolsky
// St.# : 301452597
// Email: daniel_tolsky@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

//
// These are the only permitted includes: don't include anything else.
//
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//test function prototypes
void testGet();
void testSet();
void testGetSize();
void testGetCapacity();
void testPct_used();
void testJoin();
void testAppend();
void testAppend_new();
void testTrim_all();
void testRemove();
void testKeep_all_starts_with();
void testClear();
void testSquish();
void testTo_str();
void testEquals();
void testNotEquals();

//str_vec class
class str_vec
{
	private:
		string* arr;    // pointer to the underlying array
		int capacity;   // length of underlying array
		int size;       // # of elements from user's perspective

	public:
		// Default constructor
		str_vec()
		: str_vec(0, "") // size 0, capacity 10
		{
			capacity = 10;
		}

		// Constructor
		str_vec(int n, string s)
		: capacity(2 * n + 1), size(n)
		{
			if (n < 0)
			{
				cmpt::error("str_vec(n, s): n must be 0 or greater");
			}
			arr = new string[capacity];
			for (int count = 0; count < n; ++count) 
			{
				arr[count] = s;
			}
		}

		// Copy constructor
		str_vec(const str_vec& other) 
		: capacity(other.capacity), size(other.size)
		{
			arr = new string[capacity];
			for (int count = 0; count < size; count++) 
			{
				arr[count] = other.arr[count];
			}
		}

		// A getter: returns the value at index location i of the underlying array
		string get(int i) const 
		{
			if (i < 0 || i >= size)
			{
				cmpt::error("get: index out of bounds");
			} 
			return arr[i];
		}

		// A setter: sets a string s at index location i of the underlying array
		void set(int i, string s)
		{
			if (i < 0 || i >= size)
			{
				cmpt::error("set: index out of bounds");
			}
			arr[i] = s;
		}

		// Returns size of underlying array
		int getSize() const 
		{ 
			return size; 
		}

		// Returns capacity of underlying array
		int getCapacity() const 
		{ 
			return capacity; 
		}

		// Returns percentage used of the underlying array (size / capacity)
		double pct_used() const
		{
			double pct = 0.0;

			pct = (double)size / (double)capacity;
			return pct;
		}

		// Joins elements of the array with string sep
		string join(string sep)
		{
			string total = arr[0];

			for (int count = 1; count < size; ++count) 
			{
				if (arr[count] != "")
				{
					total += sep + arr[count];
				}
			}
			return total;
		}

		// Adds another element to the end of the underlying array, increasing capacity if size >= capacity
		void append(string s)
		{
			if (size >= capacity) 
			{
				capacity = 2 * capacity;
				string* arr_new = new string[capacity];

				for (int count = 0; count < size; ++count) 
				{
					arr_new[count] = arr[count]; 
				}

				delete[] arr;
				arr = arr_new;
			}
			arr[size] = s;
			size++;
    	}

		// Same as append(), but only adds an element to the end of the array if that element (string s) does not already exist in the underlying array
		void append_new(string s)
		{
			bool existing = false;
			for (int count = 0; count < size; ++count)
			{
				if (s == arr[count])
				{
					existing = true;
				}
			}

			if (!existing)
			{
				append(s);
			}
		}

		// Removes any leading and trailing spaces from all the elements of the str_vec
		void trim_all()
		{
			string tempStr = "";
			string tempWord = "";

			for (int count1 = 0; count1 < size; ++count1)
			{
				tempStr = arr[count1];

				for (int count2 = 0; count2 < tempStr.length(); ++count2)
				{
					if (tempStr[count2] != ' ')
					{
						tempWord.push_back(tempStr[count2]);
					}
				}
				arr[count1] = tempWord;
				tempWord = "";
			}
		}

		// Removes element at index i
		void remove(int i)
		{
			int lastIndex = size - 1;

			if (i < 0 || i >= size)
			{
				cmpt::error("remove: index out of bounds");
			}

			for (int count = i; count <= lastIndex; ++count)
			{
				arr[count] = arr[count + 1];
			}
			--size;
		}

		// Removes all elements except those who being with char c
		void keep_all_starts_with(char c)
		{
			string tempStr = "";
			string* arr_new = new string[capacity];
			int keepCount = 0;
			
			for (int count = 0; count < size; ++count) 
			{
				tempStr = arr[count];
				if (tempStr[0] == c)
				{
					arr_new[keepCount] = arr[count]; 
					++keepCount;
				}
			}
			delete[] arr;
			arr = arr_new;
			size -= (size - keepCount);
		}

		// Clears the entire array, creating a new one with size = 0
		void clear()
		{
			string* arr_new = new string[capacity];
			delete[] arr;
			arr = arr_new;
			size = 0;
		}

		// Shrinks down the capacity to be equal to size (usefull for saving memory)
		void squish()
		{
			if (capacity > size)
			{
				capacity = size;
			}
		}

		// Returns a string which comprises the entire array
		string to_str() const
		{
			string str;

			str = "{";
			for (int count = 0; count < size; ++count) 
			{
				str += "\"";
				str += get(count);
				str += "\""; 
				if (count != (size - 1))
				{
					str += ", ";
				}
			}
			str += "}";
			return str;
		}

		// Print function: prints values of the underlying array
		void print() const 
		{
			cout << "{";
			for (int count = 0; count < size; ++count) 
			{
				cout << "\"" << get(count) << "\""; 
				if (count != (size - 1))
				{
					cout << ", ";
				}
			}
			cout << "}";
		}

		// Print function: prints values of the underlying array with \n at the end
		void println() const
		{
			cout << "{";
			for (int count = 0; count < size; ++count) 
			{
				cout << "\"" << get(count) << "\""; 
				if (count != (size - 1))
				{
					cout << ", ";
				}
			}
			cout << "}\n";
		}

		// Destructor.
		~str_vec() 
		{
			delete[] arr;
		}
};

//operator funciton prototypes
bool operator==(const str_vec, const str_vec);
bool operator!=(const str_vec, const str_vec);

// Function which allows the use of == operator to compare two str_vec objects, return true if they are equal, return false otherwise
bool operator==(const str_vec a, const str_vec b)
{
	if (a.getSize() != b.getSize())
	{
		return false;
	}

	for (int count = 0; count < a.getSize(); ++count)
	{
		if (a.get(count) != b.get(count))
		{
			return false;
		}
	}
	return true;
}

// Function which allows the use of != operator to compare two str_vec objects, return false if they are equal, return true otherwise
bool operator!=(const str_vec a, const str_vec b)
{
	if (a == b)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main() 
{
  	cout << "Assignment 2 ...\n";

	testGet();
	testSet();
	testGetSize();
	testGetCapacity();
	testPct_used();
	testJoin();
	testAppend();
	testAppend_new();
	testTrim_all();
	testRemove();
	testKeep_all_starts_with();
	testClear();
	testSquish();
	testTo_str();
	testEquals();
	testNotEquals();
	
	cout << "\n\n";

  	system("pause");
	return 0;
}

void testGet()
{
	str_vec a(5, "abc");
	str_vec b(5, "123");

	cout << "\n\nTest get(): ";

	assert(a.get(0) == "abc");
	cout << "passed  ";

	assert(b.get(0) == "123");
	cout << "passed  ";

	assert(b.get(3) == "123");
	cout << "passed  ";
}

void testSet()
{
	str_vec a(5, "abc");
	str_vec b(5, "123");

	cout << "\n\nTest set(): ";

	a.set(0, "peter");
	assert(a.get(0) == "peter");
	cout << "passed  ";

	b.set(0, "balla");
	assert(b.get(0) == "balla");
	cout << "passed  ";

	b.set(3, "&%^");
	assert(b.get(3) == "&%^");
	cout << "passed  ";
}

void testGetSize()
{
	str_vec a(5, "abc");
	str_vec b(6, "123");

	cout << "\n\nTest getSize(): ";

	assert(a.getSize() == 5);
	cout << "passed  ";

	assert(b.getSize() == 6);
	cout << "passed  ";

	b.append("walla");
	assert(b.getSize() == 7);
	cout << "passed  ";
}

void testGetCapacity()
{
	str_vec a(3, "abc");
	str_vec b(5, "123");
	str_vec c(100, ":)");

	cout << "\n\nTest getCapacity(): ";

	assert(a.getCapacity() == 7);
	cout << "passed  ";

	assert(b.getCapacity() == 11);
	cout << "passed  ";

	assert(c.getCapacity() == 201);
	cout << "passed  ";
}

void testPct_used()
{
	str_vec a(3, "abc");
	str_vec b(5, "123");

	cout << "\n\nTest pct_used(): ";

	assert(a.pct_used() == 0.42857142857142855);
	cout << "passed  ";

	assert(b.pct_used() == 0.45454545454545454);
	cout << "passed  ";

	b.append("iguana");
	assert(b.pct_used() == 0.54545454545454545);
	cout << "passed  ";
}

void testJoin()
{
	str_vec a(3, "abc");
	str_vec b(4, "123");
	str_vec c(5, ":)");

	cout << "\n\nTest join(): ";

	assert(a.join("x") == "abcxabcxabc");
	cout << "passed  ";

	assert(b.join("y") == "123y123y123y123");
	cout << "passed  ";

	assert(c.join("-") == ":)-:)-:)-:)-:)");
	cout << "passed  ";
}

void testAppend()
{
	str_vec a(3, "abc");

	cout << "\n\nTest append(): ";

	a.append("abc");
	assert(a.get(a.getSize() - 1) == "abc");
	cout << "passed  ";

	a.append("sfu");
	assert(a.get(a.getSize() - 1) == "sfu");
	cout << "passed  ";

	a.append("123");
	assert(a.get(a.getSize() - 1) == "123");
	cout << "passed  ";
}

void testAppend_new()
{
	str_vec a(3, "abc");

	cout << "\n\nTest append_new(): ";

	a.append_new("abc");
	assert(a.getSize() == 3);
	cout << "passed  ";

	a.append_new("sfu");
	assert(a.get(a.getSize() - 1) == "sfu");
	cout << "passed  ";

	a.append_new("123");
	assert(a.get(a.getSize() - 1) == "123");
	cout << "passed  ";
}

void testTrim_all()
{
	str_vec a(3, "abc ");
	str_vec b(4, " 1 23");
	str_vec c(5, ": )");

	cout << "\n\nTest trim_all(): ";

	a.trim_all();
	assert(a.to_str() == "{\"abc\", \"abc\", \"abc\"}");
	cout << "passed  ";

	b.trim_all();
	assert(b.to_str() == "{\"123\", \"123\", \"123\", \"123\"}");
	cout << "passed  ";

	c.trim_all();
	assert(c.to_str() == "{\":)\", \":)\", \":)\", \":)\", \":)\"}");
	cout << "passed  ";
}

void testRemove()
{
	str_vec a(3, "abc");

	cout << "\n\nTest remove(): ";

	a.remove(2);
	assert(a.to_str() == "{\"abc\", \"abc\"}");
	cout << "passed  ";

	a.remove(1);
	assert(a.to_str() == "{\"abc\"}");
	cout << "passed  ";

	a.remove(0);
	assert(a.to_str() == "{}");
	cout << "passed  ";
}

void testKeep_all_starts_with()
{
	str_vec a(3, "abc");

	cout << "\n\nTest keep_all_starts_with(): ";

	a.set(1, "hi");

	a.keep_all_starts_with('a');
	assert(a.to_str() == "{\"abc\", \"abc\"}");
	cout << "passed  ";

	a.set(1, "bob");
	a.keep_all_starts_with('b');
	assert(a.to_str() == "{\"bob\"}");
	cout << "passed  ";

	a.keep_all_starts_with(' ');
	assert(a.to_str() == "{}");
	cout << "passed  ";
}

void testClear()
{
	str_vec a(3, "abc");
	str_vec b(4, "123");
	str_vec c(5, ":)");

	cout << "\n\nTest clear(): ";

	a.clear();
	assert(a.to_str() == "{}");
	cout << "passed  ";

	b.clear();
	assert(a.to_str() == "{}");
	cout << "passed  ";

	c.clear();
	assert(a.to_str() == "{}");
	cout << "passed  ";
}

void testSquish()
{
	str_vec a(5, ":)");

	cout << "\n\nTest squish(): ";

	a.squish();
	assert(a.getSize() == a.getCapacity());
	cout << "passed  ";

	a.append("peter");
	a.squish();
	assert(a.getSize() == a.getCapacity());
	cout << "passed  ";

	a.append("peter");
	a.append("peter");
	a.append("peter");
	a.squish();
	assert(a.getSize() == a.getCapacity());
	cout << "passed  ";
}

void testTo_str()
{
	str_vec a(3, "abc");

	cout << "\n\nTest to_str(): ";

	assert(a.to_str() == "{\"abc\", \"abc\", \"abc\"}");
	cout << "passed  ";

	a.append("123");
	assert(a.to_str() == "{\"abc\", \"abc\", \"abc\", \"123\"}");
	cout << "passed  ";

	a.clear();
	assert(a.to_str() == "{}");
	cout << "passed  ";
}

void testEquals()
{
	str_vec a(3, "abc ");
	str_vec b(3, "abc ");
	str_vec c(5, "123");

	cout << "\n\nTest operator==(): ";

	assert((a == b) == true);
	cout << "passed  ";

	a.append("123");
	assert((a == c) == false);
	cout << "passed  ";

	a.clear();
	assert((b == c) == false);
	cout << "passed  ";
}

void testNotEquals()
{
	str_vec a(3, "abc ");
	str_vec b(3, "abc ");
	str_vec c(5, "123");

	cout << "\n\nTest operator!=(): ";

	assert((a == b) != false);
	cout << "passed  ";

	a.append("123");
	assert((a == c) != true);
	cout << "passed  ";

	a.clear();
	assert((b == c) != true);
	cout << "passed  ";
}