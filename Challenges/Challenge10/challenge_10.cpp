// challenge_10.cpp

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

unsigned long long int sumUp(vector<int>&);
int vecToInt(vector<int>&);
bool isPrime(int);
void addOne(vector<int>&);
int productVec(vector<int>&);
int digitsInVec(vector<int>&);
int exponent(int, int);

int main() 
{
	cout << "Challenge 10 ...\n";
	
	const int max_digits = 7;

	vector <int> num;

	for (int count = 0; count < max_digits; ++count)
	{
		num.push_back(0);
	}

	num[num.size() - 1] = 2; //start value "00002"

	cout << "This is the sum: " << sumUp(num) << endl;

	system("pause");
}

unsigned long long int sumUp(vector<int>& v)
{
	unsigned long long int sum = 0;
	const int max_size = 1'000'000;
	int vecInt = 0;

	while (vecToInt(v) < max_size)
	{
		vecInt = vecToInt(v);
		if (isPrime(vecInt) && isPrime(productVec(v) + 1))
		{
			sum += vecInt;
			cout << vecInt << endl;
		}
		addOne(v);
	}
	return sum;
}

int vecToInt(vector<int>& v)
{
	int num = 0;
	for (int count = 0; count < digitsInVec(v); ++count)
	{
		num += v[v.size() - count - 1] * exponent(10, count);
	}
	return num;
}

bool isPrime(int num)
{ 
    for (int count = 2; count < num; ++count)
	{
		if (num % count == 0)
		{
			return false;
		}
	}
    return true;
}

void addOne(vector<int>& v)
{
	int count = v.size() - 1;

	while (count >= 0 && v[count] == 9)
	{
		if (v[count] == 9)
		{
			v[count] = 0;
		}
		--count;
	}
	++v[count];
}

int productVec(vector<int>& v)
{
	int product = 1;
	int digits = digitsInVec(v);
	for (int count = 0; count < digits; ++count)
	{
		product *= v[v.size() - count - 1];
	}
	return product;
}

int digitsInVec(vector<int>& v)
{
	int count = 0;
	while (v[count] == 0)
	{
		++count;
	}
	return v.size() - count;
}

int exponent(int base, int exponent)
{
	int result = 1;
	for (int count = 0; count < exponent; ++count)
	{
		result *= base;
	}
	return result;
}
