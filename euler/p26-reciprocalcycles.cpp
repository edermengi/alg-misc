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
int MAXSTR = 2000;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

string substr(vector<int> &arr, int start, int count)
{
    string s = "";
    for (int i = start; i < count + start; i++)
        s += to_string(arr[i]);
    return s;
}

int rec_cycle(int limit)
{
    int max_d = 0;
    int max_match_len = 0;
    string max_match = "";

    for (int i = 2; i < limit; i++)
    {
        // long double d = (long double)1 / i;
        // stringstream ss;
        // ss << std::setprecision(20) << d;
        // string s = ss.str().substr();
        // cout << "1/" << i << ": " << s << endl;

        vector<int> digits;
        int num = 1;

        for (int j = 0; j < MAXSTR * 2; j++)
        {
            digits.push_back(10 * num / i);
            int remainder = (10 * num) % i;
            if (remainder == 0)
            {
                break;
            }
            num = remainder;
        }
        cout << "1/" << i << ": 0.";
        for (int j = 0; j < digits.size(); j++)
        {
            cout << digits[j];
        }
        cout << endl;

        for (int shift = 0; shift < MAXSTR / 2; shift++)
        {
            string prev_seq = to_string(digits[shift]), cur_seq = "";
            int matches = 0;
            for (int k = shift + 1; k < digits.size() - 1 && matches < 2; k++)
            {
                cur_seq += to_string(digits[k]);
                if (cur_seq == prev_seq)
                {
                    if (prev_seq[0] - '0' == digits[k + 1])
                    {
                        matches++;
                        cur_seq = "";
                    }
                    else
                    {
                        prev_seq += to_string(digits[k]);
                        cur_seq = "";
                        matches = 0;
                    }
                }
                else if (!prev_seq.starts_with(cur_seq))
                {
                    prev_seq += cur_seq;
                    cur_seq = "";
                    matches = 0;
                }
            }
            if (matches > 1)
            {
                cout << "seq: " << prev_seq << endl;
                if (max_match_len < prev_seq.size())
                {
                    max_match_len = prev_seq.size();
                    max_match = prev_seq;
                    max_d = i;
                }

                break;
            }
        }
    }
    cout << "MAX: 1/" << max_d << "=" << max_match << endl;
}

// grimbal's solution https://projecteuler.net/thread=26
void ex26()
{
    int n, i, len, maxlen, maxn;
    maxlen = 0;
    for (n = 2; n < 1000; n++)
    {
        int rest = 1;
        int r0;
        for (i = 0; i < n; i++)
            rest = (rest * 10) % n;
        r0 = rest;
        len = 0;
        do
        {
            rest = (rest * 10) % n;
            len++;
        } while (rest != r0);
        if (len > maxlen)
        {
            maxn = n;
            maxlen = len;
        }
    }
    printf("ex26: %d: %d\n", maxn, maxlen);
}

// https://projecteuler.net/problem=26
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << rec_cycle(1000) << endl;

    // ex26();

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
