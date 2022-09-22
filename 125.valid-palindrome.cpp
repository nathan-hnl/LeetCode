/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        /*
         * Time complexity : O(∣s∣).
         * Space complexity : O(1).
         * Runtime: 8 ms, faster than 99.31% of C++ online submissions for Valid Palindrome.
         * Memory Usage: 7.3 MB, less than 69.13% of C++ online submissions for Valid Palindrome.
        */
        int n = s.size();
        int left = 0, right = n -1;
        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                ++left;
            }
            while(left < right && !isalnum(s[right]))
            {
                --right;
            }
            if (left < right)
            {
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
// @lc code=end

