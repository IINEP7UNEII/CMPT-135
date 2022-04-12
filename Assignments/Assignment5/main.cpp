/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Daniel Tolsky
// St.# : 301452597
// Email: daniel_tolsky@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include "Menu.cpp"
using namespace std;

int main()
{
    Menu data; //initialize the database

    data.startMenu(); //open start menu of database
    data.readFile(); //read file "database.txt" for some sample records

    while (true) //program loop
    {
        data.excecuteMenuChoice(data.mainMenu()); //open main menu and excecute user choice in menu
    }

    return 0;
}