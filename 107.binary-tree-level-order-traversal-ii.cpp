/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        /*
         * Runtime: 4 ms, faster than 94.89% of C++ online submissions for Binary Tree Level Order Traversal II.
         * Memory Usage: 13.7 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
        */
        if (root == nullptr)
            return vector<vector<int> >();

        list<vector<int> >list;
        vector<int> curLevel;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int i = 0, n = q.size();
            TreeNode *temp;
            while (i++ < n)
            {
                temp = q.front();
                curLevel.push_back(temp->val);
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            list.push_front(curLevel);
            curLevel.clear();
        }
        return vector<vector<int> >(list.begin(), list.end());
    }
};
// @lc code=end

