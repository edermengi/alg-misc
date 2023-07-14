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
typedef pair<int, int> ab_pair;

int numDigits(int x)
{
    if (x >= 100000)
    {
        if (x >= 10000000)
        {
            if (x >= 100000000)
            {
                if (x >= 1000000000)
                    return 10;
                return 9;
            }
            return 8;
        }
        if (x >= 1000000)
            return 7;
        return 6;
    }
    if (x >= 100)
    {
        if (x >= 1000)
        {
            if (x >= 10000)
                return 5;
            return 4;
        }
        return 3;
    }
    if (x >= 10)
        return 2;
    return 1;
}
// https://projecteuler.net/problem=29
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    set<int> products;
    int sum = 0;
    for (int i = 1; i < 10000; i++)
    {
        set<int> digits;
        int num = i;
        bool skip = false;
        while (num > 0)
        {
            int digit = num % 10;
            if (digit == 0 || digits.contains(digit))
            {
                skip = true;
                break;
            }
            else
            {
                digits.insert(digit);
            }
            num = num / 10;
        }
        if (skip)
            continue;
        int num_digits_i = numDigits(i);

        for (int j = i + 1; j < 100000; j++)
        {
            int num_digits_j = numDigits(j);
            if (num_digits_i + num_digits_j > 8)
                continue;

            int prod = i * j;

            int num_digits_prod = numDigits(prod);
            if (num_digits_i + num_digits_j + num_digits_prod != 9)
                continue;

            set<int> prod_digits(digits);
            num = j;
            skip = false;
            while (num > 0)
            {
                int digit = num % 10;
                if (digit == 0 || prod_digits.contains(digit))
                {
                    skip = true;
                    break;
                }
                else
                {
                    prod_digits.insert(digit);
                }
                num = num / 10;
            }
            if (skip)
                continue;

            num = prod;
            skip = false;
            while (num > 0)
            {
                int digit = num % 10;
                if (digit == 0 || prod_digits.contains(digit))
                {
                    skip = true;
                    break;
                }
                else
                {
                    prod_digits.insert(digit);
                }
                num = num / 10;
            }
            if (skip)
                continue;

            if (prod_digits.size() == 9 && !products.contains(prod))
            {
                sum += prod;
                products.insert(prod);
                cout << i << " * " << j << " = " << prod << endl;
            }
            else if (prod_digits.size() == 9)
            {
                cout << "dup: " << i << " * " << j << " = " << prod << endl;
            }
        }
    }

    cout << "SUM: " << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
