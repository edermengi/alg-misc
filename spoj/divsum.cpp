#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int bf_sum(int num)
{
    long sum = 1 ? num > 1 : 0;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}

// https://www.spoj.com/problems/DIVSUM/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int num;
        cin >> num;
        int num2 = num;

        set<int> all_divs;

        for (int j = 2; j <= num2 && j <= num / 2; j++)
        {
            if (num2 % j == 0)
            {
                num2 = num2 / j;

                set<int> divs(all_divs);
                for (int div : divs)
                {
                    int prod1 = div * num2;
                    if (prod1 < num && num % prod1 == 0)
                        all_divs.insert(prod1);
                    int prod2 = div * j;
                    if (prod2 < num && num % prod2 == 0)
                        all_divs.insert(prod2);
                }
                all_divs.insert(j);
                if (num2 != 1)
                    all_divs.insert(num2);
                j = 1;
            }
        }

        long sum = 1 ? num > 1 : 0;
        for (int d : all_divs)
            sum += d;

        cout << sum << " - " << bf_sum(num) << "\n";
        // cout << sum << "\n";
    }
}
