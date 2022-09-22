/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.67%)
 * Total Accepted:    547.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 *
 * Example 1:
 *
 *
 * Input: 121
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 *
 * Follow up:
 *
 * Coud you solve it without converting the integer to a string?
 *
 */

//reference link: 
/*
 * https://blog.csdn.net/regemc/article/details/79698015
 * https://leetcode.com/problems/palindrome-number/solution/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        //1. negative number
        //2. last number is 0, while the number itself is not 0
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        //only compare two half part is equal or not
        int revertedNum = 0;
        while (x > revertedNum)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNum || x == revertedNum / 10;
    }
};

