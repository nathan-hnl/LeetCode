/* * @lc app=leetcode id=101 lang=cpp * * [101] Symmetric Tree */// @lc code=start/** * Definition for a binary tree node. * struct TreeNode { *     int val; *     TreeNode *left; *     TreeNode *right; *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} * }; */#include <iostream>#include <queue>using namespace std;struct TreeNode {    int val;    TreeNode *left;    TreeNode *right;    TreeNode(int x) : val(x), left(NULL), right(NULL) {}};class Solution {public:    bool isSymmetric(TreeNode* root) {        //1. recursion        /*         * Runtime: 8 ms, faster than 47.87% of C++ online submissions for Symmetric Tree.         * Memory Usage: 14.7 MB, less than 84.75% of C++ online submissions for Symmetric Tree.        */        return isMirror(root, root);        //2. iteration        /*         * Runtime: 4 ms, faster than 84.26% of C++ online submissions for Symmetric Tree.
         * Memory Usage: 15 MB, less than 32.20% of C++ online submissions for Symmetric Tree.        */        queue<TreeNode *> q;        q.push(root);        q.push(root);        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();

            if (t1 == nullptr && t2 == nullptr)                continue;            if (t1 == nullptr || t2 == nullptr)                return false;
            if (t1->val != t2->val)
                return false;

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }        return true;        //3. iteration optimize        /*         * Runtime: 8 ms, faster than 47.87% of C++ online submissions for Symmetric Tree.         * Memory Usage: 14.9 MB, less than 40.68% of C++ online submissions for Symmetric Tree.        */        if (root == nullptr)            return true;        queue<TreeNode *> q;        q.push(root->left);        q.push(root->right);        while (!q.empty())
        {
            //same with method 2
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();

            if (t1 == nullptr && t2 == nullptr)                continue;            if (t1 == nullptr || t2 == nullptr)                return false;
            if (t1->val != t2->val)
                return false;

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }        return true;    }    bool isMirror(TreeNode *t1, TreeNode *t2)    {        if (t1 == nullptr && t2 == nullptr)            return true;        if (t1 == nullptr || t2 == nullptr)            return false;        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);    }};// @lc code=end