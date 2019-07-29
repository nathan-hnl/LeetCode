/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <vector>
#include <algorithm>

using namespace std;

/*
 * ATTENTION:
 * If you have figured out the O(n) solution, 
 * try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        /*
        Runtime: 8 ms, faster than 93.76% of C++ online submissions for Maximum Subarray.
        Memory Usage: 9.4 MB, less than 57.97% of C++ online submissions for Maximum Subarray.
        */
        int max_sum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum = nums[i] + (sum > 0 ? sum : 0);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

