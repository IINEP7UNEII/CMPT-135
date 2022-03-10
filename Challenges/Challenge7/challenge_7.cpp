// challenge_7.cpp

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

int findLargestCol(vector <int>);

int main() 
{
	cout << "Challenge 7 ...\n";

	const int numOfColumns = 500;

	string str;
	vector <string> list;

	ifstream file;
    file.open("C:\\Users\\Daniel\\Documents\\Code\\C++\\CMPT-135\\Challenges\\Challenge7\\bits7.txt", ios::in);

	while (file >> str)
    {
        list.push_back(str);
	}

	vector <int> col;

	for (int count = 0; count < numOfColumns; ++count)
	{
		col.push_back(0);
	}

	for (int r = 0; r < list.size(); ++r) //r for row
	{
		for (int c = 0; c < numOfColumns; ++c) //c for column
		{
			col[c] += (list[r][c] - 48); // subract 48 to convert char to int
		}
	}

	cout << "Index: " << findLargestCol(col);
	cout << "\nNumber: " << findLargestCol(col) + 1;
	cout << "\nSum: " << col[findLargestCol(col)];
	cout << "\n\n";
	
	system("pause");
}

int findLargestCol(vector <int> c)
{
	int largestIndex = 0;

	for (int count = 0; count < c.size(); ++count)
	{
		if (c[count] >= c[largestIndex])
		{
			largestIndex = count;
		}
	}

	return largestIndex;
}