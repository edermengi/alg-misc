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

int l(string s)
{
    return s.size();
}
map<int, string> words{
    {0, ""},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"}};

// https://projecteuler.net/problem=17
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    int sum = 0;
    for (int i = 1; i < 1000; i++)
    {
        int num = i;
        int num_sum = 0;
        string num_str = "";
        if (num > 99)
        {
            int hundreds = num / 100;
            num_str += words[hundreds];
            num_str += "hundred"; // hundred
            num %= 100;
            if (num > 0)
            {
                num_str += "and"; // and
            }
        }
        if (num > 19)
        {
            int tens = num / 10 * 10;
            num_str += words[tens];
            num %= 10;
        }
        num_str += words[num];
        num_sum = l(num_str);
        sum += num_sum;
        cout << i << ": sum=" << num_sum << "\t" << num_str << endl;
    }
    sum += l("onethousand");
    cout << "total sum=" << sum << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
