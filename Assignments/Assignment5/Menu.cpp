#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Database.cpp"
using namespace std;

class Menu : public Database //Menu class which inherits from the Database class
{
    private:
        //no private variables were needed for this class

        void swap(Aircraft &a, Aircraft &b) //swap function to swap Aircraft objects in vector
        {
            Aircraft temp = a;
            a = b;
            b = temp;
        }
        
        void bubbleSortString(vector <Aircraft>& vec, int field) //sort Aircraft vector
        {
            bool swapped;
            for (int a = 0; a < vec.size() - 1; ++a)
            {
                swapped = false;
                for (int b = 0; b < vec.size() - a - 1; ++b)
                {
                    if (field == 1)
                    {
                        if (vec[b].getName() > vec[b + 1].getName())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 2)
                    {
                        if (vec[b].getType() > vec[b + 1].getType())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 3)
                    {
                        if (vec[b].getCountry() > vec[b + 1].getCountry())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                }
            
                if (swapped == false)
                {
                    break;
                }
            }
        }

        void bubbleSortStringReversed(vector <Aircraft>& vec, int field)  //sort Aircraft vector
        {
            bool swapped;
            for (int a = 0; a < vec.size() - 1; ++a)
            {
                swapped = false;
                for (int b = 0; b < vec.size() - a - 1; ++b)
                {
                    if (field == 1)
                    {
                        if (vec[b].getName() < vec[b + 1].getName())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 2)
                    {
                        if (vec[b].getType() < vec[b + 1].getType())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 3)
                    {
                        if (vec[b].getCountry() < vec[b + 1].getCountry())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                }
            
                if (swapped == false)
                {
                    break;
                }
            }
        }

        void bubbleSortInt(vector <Aircraft>& vec, int field)  //sort Aircraft vector
        {
            bool swapped;
            for (int a = 0; a < vec.size() - 1; ++a)
            {
                swapped = false;
                for (int b = 0; b < vec.size() - a - 1; ++b)
                {
                    if (field == 1)
                    {
                        if (vec[b].getWeight() > vec[b + 1].getWeight())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 2)
                    {
                        if (vec[b].getSpeed() > vec[b + 1].getSpeed())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                }
            
                if (swapped == false)
                {
                    break;
                }
            }
        }

        void bubbleSortIntReversed(vector <Aircraft>& vec, int field)  //sort Aircraft vector
        {
            bool swapped;
            for (int a = 0; a < vec.size() - 1; ++a)
            {
                swapped = false;
                for (int b = 0; b < vec.size() - a - 1; ++b)
                {
                    if (field == 1)
                    {
                        if (vec[b].getWeight() < vec[b + 1].getWeight())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                    else if (field == 2)
                    {
                        if (vec[b].getSpeed() < vec[b + 1].getSpeed())
                        {
                            swap(vec[b], vec[b + 1]);
                            swapped = true;
                        }
                    }
                }
            
                if (swapped == false)
                {
                    break;
                }
            }
        }

        string inputStringHandle() //handle input
        {
            string tempStr;
            cin >> tempStr;
            while (tempStr == "") 
            {
                cerr << "ERROR: Input string must not be empty!\n";
                cerr << "Enter string again: ";
                if (cin.fail()) 
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cin >> tempStr;
                }
            }
            cin.ignore(10000, '\n');
            return tempStr;
        }

        int inputIntHandle() //handle input
        {
            int tempInt;
            cin >> tempInt;
            while (tempInt <= 0 || cin.fail()) 
            {
                cerr << "ERROR: Input integer must be a number not be less than or equal to 0!\n";
                cerr << "Enter integer again: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> tempInt;
            }
            cin.ignore(10000, '\n');
            return tempInt;
        }

        char inputCharHandle() //handle input
        {
            char tempChar;
            cin >> tempChar;
            while (cin.fail()) 
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> tempChar;
            }
            cin.ignore(10000, '\n');
            return tempChar;
        }

    public:
        Menu() //default constructor
        {
            //nothing to initialize as all parameters are inherited from the Database class
        }

        void startMenu() //start menu of program
        {   
            char cont = ' ';
            cout << "___________________________________\n";
            cout << "*Welcome to the aircraft database!*\n";
            cout << "***********************************\n\n\n";

            cout << "Enter y/Y key to continue, or any other key to quit: ";
            cont = inputCharHandle();

            if (cont != 'y' && cont != 'Y')
            {
                exit(0);
            }
            clearScreen();
        }

        int mainMenu() //main menu of program where all options are shown
        {
            int choice = 0;
            cout << "Please choose an option:\n";
            cout << "************************\n\n";

            cout << "1. Add aircraft to database\n";
            cout << "2. Find an aircraft in the database\n";
            cout << "3. Delete aircraft from database\n";
            cout << "4. List all aircraft in the database\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            choice = inputIntHandle();

            clearScreen();
            return choice;
        }

        void fieldsInputMenu(unsigned int index) //menu where the user is prompted to input information for a new record
        {
            --index;
            string inputString = "";

            cout << "Information input menu\n";
            cout << "**********************\n\n";

            cout << "Input aircraft name: ";
            inputString = inputStringHandle();
            while (alreadyInDatabase(inputString))
            {
                cerr << "\nERROR: Aircraft already in database. Input aircraft name agian: ";
                inputString = inputStringHandle();
            }
            getDatabaseRecord(index).setName(inputString);
            
            cout << "\nInput aircraft type: ";
            getDatabaseRecord(index).setType(inputStringHandle());

            cout << "\nInput aircraft country of origin: ";
            getDatabaseRecord(index).setCountry(inputStringHandle());

            cout << "\nInput aircraft weight (kg): ";
            getDatabaseRecord(index).setWeight(inputIntHandle());

            cout << "\nInput aircraft top speed (km/h): ";
            getDatabaseRecord(index).setSpeed(inputIntHandle());

            cout << "\n\nRecord has been added successfully!";

            leavePrompt();
        }

        void findRecordMenu() //menu where searching for a record is performed
        {
            char input = ' ';

            cout << "Finding record menu\n";
            cout << "*******************\n\n";

            cout << "1. Find aircraft by index\n";
            cout << "2. Find aircraft by string\n\n";

            cout << "Enter search method, or any other number to return to main menu: ";
            input = inputCharHandle();

            if (input == '1')
            {
                int index = 0;
                cout << "\n\nEnter aircraft index: ";
                index = inputIntHandle();

                while (index < 1 || index > getDatabaseSize())
                {
                    cerr << "\nERROR: Enter aircraft index greater than 0 and less than " << getDatabaseSize() << ": ";
                    index = inputIntHandle();
                }
                displayAircraftFeildsMenu(index);
                leavePrompt();
            }
            else if (input == '2')
            {
                string inputString = "";
                cout << "\n\nEnter aircraft string: ";
                inputString = inputStringHandle();

                if (alreadyInDatabase(inputString))
                {
                    for (int count = 0; count < getDatabaseSize(); ++count)
                    {
                        if (inputString == getDatabaseRecord(count).getName())
                        {
                            displayAircraftFeildsMenu(count);
                            leavePrompt();
                        }
                    }
                } //continue make changes for finding record like substring search
                else if (subStringInDatabase(inputString))
                {
                    for (int count = 0; count < getDatabaseSize(); ++count)
                    {
                        if (getDatabaseRecord(count).getName().find(inputString) != string::npos)
                        {
                            displayAircraftFeildsMenu(count);
                        }
                    }
                    leavePrompt();
                }
                else
                {
                    cout << "\n\nString was not found in the database!\n";
                    leavePrompt();
                }
            }
        }

        void displayAircraftFeildsMenu(int index) //display record informartion
        {
            cout << "\n\nRecord information\n";
            cout << "******************\n\n";
            
            cout << "Aircraft name: " << getDatabaseRecord(index).getName();
            cout << "\nType: " << getDatabaseRecord(index).getType();
            cout << "\nCountry of origin: " << getDatabaseRecord(index).getCountry();
            cout << "\nWeight (kg): " << getDatabaseRecord(index).getWeight();
            cout << "\nTop speed (km/h): " << getDatabaseRecord(index).getSpeed();
        }

        bool alreadyInDatabase(string name) //checks whether a string is already in the database
        {
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                if (name == getDatabaseRecord(count).getName())
                {
                    return true;
                }
            }
            return false;
        }

        bool subStringInDatabase(string subString) //checks whether a subString is in the database
        {
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                if (getDatabaseRecord(count).getName().find(subString) != string::npos)
                {
                    return true;
                }
            }
            return false;
        }

