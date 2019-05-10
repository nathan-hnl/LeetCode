/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.26%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */

/*
Runtime: 8 ms, faster than 99.94% of C++ online submissions for Two Sum.
Memory Usage: 9.9 MB, less than 56.96% of C++ online submissions for Two Sum.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> mapValue;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mapValue.count(target - nums[i]))
            {
                return {i, mapValue[target - nums[i]]};
            }
            mapValue[nums[i]] = i;
        }

        return {};
    }
};

