/*
 *
 A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
 You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
 Return the minimum number of flips to make s monotone increasing.
*/

#include <string>
#include <vector>

using namespace std;

int minFlipsMonoIncr1(string s)
{
    int n = s.size(), res = INT_MAX;
    vector<int> cnt1(n + 1), cnt0(n + 1);
    for (int i = 1, j = n - 1; j >= 0; ++i, --j)
    {
        cnt1[i] = cnt1[i - 1] + (s[i - 1] == '0' ? 0 : 1);
        cnt0[j] = cnt0[j + 1] + (s[j] == '1' ? 0 : 1);
    }

    for (int i = 0; i <= n; ++i)
    {
        res = min(res, cnt1[i] + cnt0[i]);
    }
    return res;
}

int minFlipsMonoIncr2(string s)
{
    int res = 0, cnt1 = 0;
    for (auto& c : s)
    {
        (c == '0') ? ++res : ++cnt1;
        res = min(res, cnt1);
    }

    return res;
}

int minFlipsMonoIncr(string s)
{
    int dp0 = 0, dp1 = 0;
    for (auto& c : s)
    {
        int newDp0 = dp0, newDp1 = min(dp0, dp1);
        (c == '1') ? newDp0++ : newDp1++;
        dp0 = newDp0;
        dp1 = newDp1;
    }

    return min(dp0, dp1);
}