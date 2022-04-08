// challenge_11.cpp

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

//
// ... add any helper functions (write them yourself!) here ...
//

int main() 
{
	cout << "Challenge 11 ...\n";

	unsigned int solutionCount = 0;
	int lowerLimit = -100;
	int upperLimit = 100;

	int aNum, bNum, cNum, dNum = 0;

	for (int a = lowerLimit; a <= upperLimit; a++)
	{
		for (int b = lowerLimit; b <= upperLimit; b++)
		{
			for (int c = lowerLimit; c <= upperLimit; c++)
			{
				for (int d = lowerLimit; d <= upperLimit; d++)
				{
					aNum = a * a * a;
					bNum = 2 * b * b;
					cNum = 10 * c;
					dNum = (d * d);

					if ((aNum - bNum + cNum - dNum) == -1)
					{
						++solutionCount;
					}
				}
			}
		}
	}

	cout << "\nThere are " << solutionCount << " solutions to this equation.\n";

	system("pause");
}
