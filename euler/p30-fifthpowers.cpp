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

// https://projecteuler.net/problem=29
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int N = 5;
    int sum = 0;
    for (int i = 2; i < 100000000; i++)
    {
        int pnum = 0;
        int num = i;
        while (num > 0)
        {
            pnum += pow(num % 10, N);
            num = num / 10;
        }
        if (i == pnum)
        {
            cout << i << endl;
            sum += i;
        }
    }

    cout << "SUM: " << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
