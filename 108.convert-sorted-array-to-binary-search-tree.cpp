/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    /*
     * Runtime: 8 ms, faster than 100.00% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
     * Memory Usage: 21 MB, less than 97.30% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
    */
    TreeNode *makeTree(vector<int>& nums, int low_, int high_)
    {
        if (low_ > high_)
            return NULL;
        //else if (low_ == high_)
        //    return new TreeNode(nums[low_]);

        int mid_ = low_ + (high_ - low_) / 2;
        TreeNode *tn = new TreeNode(nums[mid_]);
        tn->left = makeTree(nums, low_, mid_ - 1);
        tn->right = makeTree(nums, mid_ + 1, high_);
        return tn;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty())
            return NULL;

        return makeTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

