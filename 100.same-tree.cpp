/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
         * Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Same Tree.
        */
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
         * Memory Usage: 9.9 MB, less than 75.00% of C++ online submissions for Same Tree.
        */
        if (p == NULL && q == NULL)
            return true;
        if (!check(p, q))
            return false;

        queue<TreeNode *> queueP, queueQ;
        queueP.push(p);
        queueQ.push(q);
        while (!queueP.empty())
        {
            TreeNode *tempP = queueP.front();
            TreeNode *tempQ = queueQ.front();
            queueP.pop();
            queueQ.pop();

            if (!check(tempP, tempQ))
                return false;
            if (!check(tempP->left, tempQ->left))
                return false;
            if (tempP->left != NULL)
            {
                queueP.push(tempP->left);
                queueQ.push(tempQ->left);
            }

            if (!check(tempP->right, tempQ->right))
                return false;

            if (tempP->right != NULL)
            {
                queueP.push(tempP->right);
                queueQ.push(tempQ->right);
            }

        }

        return true;
    }

    bool check(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;

        return true;
    }
};
// @lc code=end

