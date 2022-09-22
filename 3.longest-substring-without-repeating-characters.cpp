/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                occ.erase(s[i - 1]);
            }

            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            
            ans = max(ans, rk - i + 1);
        }

        return ans;
    }
};
// @lc code=end

