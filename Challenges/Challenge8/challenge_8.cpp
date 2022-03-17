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
void getNum(string, int&, int&);
void getOp(string, int&, char&);

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

	int charCount = 0;
	int a = 0;
	int b = 0;
	char op = ' ';

	for (int lineCount = 0; lineCount < list.size(); ++lineCount) //go over lines
	{
		getNum(list[lineCount], charCount, a);


		a = 0;
		b = 0;
		charCount = 0;
	}

	system("pause");
}

void getNum(string s, int& i, int& num)
{
	if (s[i] > 57 || s[i] < 48 || i > s.size() - 1)
	{
		return;
	}

	num *= 10;
	num += s[i] - 48;
	getNum(s, ++i, num);
}

void getOp(string s, int& i, char& op)
{
	if (i > s.size() - 1)
	{
		return;
	}

	if (s[i] == '+' || s[i]  == '-' || s[i]  == '*' || s[i] == '@')
	{
		op = s[i];
		return;
	}

	getOp(s, ++i, op);
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