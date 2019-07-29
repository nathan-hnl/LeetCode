/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        Runtime: 24 ms, faster than 97.08% of C++ online submissions for Remove Duplicates from Sorted Array.
        Memory Usage: 10.2 MB, less than 97.45% of C++ online submissions for Remove Duplicates from Sorted Array.
        */
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        return i + 1;
    }
};

