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

int count_amicable(int limit)
{
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    for (int i = 2; i <= limit; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    map<int, int> sums;

    for (int i = 220; i < limit; i++)
    {
        set<int> divisors;
        for (int prime : primes)
        {
            if (prime >= i)
                break;
            while (i % prime == 0)
            {
                for (int d : set<int>(divisors))
                {
                    int div_cand = prime * d;
                    if (div_cand < i && i % div_cand == 0)
                    {
                        divisors.insert(prime * d);
                    }
                }
                divisors.insert(prime);
                divisors.insert(i / prime);
                prime *= prime;
            }
        }
        int divsum = 1;
        for (int d : divisors)
        {
            divsum += d;
        }
        if (divsum > 1)
        {
            sums[i] = divsum;
        }
    }
    ull amicsum = 0;
    for (auto p : sums)
    {
        if (p.first != p.second && p.first == sums[p.second])
        {
            amicsum += p.first + p.second;
            cout << p.first << " " << p.second << endl;
        }
    }
    return amicsum / 2;
}

// https://projecteuler.net/problem=21
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << count_amicable(10000) << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
