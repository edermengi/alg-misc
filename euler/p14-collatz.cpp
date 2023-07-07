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

map<ull, int> cache;
int hits = 0;

void collatzseq(ull num, int &count)
{
    auto cached = cache.find(num);
    if (cached != cache.end())
    {
        hits++;
        count += cached->second;
        return;
    }
    count++;
    if (num == 1)
    {
        count = 1;
    }
    else if (num % 2 == 0)
    {
        collatzseq(num / 2, count);
    }
    else
    {
        collatzseq(3 * num + 1, count);
    }
}

// https://projecteuler.net/problem=14
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int max_count = 0;
    int max_i;
    for (ull i = 1; i <= 999999; i++)
    {
        int count = 0;
        collatzseq(i, count);
        cache[i] = count;
        // cout << i << ": " << count << endl;
        if (count > max_count)
        {
            max_count = count;
            max_i = i;
        }
    }
    cout << "value : " << max_i << ", chain: " << max_count << endl;
    cout << "cache hits : " << hits << ", size: " << cache.size() << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
