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

int solution(int limit)
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
    set<int> dsums;

    for (int i = 2; i <= limit; i++)
    {
        set<int> divisors;
        for (int prime : primes)
        {
            if (prime >= i)
                break;
            while (i % prime == 0 && prime < i)
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
        if (divsum > i)
        {
            sums[i] = divsum;
        }
    }
    for (auto p : sums)
    {
        cout << p.first << " " << p.second << endl;
        for (auto p2 : sums)
        {
            dsums.insert(p.first + p2.first);
        }
    }
    ull sum = 0;
    for (int i = 1; i <= limit; i++)
    {
        if (dsums.find(i) == dsums.end())
        {
            sum += i;
            cout << "found: " << i << endl;
        }
    }

    return sum;
}

// https://projecteuler.net/problem=23
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << "total: " << solution(29000) << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
