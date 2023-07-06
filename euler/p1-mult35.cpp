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

int divsum(int div, int limit)
{
    int sum = 0;
    for (int i = div; i < limit; i += div)
    {
        sum += i;
    }
    return sum;
}

// https://projecteuler.net/problem=1
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int limit = 1000;

    cout << divsum(3, limit) + divsum(5, limit) - divsum(15, limit);
}
