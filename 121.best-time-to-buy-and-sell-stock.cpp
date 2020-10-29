/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        if (prices.empty())
           return maxprofit;

        //1. O(N2)
        /*
         * Time Limit Exceeded
        */
       for (int i = 0; i < prices.size() - 1; i++)
       {
           for (int j = i + 1; j < prices.size(); j++)
           {
               int curProfit = prices[j] - prices[i];
               if (curProfit > maxprofit)
               {
                   maxprofit = curProfit;
               }
           }
           
       }
       return maxprofit;
       
       //2.One Pass
       /*
        * Runtime: 12 ms, faster than 80.25% of C++ online submissions for Best Time to Buy and Sell Stock.
        * Memory Usage: 13 MB, less than 86.94% of C++ online submissions for Best Time to Buy and Sell Stock.
       */
       int minPrice = prices[0];
       for (int i = 1; i < prices.size(); i++)
       {
           if (prices[i] < minPrice)
           {
               minPrice = prices[i];
           }
           else if (prices[i] - minPrice > maxprofit)
           {
               maxprofit = prices[i] - minPrice;
           }
       }
       return maxprofit;
    }
};
// @lc code=end

