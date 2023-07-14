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
typedef pair<int, int> ab_pair;

// https://projecteuler.net/problem=29
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    int N = 5;
    int count = 0;
    for (int a1 = 0; a1 <= 1; a1++)
    {
        for (int a2 = 0; a2 <= 2; a2++)
        {
            for (int a3 = 0; a3 <= 4; a3++)
            {
                for (int a4 = 0; a4 <= 10; a4++)
                {
                    for (int a5 = 0; a5 <= 20; a5++)
                    {
                        for (int a6 = 0; a6 <= 40; a6++)
                        {
                            for (int a7 = 0; a7 <= 100; a7++)
                            {
                                for (int a8 = 0; a8 <= 200; a8++)
                                {
                                    int sum = a1 * 200 + a2 * 100 + a3 * 50 + a4 * 20 + a5 * 10 + a6 * 5 + a7 * 2 + a8 * 1;
                                    if (sum > 200)
                                    {
                                        break;
                                    }
                                    if (sum == 200)
                                    {
                                        count++;
                                        // cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << " " << a7 << " " << a8 << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "COUNT: " << count << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
