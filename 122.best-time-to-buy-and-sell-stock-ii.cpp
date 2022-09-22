/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        //1. Peak Valley Approach
        /*
         * Time complexity : O(n). Single pass.
         * Space complexity : O(1). Constant space required.
         * Runtime: 8 ms, faster than 97.35% of C++ online submissions for Best Time to Buy and Sell Stock II.
         * Memory Usage: 13.3 MB, less than 21.80% of C++ online submissions for Best Time to Buy and Sell Stock II.
        */
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        while (i < prices.size() - 1)
        {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;

        //2. Simple One Pass
        /*
         * Time complexity : O(n). Single pass.
         * Space complexity : O(1). Constant space needed.
         * Runtime: 8 ms, faster than 97.35% of C++ online submissions for Best Time to Buy and Sell Stock II.
         * Memory Usage: 13.3 MB, less than 20.48% of C++ online submissions for Best Time to Buy and Sell Stock II.
        */
       for (int j = 1; j < prices.size(); j++)
       {
           if (prices[j] > prices[j - 1])
               maxProfit += prices[j] - prices[j - 1];
       }
       return maxProfit;
    }
};
// @lc code=end

