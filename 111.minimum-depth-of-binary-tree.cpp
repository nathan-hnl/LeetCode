/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <algorithm>

#include <stack>
#include <utility>

#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        //1. recursive method
        /*
        Runtime: 12 ms, faster than 92.81% of C++ online submissions for Minimum Depth of Binary Tree.
        Memory Usage: 20.4 MB, less than 5.03% of C++ online submissions for Minimum Depth of Binary Tree.
        */
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        if (!root->left)
        {
            return minDepth(root->right) + 1;
        }
        if (!root->right)
        {
            return minDepth(root->left) + 1;
        }
        
        return min(minDepth(root->left), minDepth(root->right)) + 1;

        //2. Depth First Search(DFS)
        stack<pair<TreeNode *, int>> stackNode;
        stackNode.push(make_pair(root, 1));
        int minRes = INT32_MAX;

        while (!stackNode.empty())
        {
            TreeNode *curNode = stackNode.top().first;
            int curDepth = stackNode.top().second;
            stackNode.pop();

            if (!curNode->left && !curNode->right)
            {
                minRes = min(minRes, curDepth);
            }
            if (curNode->left)
            {
                stackNode.push(make_pair(curNode->left, curDepth + 1));
            }
            if (curNode->right)
            {
                stackNode.push(make_pair(curNode->right, curDepth + 1));
            }
        }
        return minRes;

        //3. (BFS)
        /*
        Runtime: 24 ms, faster than 18.31% of C++ online submissions for Minimum Depth of Binary Tree.
        Memory Usage: 19.8 MB, less than 95.73% of C++ online submissions for Minimum Depth of Binary Tree.
        */
        queue<pair<TreeNode *, int>> curNodes;
        curNodes.push(make_pair(root, 1));
        int curRes = 0;

        while (!curNodes.empty())
        {
            TreeNode *curNode = curNodes.front().first;
            curRes = curNodes.front().second;
            curNodes.pop();

            if (!curNode->left && !curNode->right)
            {
                return curRes;
            }
            if (curNode->left)
            {
                curNodes.push(make_pair(curNode->left, curRes + 1));
            }
            if (curNode->right)
            {
                curNodes.push(make_pair(curNode->right, curRes + 1));
            }
        }
        return -1;
    }
};
// @lc code=end

