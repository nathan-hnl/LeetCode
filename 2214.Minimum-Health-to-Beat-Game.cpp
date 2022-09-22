/*
 *
 You are playing a game that has n levels numbered from 0 to n - 1.
 You are given a 0-indexed integer array damage where damage[i] is the amount of health you will lose to complete the ith level.
 You are also given an integer armor. You may use your armor ability at most once during the game on any level which will protect you from at most armor damage.
 You must complete the levels in order and your health must be greater than 0 at all times to beat the game.
 Return the minimum health you need to start with to beat the game.
*/

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long minimumHealth(vector<int>& damage, int armor)
{
    //method 1 greedy
    return 1 + accumulate(damage.begin(), damage.end(), 0L) - min(*max_element(damage.begin(), damage.end()), armor);

    //method 2 DP
    long useArmor = 1, noArmor = 1;
    for (int i = 0; i < damage.size(); ++i)
    {
        long newUseArmor = min(noArmor + max(0, damage[i] - armor), useArmor + damage[i]);
        long newNoArmor = noArmor + damage[i];
        useArmor = newUseArmor;
        noArmor = newNoArmor;
    }

    return min(useArmor, noArmor);
}