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

int total_scores()
{
    vector<pair<string, int>> names;
    char c;
    string name = "";
    int score = 0;
    while (cin >> c)
    {
        if (c == ',')
        {
            names.push_back({name, score});
            score = 0;
            name = "";
        }
        else if (isalpha(c))
        {
            name += c;
            score += c - 'A' + 1;
        }
    }
    names.push_back({name, score});
    sort(names.begin(), names.end());

    ull sum = 0;
    for (int i = 0; i < names.size(); i++)
    {
        sum += (i + 1) * names[i].second;
        cout << names[i].first << ": " << names[i].second << endl;
    }
    return sum;
}

// https://projecteuler.net/problem=21
int main()
{
#ifndef ONLINE_JUDGE
    freopen("0022_names.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << total_scores() << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
