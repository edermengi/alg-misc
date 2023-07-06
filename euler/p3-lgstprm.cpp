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

int largest_prime_factor(ull limit)
{
    int sqlim = sqrt(limit);

    vector<bool> is_prime(sqlim, true);
    vector<ull> primes;
    for (int i = 2; i < sqlim; i++)
    {
        for (int j = i * 2; j < sqlim; j += i)
        {
            is_prime[j] = false;
        }
    }
    for (int i = 2; i < sqlim; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
    vector<ull> factors;
    ull largest_known_prime = 0;
    for (auto prime : primes)
    {
        if (limit % prime == 0)
        {
            if (prime > largest_known_prime)
            {
                largest_known_prime = prime;
            }
            ull factor = limit / prime;
            if (factor < sqlim && is_prime[factor])
            {
                return factor;
            }
            else
            {
                bool is_factor_prime = true;
                int sqfactor = sqrt(factor);
                for (int j = 0; j < primes.size() && primes[j] < sqfactor; j++)
                {
                    if (factor % primes[j] == 0)
                    {
                        is_factor_prime = false;
                        break;
                    }
                }
                if (is_factor_prime)
                {
                    return factor;
                }
            }
        }
    }

    return largest_known_prime;
}

// https://projecteuler.net/problem=3
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ull limit = 600851475143;
    // ull limit = 1002344345;

    cout << largest_prime_factor(limit);
}
