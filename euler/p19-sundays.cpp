#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

typedef unsigned long long ull;

int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

struct edate
{
    int day, month, year, day_of_month;
};

string to_str(edate d)
{
    return to_string(d.day) + "-" + to_string(d.month) + "-" + to_string(d.year) + ": " + to_string(d.day_of_month);
}
void inc(edate &d)
{
    bool leap = is_leap(d.year);
    int days_in_month;
    if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
        days_in_month = 30;
    else if (d.month == 2)
        days_in_month = leap ? 29 : 28;
    else
        days_in_month = 31;
    if (d.day == days_in_month)
    {
        d.day = 1;
        if (d.month == 12)
        {
            d.month = 1;
            d.year++;
        }
        else
        {
            d.month++;
        }
    }
    else
    {
        d.day++;
    }
    d.day_of_month = (d.day_of_month + 1) % 7;
}

// https://projecteuler.net/problem=19
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    edate dt = {1, 1, 1900, 1};
    int sundays_count = 0;
    while (dt.year < 2001)
    {
        if (dt.year >= 1901 && dt.year <= 2000 && dt.day_of_month == 0 && dt.day == 1)
        {
            sundays_count++;
        }
        inc(dt);
        // cout << "i: " << to_str(dt) << endl;
    }
    cout << "total sundays: " << sundays_count << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
