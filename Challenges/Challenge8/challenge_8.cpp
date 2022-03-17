// challenge_8.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

bool isMultipleOfEight(int);

void execute(char, int&, int&);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int max(int, int);

int main() 
{
	cout << "Challenge 8 ...\n";

	string str;
	vector <string> list;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Code\\C++\\CMPT-135\\Challenges\\Challenge8\\expr8.txt", ios::in);

	while (getline(file, str))
    {
        list.push_back(str);
	}

	int a = 0;
	int b = 0;
	char op = ' ';
	int charCount = 0;

	int multipleOfEights = 0;

	for (int lineCount = 0; lineCount < list.size(); ++lineCount) //go over lines
	{
		if (charCount == 0)
		{
			while (list[lineCount][charCount] != ' ' && charCount < list[lineCount].size()) //get first number
			{
				a *= 10;
				a += list[lineCount][charCount] - 48;
				++charCount;
			}
		}

		while (charCount < list[lineCount].size())
		{
			while ((list[lineCount][charCount] < 48 || list[lineCount][charCount] > 57) && charCount < list[lineCount].size()) //get operator
			{
				if (list[lineCount][charCount] != ' ')
				{
					op = list[lineCount][charCount];
				}
				++charCount;
			}

			while (list[lineCount][charCount] != ' ' && charCount < list[lineCount].size()) //get second number
			{
				b *= 10;
				b += list[lineCount][charCount] - 48;
				++charCount;
			}

			execute(op, a, b);
		}

		if (isMultipleOfEight(a))
		{
			++multipleOfEights;
		}

		a = 0;
		b = 0;
		op = ' ';
		charCount = 0;
	}

	cout << "\nThere are " << multipleOfEights << " expressions that evaluate to a multiple of eight\n\n";

	system("pause");
}

void execute(char c, int& a, int& b)
{
	switch(c)
	{
		case '+':
			a = add(a, b);
			break;

		case '-':
			a = subtract(a, b);
			break;

		case '*':
			a = multiply(a, b);
			break;

		case '@':
			a = max(a, b);
			break;
	}
	b = 0;
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

bool isMultipleOfEight(int num)
{
	if (num % 8 == 0)
	{
		return true;
	}
	return false;
}