// challenge_4.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

bool compare(string, string);

int main() 
{
	cout << "Challenge 4 ...\n";
	
	string str;
	vector <string> list;

	int size = 0;
	
	bool found = false;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Coding Projects\\C++ Code\\baskets.txt", ios::in);

	while (file >> str)
    {
        list.push_back(str);
	}

	sort(list.begin(), list.end(), compare);

	string tempStr = "";
	int tempCount = 0;

	string firstName = "";
	int firstCount = 0;
	string secondName = "";
	int secondCount = 0;
	string thirdName = "";
	int thirdCount = 0;

	for (int count = 0; count < list.size(); ++count)
	{
		if (tempStr != list[count])
		{
			if (tempCount > firstCount)
			{
				firstName = tempStr;
				firstCount = tempCount;
			}
			else if (tempCount > secondCount && tempCount < firstCount)
			{
				secondName = tempStr;
				secondCount = tempCount;
			}
			else if (tempCount > thirdCount && tempCount < secondCount)
			{
				thirdName = tempStr;
				thirdCount = tempCount;
			}
			tempStr = list[count];
			tempCount = 1;
		}
		else
		{
			++tempCount;
		}
	}

	cout << '\n' << firstName << ' ' << firstCount << endl;
	cout << secondName << ' ' << secondCount << endl;
	cout << thirdName << ' ' << thirdCount << "\n\n";

	system("pause");
}

bool compare(string a,string b)
{
    return a < b;
}