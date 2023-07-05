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
struct neighbour
{
    int nr;
    int cost;
};
struct city
{
    vector<neighbour> neighbours;
};

typedef long long ll;

ll INF = 1e15;

// https://www.spoj.com/problems/SHPATH/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int s;
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        int n;
        cin >> n;

        vector<city> cities(n);
        map<string, int> city_names;

        for (int j = 0; j < n; j++)
        {
            string name;
            int p;
            cin >> name;
            cin >> p;
            for (int i = 0; i < p; i++)
            {
                int nr, cost;
                cin >> nr >> cost;
                cities[j].neighbours.push_back({nr - 1, cost});
                cities[nr - 1].neighbours.push_back({j, cost});
            }
            city_names.insert({name, j});
        }

        int r;
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            string name1, name2;
            cin >> name1 >> name2;

            int city1 = city_names[name1],
                city2 = city_names[name2];

            // vector<bool> visited(n, false);
            vector<ll> weights(n, INF);

            priority_queue<pair<ll, int>> q;
            q.push({0, city1});
            weights[city1] = 0;
            while (!q.empty())
            {
                int a = q.top().second;
                q.pop();

                city c = cities[a];
                // if (!visited[a])
                // {
                //     visited[a] = true;
                for (neighbour nbr : c.neighbours)
                {
                    int b = nbr.nr;
                    int w = nbr.cost;
                    if (weights[a] + w < weights[b])
                    {
                        weights[b] = weights[a] + w;
                        q.push({-weights[b], b});
                    }
                }
                if (a == city2)
                {
                    break;
                }
                // }
            }

            cout << weights[city2] << "\n";
        }
        if (i < s - 1)
            cout << "\n";
    }
}
