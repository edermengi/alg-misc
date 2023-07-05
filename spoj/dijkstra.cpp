#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// typedef pair<int, int> edge;
// typedef vector<edge> vertex;
typedef long long ll;

void print_graph(vector<vector<pair<int, int>>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i + 1 << ": ";
        vector<pair<int, int>> edges = graph[i];
        for (int j = 0; j < edges.size(); j++)
        {
            cout << edges[j].second + 1 << "(" << edges[j].first << "), ";
        }
        cout << "\n";
    }
}

ll INF = 1e15;

vector<vector<pair<int, int>>> graph(100001);
vector<int> edgeTo(graph.size(), -1);

void minPath()
{
    vector<ll> distTo(graph.size(), INF);
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    distTo[0] = 0;
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        // if (!visited[a])
        // {
        //     visited[a] = true;
        for (pair<int, int> e : graph[a])
        {
            int b = e.second;
            int w = e.first;
            if (distTo[a] + w < distTo[b])
            {
                distTo[b] = w + distTo[a];
                edgeTo[b] = a;
                q.push({-distTo[b], b});
            }
        }
        // }
    }
}
// https://codeforces.com/contest/20/problem/C
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    // graph.resize(n, vector<pair<int, int>>());
    // vector<bool> visited(n, false);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a - 1].push_back({w, b - 1});
        graph[b - 1].push_back({w, a - 1});
    }
    // print_graph(graph);

    minPath();

    vector<int> path;
    for (int e = n - 1; e != -1; e = edgeTo[e])
        path.push_back(e);

    if (path.size() == 1)
    {
        cout << -1;
    }
    else
    {
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] + 1 << " ";
        }
        cout << "\n";
    }
}
