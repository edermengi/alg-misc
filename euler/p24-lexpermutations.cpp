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

void swap(char *s, int a, int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

// https://www.quickperm.org/soda_submit.php
int permute(char *str, int len)
{
    int key = len - 1;
    int newKey = len - 1;
    while (key > 0 && (str[key] <= str[key - 1]))
        key--;

    key--;
    if (key < 0)
        return 0;
    newKey = len - 1;
    while ((newKey > key) && (str[newKey] <= str[key]))
        newKey--;
    swap(str, key, newKey);
    len--;
    key++;
    while (len > key)
    {
        swap(str, len, key);
        key++;
        len--;
    }
    return 1;
}

string solution_sepa()
{
    char s[] = "0123456789";
    int len = strlen(s);
    for (int i = 1; i < 1000000; i++)
    {
        permute(s, len);
    }

    return string(s);
}

string solution_bf()
{
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int count = 0;
    for (int i0 = 0; i0 < digits.size(); i0++)
    {
        for (int i1 = 0; i1 < digits.size(); i1++)
        {
            if (i1 == i0)
                continue;
            for (int i2 = 0; i2 < digits.size(); i2++)
            {
                if (i2 == i1 || i2 == i0)
                    continue;
                for (int i3 = 0; i3 < digits.size(); i3++)
                {
                    if (i3 == i2 || i3 == i1 || i3 == i0)
                        continue;
                    for (int i4 = 0; i4 < digits.size(); i4++)
                    {
                        if (i4 == i3 || i4 == i2 || i4 == i1 || i4 == i0)
                            continue;
                        for (int i5 = 0; i5 < digits.size(); i5++)
                        {
                            if (i5 == i4 || i5 == i3 || i5 == i2 || i5 == i1 || i5 == i0)
                                continue;
                            for (int i6 = 0; i6 < digits.size(); i6++)
                            {
                                if (i6 == i5 || i6 == i4 || i6 == i3 || i6 == i2 || i6 == i1 || i6 == i0)
                                    continue;
                                for (int i7 = 0; i7 < digits.size(); i7++)
                                {
                                    if (i7 == i6 || i7 == i5 || i7 == i4 || i7 == i3 || i7 == i2 || i7 == i1 || i7 == i0)
                                        continue;
                                    for (int i8 = 0; i8 < digits.size(); i8++)
                                    {
                                        if (i8 == i7 || i8 == i6 || i8 == i5 || i8 == i4 || i8 == i3 || i8 == i2 || i8 == i1 || i8 == i0)
                                            continue;
                                        for (int i9 = 0; i9 < digits.size(); i9++)
                                        {
                                            if (i9 == i8 || i9 == i7 || i9 == i6 || i9 == i5 || i9 == i4 || i9 == i3 || i9 == i2 || i9 == i1 || i9 == i0)
                                                continue;
                                            // cout << s << endl;
                                            if (++count == 1000000)
                                            {
                                                string s({digits[i0], digits[i1], digits[i2], digits[i3], digits[i4], digits[i5], digits[i6],
                                                          digits[i7], digits[i8], digits[i9]});
                                                return s;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return "";
}

// https://projecteuler.net/problem=23
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << solution_sepa() << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
