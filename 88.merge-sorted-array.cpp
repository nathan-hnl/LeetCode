/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        /*
         * Runtime: 4 ms, faster than 84.81% of C++ online submissions for Merge Sorted Array.
         * Memory Usage: 8.8 MB, less than 63.04% of C++ online submissions for Merge Sorted Array.
        */
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0)
        {
            nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
        }

        while (p2 >= 0)
        {
            nums1[p--] = nums2[p2--];
        }
    }
};
// @lc code=end

