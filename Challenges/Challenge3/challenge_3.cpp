// challenge_3.cpp

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

bool containsChar(string, char);

int main() 
{
	cout << "Challenge 3 ...\n";
	
	string str;
	vector <string> strArray;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Coding Projects\\C++ Code\\enable1.txt", ios::in);

	int vowels[5] = {'a', 'e', 'i', 'o', 'u'};

	int numOfVowels = 0;
	int vowelWords = 0;

	while (file >> str)
    {
        strArray.push_back(str);
    }

	for (int count1 = 0; count1 < strArray.size(); ++count1)
    {
        for (int count2 = 0; count2 < str.length(); ++count2)
		{
			if (containsChar(strArray[count1], vowels[count2]))
			{
				++numOfVowels;
			}
		}

		if (numOfVowels == 5)
		{
			++vowelWords;
		}
		numOfVowels = 0;
    }

	cout << vowelWords << endl;

	system("pause");
}

bool containsChar(string word, char letter)
{
	for (int count = 0; count < word.length(); ++count)
	{
		if (letter == word[count])
		{
			return true;
		}
	}
	return false;
}
