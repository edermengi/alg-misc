
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> calc_primes(int limit)
{
    vector<bool> is_prime(limit, true);
    vector<int> primes;

    for (int step = 2; step < limit; step++)
    {
        for (int i = step * 2; i < limit; i += step)
        {
            is_prime[i] = false;
        }
    }
    for (int i = 2; i < limit; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

// https://www.spoj.com/problems/DIVSUM/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int count;
    cin >> count;

    vector<int> primes = calc_primes(sqrt(1000000100));

    for (int i = 0; i < count; i++)
    {
        int start, end;
        cin >> start;
        cin >> end;

        vector<bool> range_primes(end - start + 1, true);

        for (int prime : primes)
        {
            int starti = (start + prime - 1) / prime;
            int j = max(starti, prime) * prime - start;
            for (; j < end - start + 1; j += prime)
                range_primes[j] = false;
        }
        for (int j = 0; j < range_primes.size(); j++)
        {
            if (range_primes[j] && (start + j) > 1)
                cout << start + j << "\n";
        }
        cout << "\n";
    }
}
