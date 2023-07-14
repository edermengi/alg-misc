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

// https://projecteuler.net/problem=28
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int N = 1001;
    int line = 0;
    int step = 2;
    int round = 0;
    ull sum = 1;
    for (int i = 3; i <= N * N; i += step)
    {
        cout << i << endl;
        sum += i;
        if (++round % 4 == 0)
        {
            step += 2;
        }
    }
    cout << "SUM: " << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
