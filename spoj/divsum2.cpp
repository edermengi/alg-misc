
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int bf_sum(int num)
{
    long sum = 1 ? num > 1 : 0;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}

// primes begining from 2
vector<int> primes(int limit)
{
    bool numbers[limit];
    memset(numbers, true, limit);

    for (int step = 2; step < limit; step++)
    {
        for (int i = step * 2; i < limit; i += step)
        {
            numbers[i] = false;
        }
    }
    vector<int> result;
    for (int i = 0; i < limit; i++)
    {
        if (numbers[i])
        {
            result.push_back(i);
        }
    }
    return result;
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

    vector<int> vprimes = primes(sqrt(50000000));
    for (int i = 0; i < count; i++)
    {
        int num;
        cin >> num;
        int num2 = num;
        int max_div = sqrt(num);

        set<int> all_divs;

        int j = 2;
        int div_prime = vprimes[j];

        while (div_prime <= max_div)
        {
            while (num2 % div_prime == 0)
            {
                num2 = num2 / div_prime;

                set<int> divs(all_divs);
                for (int div : divs)
                {
                    int prod1 = div * num2;
                    if (prod1 < num && num % prod1 == 0)
                        all_divs.insert(prod1);
                    int prod2 = div * div_prime;
                    if (prod2 < num && num % prod2 == 0)
                        all_divs.insert(prod2);
                }
                all_divs.insert(div_prime);
                if (num2 != 1)
                    all_divs.insert(num2);
            }
            div_prime = vprimes[++j];
        }

        long sum = 1 ? num > 1 : 0;
        for (int d : all_divs)
            sum += d;

#ifndef ONLINE_JUDGE
        cout << sum << " - " << bf_sum(num) << "\n";
#else
        cout << sum << "\n";
#endif
    }
}
