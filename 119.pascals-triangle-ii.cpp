/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
         * Memory Usage: 6.5 MB, less than 57.17% of C++ online submissions for Pascal's Triangle II.
        */
        vector<int> kRows(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++)
        {
            kRows[i] = 1;
            for (int j = i; j > 1; j--)
            {
                kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
            }
        }
        return kRows;
    }
};
// @lc code=end

