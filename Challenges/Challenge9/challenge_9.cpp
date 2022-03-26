// challenge_9.cpp

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

string alphabeticalCharSort(string);
void swapChar(char&, char&);
void swapString(string&, string&);
void swapInt(int&, int&);

struct Word
{
	string original;
    string alphabetical;
	int alphabeticalIndex;

    Word()
    {
        original = "";
		alphabetical = "";
		alphabeticalIndex = 0;
    }
};

int main() 
{
	cout << "Challenge 9 ...\n";

	string str;
	vector <string> list;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Code\\C++\\CMPT-135\\Challenges\\Challenge9\\words9.txt", ios::in);

	while (file >> str)	//input file contents into vector
    {
        list.push_back(str);
	}

	cout << "\nSorting and searching through list...\nthis may take some time...\n";

	Word *words = new Word[list.size()]; //create array of word objects
	int fourOrLessCount = 0;

	for (int count = 0; count < list.size(); ++count)
	{
		words[count].original = list[count]; //assign original word

		if (list[count].size() > 4)
		{
			words[count].alphabetical = alphabeticalCharSort(list[count]);
			words[count].alphabeticalIndex = fourOrLessCount;
			++fourOrLessCount;
		}
	}

	for (int count1 = 0; count1 < fourOrLessCount; ++count1) //sort array of strings alphabetically
	{
		for (int count2 = 1; count2 < fourOrLessCount - count1; ++count2)
		{
			if (words[count2 - 1].alphabetical > words[count2].alphabetical)
			{
				swapString(words[count2 - 1].alphabetical, words[count2].alphabetical);
				swapInt(words[count2 - 1].alphabeticalIndex, words[count2].alphabeticalIndex);
			}
		} 
	}

	int numToExtract = 12345;

	for (int count = 0; count < fourOrLessCount; ++count) //extract number at index 12345 post sort
	{
		if (words[count].alphabeticalIndex == numToExtract)
		{
			cout << "\nThe word is: " << words[count].original << endl;
			break;
		}
	}

	delete[] words;
	system("pause");
}

string alphabeticalCharSort(string s)
{
	for (int count1 = 0; count1 < s.size(); ++count1)
    {
        for (int count2 = 1; count2 < s.size() - count1; ++count2)
        {
            if (s[count2 - 1] > s[count2])
            {
				swapChar(s[count2 - 1], s[count2]);
            }
        }
    }
	return s;
}

void swapInt(int& s1, int& s2)
{
	int temp = s1;
    s1 = s2;
    s2 = temp;
}

void swapChar(char& s1, char& s2)
{
	char temp = s1;
    s1 = s2;
    s2 = temp;
}

void swapString(string& s1, string& s2)
{
	string temp = s1;
    s1 = s2;
    s2 = temp;
}