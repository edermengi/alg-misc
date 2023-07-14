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

    int N = 100;
    map<int, ab_pair> cache;
    set<string> terms;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            int res = pow(i, j);
            if (res > N)
                break;
            auto cached = cache.find(res);
            if (cached == cache.end())
            {
                cache[res] = {i, j};
            }
        }
    }

    for (int a = 2; a <= N; a++)
    {
        for (int b = 2; b <= N; b++)
        {
            string a_str, b_str;
            auto cached = cache.find(a);
            if (cached != cache.end())
            {
                a_str = to_string((*cached).second.first);
                b_str = to_string((*cached).second.second * b);
            }
            else
            {
                a_str = to_string(a);
                b_str = to_string(b);
            }

            cout << a << " " << b << "\t" << a_str << "^" << b_str << endl;
            terms.insert(a_str + "^" + b_str);
        }
    }

    cout << "Distinct terms: " << terms.size() << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
