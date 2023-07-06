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

typedef unsigned long long ull;

// https://projecteuler.net/problem=5
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << /*20*/
        19 * 17 * 16
            /* 15, 14, */
            * 13
            /*12*/
            * 11
            /*10*/
            * 9
            /*8*/
            * 7
            /*6*/
            * 5
        /*4, 3, 2, 1*/
        ;
}
