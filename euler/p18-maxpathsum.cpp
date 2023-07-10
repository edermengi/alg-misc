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

// https://projecteuler.net/problem=18
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    vector<vector<int>> g;
    g.push_back({0});

    for (string line; std::getline(cin, line);)
    {
        stringstream ss;
        ss << line;
        int weight;
        vector<int> v;
        while (ss >> weight)
        {
            v.push_back(weight);
        }
        g.push_back(v);
        cout << line << endl;
    }

    map<pair<int, int>, ull> dist;
    dist[{0, 0}] = 0;
    for (int i = 1; i < g.size(); i++)
        for (int j = 0; j < g[i].size(); j++)
            dist.insert({{i, j}, 0});

    priority_queue<pair<ull, pair<int, int>>> q;
    q.push({0, {0, 0}});

    while (!q.empty())
    {
        int x = q.top().second.first;
        int y = q.top().second.second;
        ull w = g[x][y];
        q.pop();
        if (x == g.size() - 1)
            continue;
        for (int i = y; i <= y + 1; i++)
        {
            if (dist[{x + 1, i}] < dist[{x, y}] + g[x + 1][i])
            {
                dist[{x + 1, i}] = dist[{x, y}] + g[x + 1][i];
                q.push({dist[{x + 1, i}], {x + 1, i}});
            }
        }
    }
    ull sum = 0;
    for (int i = 0; i < g[g.size() - 1].size(); i++)
    {
        ull d = dist[{g.size() - 1, i}];
        sum = max(sum, d);
    }

    cout << "total sum=" << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
