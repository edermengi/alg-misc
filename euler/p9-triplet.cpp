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

// https://projecteuler.net/problem=9
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int total = 1000;

    for (int c = total - 3; c > 1; c--)
    {
        for (int b = 1; b < total - c - 1; b++)
        {
            int a = total - b - c;
            if (c * c == a * a + b * b)
            {
                cout << a << " " << b << " " << c << endl;
                cout << a * b * c;
                return 0;
            }
        }
    }
}