        void deleteRecordMenu() //menu where the user is given options to delete a record from the database
        {
            char choice = ' ';

            cout << "Delete record menu\n";
            cout << "******************\n\n";

            cout << "1. Find aircraft by int\n";
            cout << "2. Find aircraft by string\n\n";

            cout << "Enter search method, or any other number to return to main menu: ";
            choice = inputCharHandle();

            if (choice == '1')
            {
                int index = 0;
                cout << "\n\nEnter aircraft index: "; //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
                index = inputIntHandle();

                while (index < 1 || index > getDatabaseSize())
                {
                    cerr << "\nERROR: Enter aircraft index greater than 0 and less than " << getDatabaseSize() << ": ";
                    index = inputIntHandle();
                }
                deleteRecord(index);
            }
            else if (choice == '2')
            {
                string inputString = "";
                cout << "\n\nEnter aircraft string: ";
                inputString = inputStringHandle();

                if (alreadyInDatabase(inputString))
                {
                    for (int count = 0; count < getDatabaseSize(); ++count)
                    {
                        if (inputString == getDatabaseRecord(count).getName())
                        {
                            deleteRecord(count);
                        }
                    }
                }
                else if (subStringInDatabase(inputString))
                {
                    for (int count = 0; count < getDatabaseSize(); ++count)
                    {
                        if (getDatabaseRecord(count).getName().find(inputString) != string::npos)
                        {
                            deleteRecord(count);
                        }
                    }
                    leavePrompt();
                }
                else
                {
                    cout << "\n\nString was not found in the database!\n";
                }
            }
            leavePrompt();
        }

