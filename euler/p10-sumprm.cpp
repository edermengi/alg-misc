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

typedef long long ull;

ull sum_prime(ull limit)
{
    vector<bool> is_prime(limit + 1, true);
    ull sum = 0;
    for (ull i = 2; i <= limit; i++)
    {
        if (is_prime[i])
        {
            // cout << i << ", ";
            sum += i;
            for (ull j = i * i; j <= limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    cout << "\n";

    return sum;
}

// https://projecteuler.net/problem=10
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ull limit = 2000000;

    cout << sum_prime(limit);
}
