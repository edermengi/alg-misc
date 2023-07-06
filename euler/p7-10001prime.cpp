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

int ns_prime(int n)
{
    // https://en.wikipedia.org/wiki/Prime_number_theorem
    int limit = n * (log(n) + 2);
    cout << limit << endl;

    vector<bool> is_prime(limit, true);
    for (int i = 2; i < limit; i++)
    {
        for (int j = i * 2; j < limit; j += i)
        {
            is_prime[j] = false;
        }
    }
    int count = 1;
    for (int i = 2; i < limit; i++)
    {
        if (is_prime[i] && count++ == n)
        {
            return i;
        }
    }

    return -1;
}

// https://projecteuler.net/problem=7
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << ns_prime(10001);
}
