CMPT 135 Final Project
======================

Names of Team Members
---------------------

Name: Daniel Tolsky
SFU email: dta71@sfu.ca
SFU ID: 301452597


Instructions for Compiling and Running
--------------------------------------

Compile:
g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o Aircraft.o Aircraft.cpp
g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o Database.o Database.cpp
g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o Menu.o Menu.cpp
g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o main.o main.cpp
g++ -o Aircraft_Database Aircraft.o Database.o Menu.o main.o

Run:
./Aircraft_Database


Limitations
-----------

When searching for numbers, one kind of search should print all
records where the typed-in number from the user exactly matches the
appropriate field of a record.

When searching for numbers, one kind of search should print all
records where the number the appropriate field of a record is in a range, from
low to high. This would, for example, let the user see all songs in a song
database from the year 2005 to 2015.

When deleting a record, one way to do this is to search by the
exact number that occurs in a field of the record.

When deleting a record, one way to do this is to search for
numbers in a field that appear in a low to high range of numbers.

Non-trivial use of the ncurses library to help draw nice-looking
menus. (could not get it to run on my computer)


Known Bugs
----------

No known bugs


Extra Features
--------------
Instead of searching database by integer field, we can search the 
database using the index of the record in the database

There is a start menu before the main menu
