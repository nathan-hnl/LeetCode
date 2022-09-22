/*
 You have n dice and each die has k faces numbered from 1 to k.
 Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target.
 Since the answer may be too large, return it modulo 109 + 7.

 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 */
#include <vector>

using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    static int modNumber = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(1001));
    int minValue = min(k, target);
    for (int i = 1; i <= minValue; i++)
    {
        dp[1][i] = 1;
    }

    int targetMax = n * k;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= targetMax; j++)
        {
            for (int m = 1; m <= j && m <= k; m++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % modNumber;
            }
        }
    }

    return dp[n][target];
}