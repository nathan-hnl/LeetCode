/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //or initialize it by the following method
        //vector<vector<int>> res(numRows, vector<int>(numRows, 1)); //initialize all values to 1
        //vector<vector<int>> res(numRows, vector<int>(numRows)); //initialize all values to 0
        //vector<vector<int>> res{{1, 1, 1, 1}, {2, 2, 2}}; //other initial method

        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
         * Memory Usage: 6.7 MB, less than 16.16% of C++ online submissions for Pascal's Triangle.
        */
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
        }
        return res;
        
    }
};
// @lc code=end

