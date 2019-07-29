/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <string>
//2. using STL need this head file
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //1. loop method
        //time complexity O(n), space complexity O(1)
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ')
        {
            tail--;
        }
        while (tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }

        return len;

        //2. using STL
        // time complexity O(n), space complexity O(1)
        auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
        auto last = find_if_not(first, s.rend(), ::isalpha);

        return distance(first, last);
    }
};