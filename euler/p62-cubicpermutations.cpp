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

typedef long long ull;

ull smallest_cube(int limit)
{
    map<string, vector<ull>> cubes;
    for (ull i = 2; i <= 10000; i++)
    {
        ull cube = pow(i, 3L);
        string s = to_string(cube);
        sort(s.begin(), s.end());
        cubes[s].push_back(cube);
        if (cubes[s].size() == limit)
        {
            return cubes[s][0];
        }
    }
    return 0;
}

// https://projecteuler.net/problem=62
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << smallest_cube(5) << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