        void deleteRecord(int index) //delete record function
        {
            // erase the 6th element
            dataVector().erase(dataVector().begin() + index - 1);

            cout << "\n\nRecord has been successfully deleted!\n";
        }

        void listRecordsMenu() //menu where the user is given options to list the database records
        {
            int choice = 0;
            cout << "List aircraft records menu\n";
            cout << "**************************\n\n";

            cout << "1. List aircraft by string\n";
            cout << "2. List aircraft by int\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            choice = inputIntHandle();

            if (choice != 1 && choice != 2)
            {
                exit(0);
            }
            else if (choice == 1)
            {
                listByStringMenu();
            }
            else if (choice == 2)
            {
                listByIntMenu();
            }
        }

        void listByStringMenu() //menu which given option to list the records using string fields
        {
            clearScreen();
            int field = 0;
            int order = 0;
            cout << "List aircraft by string menu\n";
            cout << "***************************\n\n";

            cout << "1. List aircraft by name\n";
            cout << "2. List aircraft by type\n";
            cout << "3. List aircraft by country\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            field = inputIntHandle();

            cout << "\n\nWould you like to list records alphabetically or in reverse alpabetical order?\n";
            cout << "1. List aircraft alphabeticaly\n";
            cout << "2. List aircraft reverse alpabetically\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            order = inputIntHandle();

            if (field != 1 && field != 2 && field != 3 && order != 1 && order != 2)
            {
                exit(0);
            }
            else if (field == 1)
            {
                clearScreen();
                if (order != 1 && order != 2)
                {
                    exit(0);
                }
                else if (order == 1)
                {
                    listAlphabetically(field);
                    leavePrompt();
                }
                else if (order == 2)
                {
                    listReverseAlphabetically(field);
                    leavePrompt();
                }
            }
            else if (field == 2)
            {
                clearScreen();
                if (order != 1 && order != 2)
                {
                    exit(0);
                }
                else if (order == 1)
                {
                    listAlphabetically(field);
                    leavePrompt();
                }
                else if (order == 2)
                {
                    listReverseAlphabetically(field);
                    leavePrompt();
                }
            }
            else if (field == 3)
            {
                clearScreen();
                if (order != 1 && order != 2)
                {
                    exit(0);
                }
                else if (order == 1)
                {
                    listAlphabetically(field);
                    leavePrompt();
                }
                else if (order == 2)
                {
                    listReverseAlphabetically(field);
                    leavePrompt();
                }
            }
        }

