#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aircraft.cpp"
using namespace std;

class Database //database class which creates a vector of Record objects and has menus and other functionality
{
    private:
        unsigned int currentAircraftIndex; //starts at 1
        vector <Aircraft> aircraft; //create vector which contains records for each aircraft

        int sToI(string str) //string to int conversion funciton
        {
            int temp = 0;
            for (int count = 0; count < str.length(); ++count) 
            {
                temp = temp * 10 + (str[count] - '0');
            }
            return temp;
        }

    public:
        Database() //default constructor
        {
            currentAircraftIndex = 0;
        }

        vector <Aircraft>& dataVector() //returns the vector which contains the records for each aircraft
        {
            return aircraft;
        }

        Aircraft& getDatabaseRecord(int index) //returns Record object from the database index
        {
            return aircraft[index];
        }

        int getDatabaseSize() const //returns size of database
        {
            return aircraft.size();
        }

        void newRecord() //create a new record and adds it to the database
        {
            Aircraft newAircraft;
            aircraft.push_back(newAircraft);
        }

        void readFile() //read the database.txt file and add the information into the database
        {
            string str;
            vector <string> list;

            ifstream file;
            file.open("C:\\Users\\Daniel\\Documents\\Code\\C++\\CMPT-135\\Assignments\\Assignment5\\database.txt", ios::in);

            while (getline(file, str))	//input file contents into vector
            {
                list.push_back(str);
            }

            int recordCount = 0;

            for (int count = 0; count < list.size(); ++count)
            {
                if (count % 5 == 0)
                {
                    newRecord();
                    ++recordCount;
                    getDatabaseRecord(recordCount - 1).setName(list[count]);
                }
                else if (count % 5 == 1)
                {
                    getDatabaseRecord(recordCount - 1).setType(list[count]);
                }
                else if (count % 5 == 2)
                {
                    getDatabaseRecord(recordCount - 1).setCountry(list[count]);
                }
                else if (count % 5 == 3)
                {
                    getDatabaseRecord(recordCount - 1).setWeight(sToI(list[count]));
                }
                else if (count % 5 == 4)
                {
                    getDatabaseRecord(recordCount - 1).setSpeed(sToI(list[count]));
                }
            }
        }

        virtual ~Database() //virtual destructor
        {
            //empty because no dynamic memmory allocation was used
        }
};