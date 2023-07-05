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

typedef long long ll;

// https://codeforces.com/problemset/problem/1840/A
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        string s;
        vector<char> res;
        cin >> n;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            char a = s[j];
            res.push_back(a);
            for (int k = j + 1; k < n; k++)
            {
                if (s[k] == a)
                {
                    j = k;
                    break;
                }
            }
        }
        cout << string(res.begin(), res.end()) << '\n';
    }
}
