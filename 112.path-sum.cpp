/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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

#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        //1. recursive method
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return sum == root->val;
        }

        return hasPathSum(root->left, sum - root->val) || 
        hasPathSum(root->right, sum - root->val);
        
        //2. BFS(广度优先搜索, Breadth-First Search)
        /*
         * Runtime: 12 ms, faster than 92.95% of C++ online submissions for Path Sum.
         * Memory Usage: 21.5 MB, less than 10.67% of C++ online submissions for Path Sum.
        */
        if (root == nullptr)
        {
            return false;
        }
        queue<TreeNode *> q_nodes;
        queue<int> q_vals;
        q_nodes.push(root);
        q_vals.push(root->val);
        while (!q_nodes.empty())
        {
            auto cur_node = q_nodes.front();
            auto cur_val = q_vals.front();
            q_nodes.pop();
            q_vals.pop();
            if (cur_node->left == nullptr && cur_node->right == nullptr)
            {
                if (cur_val == sum)
                    return true;
            }
            
            if (cur_node->left != nullptr)
            {
                q_nodes.push(cur_node->left);
                q_vals.push(cur_node->left->val + cur_val);
            }
            if (cur_node->right != nullptr)
            {
                q_nodes.push(cur_node->right);
                q_vals.push(cur_node->right->val + cur_val);
            }
        }
        return false;

        //3. BFS -- use pair
        if (!root) return false;
        queue<pair<TreeNode *, int>> q_n;
        q_n.push(make_pair(root, root->val));
        while (!q_n.empty())
        {
            auto [curN, curSum] = q_n.front();
            q_n.pop();
            curSum -= curN->val;
            if (!curN->left && !curN->right && curSum == 0) return true;
            if (curN->left)
            {
                q_n.push(make_pair(curN->left, curSum));
            }
            if (curN->right)
            {
                q_n.push(make_pair(curN->right, curSum));
            }
            
        }
        return false;

        //3. DFS(Depth-first search)
        if (!root) return false;
        stack<pair<TreeNode *, int>> s_nodes;
        s_nodes.push(make_pair(root, root->val));
        while (!s_nodes.empty())
        {
            auto [curNode_s, curSum_s] = s_nodes.top();
            s_nodes.pop();
            curSum_s -= curNode_s->val;
            if (!curNode_s->left && !curNode_s->right && curSum_s == 0) return true;
            if (curNode_s->left)
            {
                s_nodes.push(make_pair(curNode_s->left, curSum_s));
            }
            if (curNode_s->right)
            {
                s_nodes.push(make_pair(curNode_s->right, curSum_s));
            }
            
        }
        return false;
    }
};
// @lc code=end

