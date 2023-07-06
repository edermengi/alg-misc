#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long ull;

bool is_palindrome(ull num)
{
    if (num > 100000 && num <= 999999)
    {
        int a = num / 1000;
        int dig1 = num % 10;
        int dig2 = num % 100 - dig1;
        int dig3 = (num % 1000 - dig2 - dig1) / 100;
        int b = dig1 * 100 + dig2 + dig3;
        return a == b;
    }
    if (num > 10000 && num <= 99999)
    {
        int a = num / 1000;
        int dig1 = num % 10;
        int dig2 = (num - dig1) % 100 / 10;
        int b = dig1 * 10 + dig2;
        return a == b;
    }
    return false;
}

ull largest_palin(ull limit)
{
    priority_queue<ull> palins;
    for (ull i = limit; i > 0; i--)
    {
        for (ull j = i; j > i / 10; j--)
        {
            ull prod = i * j;
            if (is_palindrome(prod))
            {
                palins.push(prod);
            }
        }
    }

    return palins.top();
}

// https://projecteuler.net/problem=4
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ull limit = 999;

    cout << largest_palin(limit);
}
