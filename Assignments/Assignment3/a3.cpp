// a3.cpp

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

#include "cmpt_error.h"    //
#include "List_base.h"     // These are the only permitted #includes!
#include <iostream>        //
#include <string>          // Don't #include anything else.
#include <vector>          //
#include <cassert>

using namespace std;

// test functions
void bulleted_list_to_str_test();
void bulleted_list_to_html_str_test();
void numbered_list_to_str_test();
void numbered_list_to_html_str_test();

class Bulleted_list : public List_base //class Bulleted_list inherits from List_base
{
    private:
        vector <string> list; //underlying vector of strings
        string bullet; //bullet for each string

        void swap(string& a, string& b) //custom function to swap strings in the list (not in assignment requirements)
        {
            string tempStr = a;
            a = b;
            b = tempStr;
        }

    public:
        Bulleted_list() //default constructor
        : list(0), bullet("- ")
        {
            set_indent(0);
        }

        void set_bullet(string s) //sets bullet to desired string
        {
            bullet = s;
        }

        string get_bullet() const //returns bullet
        {
            return bullet;
        }

        int size() const //returns size of the list
        {
            return list.size();
        }

        string get(int i) const //returns an element at specified index (i) without bullet or indentation
        {
            if (i < 0 || i >= list.size())
            {
                cmpt::error("Error: get(), argument out of bounds");
            }
            return list[i];
        }

        void add_to_start(const string& item) //adds item to the beginning of the list and automatically shifts other items up
        {
            list.insert(list.begin(), item);
        }
        
        void add_to_end(const string& item) //adds item to the end of the list
        {
            list.push_back(item);
        }

        void reverse_order() //reverses the order of the list
        {
            for (int count = 0; count < list.size() / 2; ++count)
            {
                swap(list[count], list[list.size() - count - 1]);
            }
        }

        string to_str() const //returns a string containing the contents of the list inclusing indentation and bullet
        {
            string s = "";

            for (int count = 0; count < list.size(); ++count)
            {
                s += get_indent();
                s += bullet;
                s += list[count];

                s += '\n';
            }
            return s;
        }

        string to_html_str() const //returns an html version of the list without custom indentation and bullets
        {
            string s = "";

            s += "<ul>\n";

            for (int count = 0; count < list.size(); ++count)
            {
                s += "  <li>";
                s += list[count];
                s += "</li>\n";
            }
            s += "</ul>\n";
            return s;
        }

        virtual ~Bulleted_list() //destructor, empty because nothing was allocated to the free store
        { }
};

class Numbered_list : public List_base
{
    private:
        vector <string> list;
        string numSeparator;
        int startNumber;
        int timesReversed;

    public:
        Numbered_list() //default constructor
        : list(0), numSeparator(". "), startNumber(1), timesReversed(0)
        { 
            set_indent(0);
        }

        int size() const //returns size of the list
        {
            return list.size();
        }

        string get(int i) const //returns an element at specified index (i) without bullet or indentation
        {
            if (i < 0 || i >= list.size())
            {
                cmpt::error("Error: get(), argument out of bounds");
            }
            return list[i];
        }

        void add_to_start(const string& item) //adds item to the beginning of the list and automatically shifts other items up
        {
            list.insert(list.begin(), item);
        }
        
        void add_to_end(const string& item) //adds item to the end of the list
        {
            list.push_back(item);
        }

        void reverse_order() //reverses the order of the list, takes into account the numbering of the elements
        {
            for (int count = 0; count < list.size() / 2; ++count)
            {
                swap(list[count], list[list.size() - count - 1]);
            }
            ++timesReversed;
        }

        void set_start_num(int num) //sets the starting number of the list
        {
            startNumber = num;
        }

        int get_start_num() const //returns the starting number of the list
        {
            return startNumber;
        }

        void set_num_sep(string sep) //sets a separator between numbers and items in the list
        {
            numSeparator = sep;
        }

        string get_num_sep() const //returns the separator between numbers and items in the list
        {
            return numSeparator;
        }

        string to_str() const //returns a string representation of the list including numbering and indentation
        {
            string s = "";

            for (int count = 0; count < list.size(); ++count)
            {
                if (timesReversed % 2 == 0)
                {
                    s += to_string(startNumber + count);
                }
                else
                {
                    s += to_string(list.size() - count + startNumber - 1);
                }
                s += numSeparator;
                s += list[count];
                s += '\n';
            }
            return s;
        }

        string to_html_str() const //returns a string representation of a html version of the list including the display of whether the list is reversed
        {
            string s = "";

            if (timesReversed % 2 == 0)
            {
                s += "<ol>\n";
            }
            else
            {
                s += "<ol reversed>\n";
            }

            for (int count = 0; count < list.size(); ++count)
            {
                s += "  <li>";
                s += list[count];
                s += "</li>\n";
            }
            s += "</ol>\n";
            return s;
        }

        virtual ~Numbered_list() //destructor, empty because nothing was allocated to the free store
        { }
};

int main()
{
    bulleted_list_to_str_test();
    bulleted_list_to_html_str_test();
    cout << '\n';
    numbered_list_to_str_test();
    numbered_list_to_html_str_test();
    cout << "\n\n";

    system("pause");
}

void bulleted_list_to_str_test() //test function for to_str() function in the Bulleted_list class
{
    Bulleted_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    lst.set_bullet("> ");
    lst.reverse_order();
    
	cout << "\nTest Bulleted_list to_str(): ";    

	assert(lst.to_str() == "> grapes\n> pears\n> oranges\n> apples\n");
	cout << "passed";
}

void bulleted_list_to_html_str_test() //test function for to_html_str() function in the Bulleted_list class
{
    Bulleted_list lst;

    lst.add_to_end("peter");
    lst.add_to_end("armadillo");
    lst.add_to_end("cpp");
    lst.add_to_start("hello");
    
	cout << "\nTest Bulleted_list to_html_str(): ";

	assert(lst.to_html_str() == "<ul>\n  <li>hello</li>\n  <li>peter</li>\n  <li>armadillo</li>\n  <li>cpp</li>\n</ul>\n");
	cout << "passed";
}

void numbered_list_to_str_test() //test function for to_str() function in the Numbered_list class
{
    Numbered_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    lst.reverse_order();
    
	cout << "\nTest Numbered_list to_str(): ";    

	assert(lst.to_str() == "4. grapes\n3. pears\n2. oranges\n1. apples\n");
	cout << "passed";
}

void numbered_list_to_html_str_test() //test function for to_html_str() function in the Numbered_list class
{
    Numbered_list lst;

    lst.add_to_end("peter");
    lst.add_to_end("armadillo");
    lst.add_to_end("cpp");
    lst.add_to_start("hello");
    
	cout << "\nTest Numbered_list to_html_str(): ";

	assert(lst.to_html_str() == "<ol>\n  <li>hello</li>\n  <li>peter</li>\n  <li>armadillo</li>\n  <li>cpp</li>\n</ol>\n");

    lst.reverse_order();

    assert(lst.to_html_str() == "<ol reversed>\n  <li>cpp</li>\n  <li>armadillo</li>\n  <li>peter</li>\n  <li>hello</li>\n</ol>\n");
	cout << "passed";
}