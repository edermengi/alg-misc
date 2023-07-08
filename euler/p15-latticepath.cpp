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

vector<pair<int, int>> grid;
vector<ull> cache;

ull dfs(int v)
{
    pair<int, int> adj = grid[v];
    if (adj.first > 0)
    {
        ull count;
        if (cache[adj.first] != -1)
        {
            count = cache[adj.first];
        }
        else
        {
            count = dfs(adj.first);
            cache[adj.first] = count;
        }
        if (adj.second > 0)
        {
            ull sec_count;
            if (cache[adj.second] != -1)
            {
                sec_count = cache[adj.second];
            }
            else
            {
                sec_count = dfs(adj.second);
                cache[adj.second] = sec_count;
            }
            count += sec_count;
        }
        return count;
    }
    else
    {
        return 1;
    }
}

ull count_dp(int n)
{
    vector<vector<ull>> g(n + 1, vector<ull>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        g[i][0] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        g[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = g[i - 1][j] + g[i][j - 1];
        }
    }
    return g[n][n];
}

// https://projecteuler.net/problem=14
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int n = 20;
    int N = (n + 1) * (n + 1);
    grid.resize(N);
    cache.resize(N, -1);

    for (int v = 0; v < N; v++)
    {
        if (v == 0 || (v + 1) % (n + 1) != 0)
        {
            grid[v].first = v + 1;
        }
        else
        {
            grid[v].first = -1;
        }
        if (v < N - n - 1)
        {
            grid[v].second = v + n + 1;
        }
        else
        {
            grid[v].second = -1;
        }
    }

    cout << n << ": recusive : " << dfs(0) << endl;

    cout << n << ": dynamic programming: " << count_dp(n) << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
