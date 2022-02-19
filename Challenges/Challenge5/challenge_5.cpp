// challenge_5.cpp

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

double getA(vector <double>);
double getB(vector <double>);
int numbersInLine(string);

int main() 
{
	cout << "Challenge 5 ...\n";

	string str;
	vector <string> list;
	vector <double> doubleNum;
	string line = "";
	string strNum = "";

	vector <double> maxs;
	vector <double> mins;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Coding Projects\\C++ Code\\numbers5.txt", ios::in);

	while (getline(file, str))
    {
        list.push_back(str);
	}

	int stringCount = 0;

	for (int listCount = 0; listCount < list.size(); ++listCount) //go through list of lines
	{
		line = list[listCount];

		for (int lineCount = 0; lineCount < numbersInLine(line); ++lineCount) // split line into strings
		{
			while (stringCount < line.length() && line[stringCount] != ',' && line[stringCount] != ' ') //go through string
			{
				strNum += line[stringCount];
				++stringCount;
			}
			//cout << strNum << endl;
			stringCount += 2; // skip comma and space
			doubleNum.push_back(stod(strNum));
			strNum = "";
		}
		sort(doubleNum.begin(), doubleNum.end()); //sort ascending
		maxs.push_back(doubleNum[doubleNum.size() - 1]);
		mins.push_back(doubleNum[0]);
		doubleNum.clear();
		stringCount = 0;
	}

	cout << "A: " << getA(maxs);
	cout << "\nB: " << getB(mins);

	cout << "\n\n";
	system("pause");
}

double getA(vector <double> vec)
{
	sort(vec.begin(), vec.end());
	return vec[0];
}

double getB(vector <double> vec)
{
	sort(vec.begin(), vec.end());
	return vec[vec.size() - 1];
}

int numbersInLine(string s)
{
	int commaCount = 0;

	for (int count = 0; count < s.length(); ++count)
	{
		if (s[count] == ',')
		{
			++commaCount;
		}
	}

	return commaCount + 1; //returns number of doubles in string
}