/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        //1.
        /*
        Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
        Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Remove Element.
        */
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            else
                i++;
        }

        return n;

        //2.
        /*
        Runtime: 4 ms, faster than 98.54% of C++ online submissions for Remove Element.
        Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Remove Element.
        */
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

