// challenge_6.cpp

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

void displaySortString (vector <char>, vector <int>);

struct Letters 
{
    vector <char> letter;
    vector <int> letterCount;
    const int ascii_a = 97;
    const int lettersInAlphabet = 26;

    Letters() 
    {
        for (int count = 0; count < lettersInAlphabet; ++count)
        {
            letter.push_back(count + ascii_a);
        }

        for (int count = 0; count < lettersInAlphabet; ++count)
        {
            letterCount.push_back(0);
        }
    }
};

int main() 
{
	cout << "Challenge 6 ...\n";

	string str;
	vector <string> list;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Coding Projects\\C++ Code\\words6.txt", ios::in);

	while (file >> str)
    {
        list.push_back(str);
	}

    Letters letters;

    for (int listCount = 0; listCount < list.size(); ++listCount)
    {
        for (int stringCount = 0; stringCount < list[listCount].length(); ++stringCount)
        {
            ++letters.letterCount[list[listCount].at(stringCount) - letters.ascii_a];
        }
    }

    for (int count = 0; count < letters.letter.size(); ++count)
    {
        cout << letters.letter[count] << "   " << letters.letterCount[count] << endl;
    }

    cout << "\n\n";

    displaySortString (letters.letter, letters.letterCount);

	system("pause");
}

void displaySortString (vector <char> letter, vector <int> letterCount)
{
    vector <int> unsortedCount = letterCount;
    string displayString = "";

    sort(letterCount.begin(), letterCount.end());

    for (int count1 = 0; count1 < letterCount.size(); ++count1)
    {
        for (int count2 = 0; count2 < letterCount.size(); ++count2)
        {
            if (letterCount[count1] == unsortedCount[count2])
            {
                displayString += letter[count2];
            }
        }
    }

    reverse(displayString.begin(), displayString.end());
    cout << displayString << endl;
}