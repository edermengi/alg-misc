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

// https://projecteuler.net/problem=5
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int limit = 100;

    ull sum = 0;
    for (int i = 1; i <= limit; i++)
    {
        for (int j = i + 1; j <= limit; j++)
        {
            sum += 2 * i * j;
        }
    }

    cout << sum;
}
