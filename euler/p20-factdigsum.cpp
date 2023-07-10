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

int digsum(ull num)
{
    int sum = 0;
    while (num > 0)
    {
        num = num / 10;
        sum += num % 10;
    }
    return sum;
}

// https://projecteuler.net/problem=19
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    vector<int> digits({1});

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 0; j < digits.size(); j++)
        {
            digits[j] *= i;
        }
        for (int j = 0; j < digits.size() - 1; j++)
        {
            int d = digits[j];
            digits[j] = d % 10;
            digits[j + 1] += d / 10;
        }

        while (digits[digits.size() - 1] > 10)
        {
            int d = digits[digits.size() - 1];
            digits[digits.size() - 1] = d % 10;
            digits.push_back(d / 10);
        }
    }

    string str = "";
    int sum = 0;
    for (int j = digits.size() - 1; j >= 0; j--)
    {
        str += to_string(digits[j]);
        sum += digits[j];
    }

    cout << str << ": " << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
