// challenge_2.cpp

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

bool isDifferent(string);
bool isRepeated(string);
bool isOrdinary(string);

int main() 
{
	cout << "Challenge 2 ...\n";
	
    string num;
    vector <string> strArray;

	auto diff = 0;
	auto rep = 0;
	auto ord = 0;

    ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Coding Projects\\C++ Code\\strings2.txt", ios::in);

    while (file >> num) //input everything in file into a vector
    {
        strArray.push_back(num);
    }

	for (auto count = 0; count < strArray.size(); ++count) //go through each element of strArray and check each string using the functions
	{
		if (isDifferent(strArray[count]))
		{
			++diff;
		}

		if (isRepeated(strArray[count]))
		{
			++rep;
		}

		if (isOrdinary(strArray[count]))
		{
			++ord;
		}
	}

	cout << "Different strings: " << diff;
	cout << "\nRepeated strings: " << rep;
	cout << "\nOrdinary strings: " << ord;
	
    system("pause");
}

bool isDifferent(string word)
{
	for (int count1 = 0; count1 < word.length(); ++count1)
	{
		for (int count2 = count1 + 1; count2 < word.length(); ++count2)
		{
			if (word[count1] == word[count2])
			{
				return false;
			}
		}
	}
	return true;
}

bool isRepeated(string word)
{
	for (int count1 = 0; count1 < word.length(); ++count1)
	{
		for (int count2 = count1 + 1; count2 < word.length(); ++count2)
		{
			if (word[count1] != word[count2])
			{
				return false;
			}
		}
	}
	return true;
}

bool isOrdinary(string word)
{
	if (!isRepeated(word) && !isDifferent(word))
	{
		return true;
	}
	else
	{
		return false;
	}
}