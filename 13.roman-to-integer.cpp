/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (51.97%)
 * Total Accepted:    391.7K
 * Total Submissions: 753.7K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0, len = s.size();
        if (len == 0)
            return res;

        unordered_map<char, int> valuePair;
        valuePair.insert(make_pair('I', 1));
        valuePair.insert(make_pair('V', 5));
        valuePair.insert(make_pair('X', 10));
        valuePair.insert(make_pair('L', 50));
        valuePair.insert(make_pair('C', 100));
        valuePair.insert(make_pair('D', 500));
        valuePair.insert(make_pair('M', 1000));

        //1.
        int itr = 0;
        while (itr < s.size())
        {
            if (valuePair[char(s[itr])] < valuePair[char(s[itr + 1])])
            {
                res += valuePair[char(s[itr + 1])] - valuePair[char(s[itr])];
                itr += 2;
            }
            else
            {
                res += valuePair[char(s[itr])];
                itr++;
            }
        }

        return res;

        //2.
        int last_add = 0, cur_add = 0;
        for (int i = 0; i < len; ++i)
        {
            cur_add = valuePair[char(s[i])];
            if (last_add == 0)
            {
                last_add = cur_add;
                res += cur_add;
            }
            else if (cur_add > last_add)
            {
                res += cur_add - 2 * last_add;
                last_add = 0;
            }
            else if (cur_add == last_add)
            {
                res += cur_add;
            }
            else if (cur_add < last_add)
            {
                res += cur_add;
                last_add = cur_add;
            }
        }
        return res;
    }
};

