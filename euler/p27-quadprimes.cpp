#include <iostream>
#include <iomanip>
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

// https://projecteuler.net/problem=27
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int limit = 1000000;
    vector<bool> is_prime(limit, true);
    for (int i = 2; i < limit; i++)
    {
        for (int j = i * 2; j < limit; j += i)
        {
            is_prime[j] = false;
        }
    }
    int max_primes = 0;
    for (int a = -1000; a < 1000; a++)
    {
        for (int b = -1000; b < 1000; b++)
        {
            // if (!is_prime[abs(b)])
            //     continue;
            int primes_no = 0;
            for (int n = 0; n < 1000; n++)
            {
                int res = abs(n * n + a * n + b);
                assert(res < is_prime.size());
                if (!is_prime[res])
                    break;
                primes_no++;
            }
            if (primes_no > max_primes)
            {
                max_primes = primes_no;
                cout << "a=" << a << ", b=" << b << ": " << max_primes << "\t prod: " << a * b << endl;
            }
        }
    }

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
