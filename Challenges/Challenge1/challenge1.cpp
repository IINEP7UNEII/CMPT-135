// challenge_1.cpp

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

//
// ... add any helper functions (write them yourself!) here ...
//

bool containsThree(string);

int main() 
{
	cout << "Challenge 1 ...\n";
	
    string num;
    vector <string> numArray;
    int sum = 0;

    ifstream file;
    file.open("numbers1.txt", ios::in);

    while (file >> num)
    {
        numArray.push_back(num);
    }

    for (int count = 0; count < numArray.size(); ++count)
    {
        if (!containsThree(numArray[count]))
        {
            sum += stoi(numArray[count]);
        }
    }

    cout << sum;

    system("pause");
}

bool containsThree(string num)
{
    for (char digit : num) 
    {
        if (digit == '3')
        {
            return true;
        }
    }
    return false;
}