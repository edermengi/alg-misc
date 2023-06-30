#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

// https://www.spoj.com/problems/PALIN/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int count;
    cin >> count;
    cin.ignore();

    for (int no = 0; no < count; no++)
    {
        int first_ch = 0;
        string line;
        getline(cin, line);

        vector<char> digits;
        for (char d : line)
            digits.push_back(d - '0');

        bool is_palindrome = true;
        for (int i = 0; i < digits.size() / 2; i++)
            if (digits[i] != digits[digits.size() - i - 1])
                is_palindrome = false;

        if (is_palindrome)
        {
            for (int j = digits.size() - 1; j >= 0; j--)
            {
                digits[j] = (digits[j] + 1) % 10;
                if (digits[j] != 0)
                    break;
            }
            if (digits[0] == 0)
                digits.insert(digits.begin(), 1);
        }

        for (int i = 0; i < digits.size() / 2; i++)
        {
            int mirror = digits.size() - i - 1;
            if (digits[mirror] < digits[i])
            {
                digits[mirror] = digits[i];
            }
            else if (digits[mirror] > digits[i])
            {
                digits[mirror] = digits[i];
                for (int j = mirror - 1; j >= 0; j--)
                {
                    digits[j] = (digits[j] + 1) % 10;
                    if (digits[j] != 0)
                        break;
                }
                digits[mirror] = digits[i];
            }
        }
#ifndef ONLINE_JUDGE
        for (int i = 0; i < digits.size() / 2; i++)
            if (digits[i] != digits[digits.size() - i - 1])
                throw invalid_argument(line);
#endif

        for (char d : digits)
            cout << char(d + '0');

        cout << "\n";
    }
}
