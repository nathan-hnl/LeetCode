/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //1.
        /*
        Runtime: 4 ms, faster than 99.93% of C++ online submissions for Search Insert Position.
        Memory Usage: 8.8 MB, less than 86.59% of C++ online submissions for Search Insert Position.
        */
        int i = 0;
        for (; i < nums.size(); ++i)
        {
            if (target <= nums[i])
                return i;
        }

        return nums.size();

        //2.
        /*
        Runtime: 4 ms, faster than 99.93% of C++ online submissions for Search Insert Position.
        Memory Usage: 9.1 MB, less than 52.55% of C++ online submissions for Search Insert Position.
        */
        if (nums.back() < target)
            return nums.size();
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};

