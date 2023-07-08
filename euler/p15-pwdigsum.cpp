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

pair<ull, ull> power2_dig_sum_stl(int n)
{
    ull num = pow(2, n);
    ull memnum = num;

    ull sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return {memnum, sum};
}

pair<ull, ull> power2_dig_sum_custom(int n)
{
    vector<int> digits(1, 1);
    for (int i = 0; i < n; i++)
    {
        int remainder = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            int product = digits[i] * 2 + remainder;

            if (product < 10)
            {
                digits[i] = product;
                remainder = 0;
            }
            else
            {
                digits[i] = product % 10;
                remainder = product / 10;
            }
        }
        if (remainder > 0)
        {
            digits.push_back(remainder);
        }
    }

    ull sum = 0;
    ull memnum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        sum += digits[i];
        memnum += digits[i] * pow(10, i);
    }
    return {memnum, sum};
}

// https://projecteuler.net/problem=16
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    // for (int n = 1; n < 100; n++)
    for (int n : vector<int>({16, 32, 64, 1000}))
    {
        auto res = power2_dig_sum_stl(n);
        cout << "2^" << n << " = " << res.first << ", digits sum: " << res.second << endl;
        res = power2_dig_sum_custom(n);
        cout << "2^" << n << " = " << res.first << ", digits sum: " << res.second << endl;
    }

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
