// a4.cpp

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

#include "a4.h"  // no other includes are allowed!

using namespace std;

int sum_of_squares(int n)
{
    if (n < 0) //pre-condition check
    {
        cmpt::error("Error: sum_of_squares(), n must be greater or euqal to zero");
    }

    if (n == 0) //base case
    {
        return 0;
    }
    return (n * n) + sum_of_squares(n - 1); //recursive step
}

void sum_of_squares_test()
{
    cout << "\nTest sum_of_squares(): "; 

    assert(sum_of_squares(0) == 0);
    assert(sum_of_squares(5) == 55);

	cout << "passed";
}

int count_strange(int n)
{
    if (n <= 0) //pre-condition check
    {
        cmpt::error("Error: count_strange(), n must be greater than zero");
    }

    if (n == 1) //base case
    {
        return 1;
    }
    else if (n % 2 == 0 || n % 5 == 0)
    {
        return count_strange(n - 1); //recursive case
    }
    else
    {
        return count_strange(n - 1) + 1; //recursive case
    }
}

void count_strange_test()
{
    cout << "\nTest count_strange(): "; 

    assert(count_strange(11) == 5);
    assert(count_strange(15) == 6);

	cout << "passed";
}

bool all_sfu(const string& s)
{
    if (s == "" || s.size() <= 1) //base case
    {
        return true;
    }
    else if (s[0] == 's' || s[0] == 'f' || s[0] == 'u') //recursive case
    {
        string newStr(s.begin() + 1, s.end());
        return all_sfu(newStr);
    }

    return false;
}

void all_sfu_test()
{
    cout << "\nTest all_sfu(): "; 

    assert(all_sfu("") == true);
    assert(all_sfu("ssfuuu") == true);
    assert(all_sfu("ssfouu") == false);

	cout << "passed";
}

bool is_int(const string& s)
{
    if (s == "" || (s[0] == '-' && s[1] == '-')) //base case
    {
        return false;
    }
    else if (s.size() == 1 && s[0] >= 48 && s[0] <= 57) //base case
    {
        return true;
    }
    else if ((s[0] >= 48 && s[0] <= 57) || s[0] == '-') //recursive case
    {
        string newStr(s.begin() + 1, s.end());
        return is_int(newStr);
    }

    return false;
}

void is_int_test()
{
    cout << "\nTest is_int(): "; 

    assert(is_int("") == false);
    assert(is_int("--") == false);
    assert(is_int("12345") == true);

	cout << "passed";
}

string strip(const string& s)
{
    if (s[0] == ' ') //recursive case
    {
        string newStr(s.begin() + 1, s.end());
        return strip(newStr);
    }
    else if (s[s.size() - 1] == ' ') //recursive case
    {
        string newStr(s.begin(), s.end() - 1);
        return strip(newStr);
    }
    else if (s == "") //base case
    {
        return "";
    }
    else //base case
    {
        return s;
    }
}

void strip_test()
{
    cout << "\nTest strip(): "; 

    assert(strip("") == "");
    assert(strip("  ab c d ") == "ab c d");
    assert(strip("      ") == "");

	cout << "passed";
}

int sum_neg(const vector<int>& v)
{
    vector <int> copyVec = v;

    if (copyVec.size() == 0) //base case
    {
        return 0;
    }
    else if (copyVec[copyVec.size() - 1] < 0) //recursive case
    {
        int temp = copyVec[copyVec.size() - 1];
        copyVec.pop_back();
        return temp + sum_neg(copyVec);
    }
    else //recursive case
    {
        copyVec.pop_back();
        return sum_neg(copyVec);
    }
}

void sum_neg_test()
{
    cout << "\nTest sum_neg(): ";

    vector <int> a = {1, 2, 3, 4, 5};
    vector <int> b = {1, -2, 3, 4, -5};
    vector <int> c = {-1, -2, -3, -4, -5};

    assert(sum_neg(a) == 0);
    assert(sum_neg(b) == -7);
    assert(sum_neg(c) == -15);

	cout << "passed";
}

vector<int> max_vec(const vector<int>& a, const vector<int>& b)
{
    vector <int> aCopy = a;
    vector <int> bCopy = b;

    if (bCopy.size() == 0) //base case
    {
        return aCopy;
    }
    else if (aCopy[bCopy.size() - 1] >= bCopy[bCopy.size() - 1]) //base case
    {
        bCopy.pop_back();
    }
    else if (aCopy[bCopy.size() - 1] < bCopy[bCopy.size() - 1]) //recursive case
    {
        aCopy[bCopy.size() - 1] = bCopy[bCopy.size() - 1];
        bCopy.pop_back();
    }
    
    return max_vec(aCopy, bCopy);
}

void max_vec_test()
{
    cout << "\nTest max_vec(): ";

    vector <int> a = {4, 2, 7};
    vector <int> b = {-3, 7, 0};
    vector <int> c = {5, 1, 9};

    vector <int> ab = {4, 7, 7};
    vector <int> bc = {5, 7, 9};
    vector <int> ca = {5, 2, 9};

    assert(max_vec(a, b) == ab);
    assert(max_vec(b, c) == bc);
    assert(max_vec(c, a) == ca);

	cout << "passed";
}

int count(const vector<string>& v, const string& s)
{
    vector <string> copyVec = v;
 
    if (v.size() == 0) //base case
    {
        return 0;
    }

    copyVec.pop_back();

    if (v[v.size() - 1] == s) //recursive case
    {
        return count(copyVec, s) + 1;
    }

    return count(copyVec, s);
}

void count_test()
{
    cout << "\nTest count(): ";

    vector <string> vec1 = {"peter", "bob", "zack"};
    vector <string> vec2 = {"peter", "peter", "bob"};
    vector <string> vec3 = {"peter", "peter", "peter"};

    assert(count(vec1, "harold") == 0);
    assert(count(vec2, "peter") == 2);
    assert(count(vec3, "peter") == 3);

	cout << "passed";
}

vector<string> zip(const string& s, const string& t)
{
    //incomplete
    vector <string> empty;
    string sCopy = s; //to get rid of compilation warning
    string tCppy = t; //to get rid of compilation warning
    return empty;
}

void zip_test()
{
    cout << "\nTest zip(): ";

    string a = "peter";
    string b = "bobob";
    string c = "seven";

    vector <string> ab = {"pb", "eo", "tb", "eo", "rb"};
    vector <string> ac = {"ps", "ee", "tv", "ee", "rn"};
    vector <string> bc = {"bs", "oe", "bv", "oe", "bn"};

    assert(zip(a, b) == ab);
    assert(zip(a, c) == ac);
    assert(zip(b, c) == bc);

	cout << "passed";
}

string join(const vector<string>& v, const string& sep)
{
    //incomplete
    string empty;
    vector vCopy = v; //to get rid of compilation warning
    string sepCopy = sep; //to get rid of compilation warning
    return empty;
}

void join_test()
{
    cout << "\nTest join(): ";

    vector <string> vec1 = {"peter", "banana", "bob"};
    vector <string> vec2 = {"fly", "walk", "run"};
    vector <string> vec3 = {"moose", "turtle", "deer"};

    assert(join(vec1, "-") == "peter-banana-bob");
    assert(join(vec2, ", ") == "fly, walk, run");
    assert(join(vec3, "") == "mooseturtledeer");

	cout << "passed";
}
//
// Don't put main() in this file. It goes in a4_main.cpp.
//