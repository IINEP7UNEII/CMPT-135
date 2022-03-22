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
    if (n == 0)
    {
        return 0;
    }
    return (n * n) + sum_of_squares(n - 1);
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
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0 || n % 5 == 0)
    {
        return count_strange(n - 1);
    }
    else
    {
        return count_strange(n - 1) + 1;
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
    if (s == "" || s.size() <= 1)
    {
        return true;
    }
    else if (s[0] == 's' || s[0] == 'f' || s[0] == 'u')
    {
        string p(s.begin() + 1, s.end());
        return all_sfu(p);
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
    if (s == "" || (s[0] == '-' && s[1] == '-'))
    {
        return false;
    }
    else if (s.size() == 1 && s[0] >= 48 && s[0] <= 57)
    {
        return true;
    }
    else if ((s[0] >= 48 && s[0] <= 57) || s[0] == '-')
    {
        string p(s.begin() + 1, s.end());
        return is_int(p);
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
    if (s[0] == ' ')
    {
        string p(s.begin() + 1, s.end());
        return strip(p);
    }
    else if (s[s.size() - 1] == ' ')
    {
        string p(s.begin(), s.end() - 1);
        return strip(p);
    }
    else if (s == "")
    {
        return "";
    }
    else
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
    vector <int> p = v;

    if (p.size() == 0)
    {
        return 0;
    }
    else if (p[p.size() - 1] < 0)
    {
        int temp = p[p.size() - 1];
        p.pop_back();
        return temp + sum_neg(p);
    }
    else
    {
        p.pop_back();
        return sum_neg(p);
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
    vector <int> a1 = a;
    vector <int> b1 = b;

    if (b1.size() == 0)
    {
        return a1;
    }
    else if (a1[b1.size() - 1] >= b1[b1.size() - 1])
    {
        b1.pop_back();
    }
    else if (a1[b1.size() - 1] < b1[b1.size() - 1])
    {
        a1[b1.size() - 1] = b1[b1.size() - 1];
        b1.pop_back();
    }
    
    return max_vec(a1, b1);
}

void max_vec_test()
{
    cout << "\nTest sum_neg(): ";

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
//
// Don't put main() in this file. It goes in a4_main.cpp.
//