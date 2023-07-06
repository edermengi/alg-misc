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

int fibsum(int limit)
{
    int sum = 0;
    int f1 = 1, f2 = 2;
    while (f2 < limit)
    {
        cout << f2 << " ";
        if (f2 % 2 == 0)
        {
            sum += f2;
        }
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    cout << "\n";
    return sum;
}

// https://projecteuler.net/problem=2
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int limit = 4000000;

    cout << fibsum(limit);
}
