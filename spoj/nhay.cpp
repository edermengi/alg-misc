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

vector<int> prefix_kmp(string pat)
{
    int n = pat.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && pat[i] != pat[j])
            j = pi[j - 1];
        if (pat[i] == pat[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    int len;
    string str, pat;
    while (cin >> len)
    {
        cin >> pat >> str;

        pat = pat.substr(0, len);

        vector<int> pi = prefix_kmp(pat);
        vector<int> pos;

        // cout << pat << "-> " << str << endl;
        // for (auto p : pi)
        //     cout << p;
        // cout << endl;

        int j = 0;
        int k = 0;
        while (j < str.size())
        {
            if (pat[k] == str[j])
            {
                j++;
                k++;
                if (k == pat.size())
                {
                    int m = j - k; // match
                    pos.push_back(m);
                    k = pi[k - 1];
                }
            }
            else
            {
                if (k > 0)
                {
                    k = pi[k - 1];
                }
                else
                {
                    j++;
                }
            }
        }
        for (int p : pos)
            cout << p << endl;
        cout << endl;
    }

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}