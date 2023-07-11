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

int fibidx(int limit)
{
    vector<int> va({1}), vb({1});
    vector<int> *f1 = &va, *f2 = &vb;
    int idx = 2;
    while (f2->size() < limit)
    {
        idx++;
        for (int i = 0; i < f2->size(); i++)
        {
            if (i >= f1->size())
                f1->push_back((*f2)[i]);
            else
                (*f1)[i] += (*f2)[i];
        }
        for (int i = 0; i < f1->size(); i++)
        {
            if ((*f1)[i] > 9)
            {
                int cary = (*f1)[i] / 10;
                if (i == f1->size() - 1)
                    f1->push_back(cary);
                else
                    (*f1)[i + 1] += cary;
                (*f1)[i] %= 10;
            }
        }
        vector<int> *tmp = f2;
        f2 = f1;
        f1 = tmp;
    }
    return idx;
}

// https://projecteuler.net/problem=25
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cout << fibidx(1000) << endl;

#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "took: " << duration.count() << "us" << endl;
#endif
}
