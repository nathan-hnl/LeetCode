/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.25%)
 * Total Accepted:    440.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        //Approach 1: Horizontal scanning
        /*
        Runtime: 8 ms, faster than 98.41% of C++ online submissions for Longest Common Prefix.
        Memory Usage: 8.9 MB, less than 99.09% of C++ online submissions for Longest Common Prefix.
        */
        string prefixStr = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefixStr) != 0)
            {
                prefixStr = prefixStr.substr(0, prefixStr.length() - 1);
            }
            if (prefixStr.empty())
                return "";
        }
        return prefixStr;

        //Approach 2: Vertical scanning
        /*
        Runtime: 12 ms, faster than 27.99% of C++ online submissions for Longest Common Prefix.
        Memory Usage: 8.7 MB, less than 99.82% of C++ online submissions for Longest Common Prefix.
        */
        for (int i = 0; i < strs[0].length(); i++)
        {
            char c = strs[0].at(i);
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].length() || strs[j].at(i) != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];

        //Approach 3: Divide and conquer
        /*
         * Runtime: 16 ms, faster than 11.98% of C++ online submissions for Longest Common Prefix.
         * Memory Usage: 12 MB, less than 11.34% of C++ online submissions for Longest Common Prefix.
        */
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

private:
    string longestCommonPrefix(vector<string>& strs, int l, int r)
    {
        if (l == r)
            return strs[l];
        else
        {
            int mid = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);

            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string leftStr, string rightStr)
    {
        int minLen = _Min_value(leftStr.length(), rightStr.length());
        for (int i = 0; i < minLen; i++)
        {
            if (leftStr[i] != rightStr[i])
                return leftStr.substr(0, i);
        }
        return leftStr.substr(0, minLen);
    }
};

