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

ull LIMIT = 1000000;

vector<bool> is_prime(LIMIT, true);
vector<ull> primes;
void init_primes()
{
    ull sqlimit = sqrt(LIMIT);
    for (ull i = 2; i <= sqlimit; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ull j = i * i; j <= LIMIT; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int count_factors(ull num)
{
    ull sqnum = sqrt(num);

    int count = 1;
    for (ull prime : primes)
    {
        if (prime > num / 2)
        {
            break;
        }
        ull factor = prime;
        int factorization = 0;
        while (num % factor == 0)
        {
            // cout << factor << "/" << num / factor << " ";
            factorization++;
            factor *= prime;
        }
        if (factorization > 0)
        {
            count *= (factorization + 1);
        }
    }
    return count;
}

// https://projecteuler.net/problem=12
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init_primes();
    int limit = 100000;

    for (int i = 3; i < limit; i++)
    {
        int num = i * (i + 1) / 2;
        // cout << num << ": " << count_factors(num) << "\n";
        if (count_factors(num) > 500)
        {
            cout << num << "\n";
        }
    }
}