        void listByIntMenu() //menu which given option to list the records using int fields
        {
            clearScreen();
            int field = 0;
            int order = 0;
            cout << "List aircraft by integer menu\n";
            cout << "*****************************\n\n";

            cout << "1. List aircraft by weight\n";
            cout << "2. List aircraft by top speed\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            field = inputIntHandle();

            cout << "\n\nWould you like to list records in ascending or descending order?\n";
            cout << "1. List aircraft ascending order\n";
            cout << "2. List aircraft descending order\n";
            cout << "Any other number to quit\n\n";

            cout << "Enter a number from the options: ";
            order = inputIntHandle();

            if (field != 1 && field != 2 && field != 3)
            {
                exit(0);
            }
            else if (field == 1)
            {
                clearScreen();
                if (order != 1 && order != 2 && order != 3)
                {
                    exit(0);
                }
                else if (order == 1)
                {
                    listAscending(field);
                    leavePrompt();
                }
                else if (order == 2)
                {
                    listDescending(field);
                    leavePrompt();
                }
            }
            else if (field == 2)
            {
                clearScreen();
                if (order != 1 && order != 2)
                {
                    exit(0);
                }
                else if (order == 1)
                {
                    listAscending(field);
                    leavePrompt();
                }
                else if (order == 2)
                {
                    listDescending(field);
                    leavePrompt();
                }
            }
        }

        void listAlphabetically(int field) //creates a copy of the database to sort and display in alphabetical order
        {
            vector <Aircraft> sorted;
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                sorted.push_back(getDatabaseRecord(count));
            }

            bubbleSortString(sorted, field);

            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                displayRecord(sorted, count);
            }
        }

        void listReverseAlphabetically(int field) //creates a copy of the database to sort and display in reverse alphabetical order
        {
            vector <Aircraft> sorted;
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                sorted.push_back(getDatabaseRecord(count));
            }

            bubbleSortStringReversed(sorted, field);

            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                displayRecord(sorted, count);
            }
        }

        void listAscending(int field) //creates a copy of the database to sort and display in ascending order
        {
            vector <Aircraft> sorted;
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                sorted.push_back(getDatabaseRecord(count));
            }

            bubbleSortInt(sorted, field);

            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                displayRecord(sorted, count);
            }
        }

        void listDescending(int field) //creates a copy of the database to sort and display in descending order
        {
            vector <Aircraft> sorted;
            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                sorted.push_back(getDatabaseRecord(count));
            }

            bubbleSortIntReversed(sorted, field);

            for (int count = 0; count < getDatabaseSize(); ++count)
            {
                displayRecord(sorted, count);
            }
        }

        void displayRecord(vector <Aircraft> sorted, int index) //display record fields (information)
        {
            cout << sorted[index].getName() << '\n';
            cout << sorted[index].getType() << '\n';
            cout << sorted[index].getCountry() << '\n';
            cout << sorted[index].getWeight() << '\n';
            cout << sorted[index].getSpeed() << "\n\n";
        }

        void leavePrompt() //promts the user to exit program or return to menu
        {
            char input = ' ';
            cout << "\nEnter e/E to exit, or enter any other key to return to main menu: ";
            input = inputCharHandle();

            if (input == 'e' || input == 'E')
            {
                exit(0);
            }
        }

        void excecuteMenuChoice(int choice) //uses the user prompt from the menu to open the respective windows
        {
            switch (choice)
            {
                case 1:
                    newRecord();
                    clearScreen();
                    fieldsInputMenu(getDatabaseSize());
                    clearScreen();
                    break;

                case 2:
                    findRecordMenu();
                    clearScreen();
                    break;

                case 3:
                    deleteRecordMenu();
                    clearScreen();
                    break;

                case 4:
                    listRecordsMenu();
                    clearScreen();
                    break;

                default:
                    exit(0);
                    break;
            }
        }

        void clearScreen() //function which clears the screen from previous menus
        {
            cout << string(100, '\n');
        }

        virtual ~Menu() //virtual destructor
        {
            //empty because no dynamic memmory allocation was used
        }
};