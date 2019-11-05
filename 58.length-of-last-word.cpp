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
        //Runtime: 4 ms, faster than 76.02% of C++ online submissions for Length of Last Word.
        //Memory Usage: 8.9 MB, less than 19.43% of C++ online submissions for Length of Last Word.

        //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
        //Memory Usage: 8.8 MB, less than 43.78% of C++ online submissions for Length of Last Word.
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
        //Runtime: 8 ms, faster than 10.24% of C++ online submissions for Length of Last Word.
        //Memory Usage: 8.9 MB, less than 8.81% of C++ online submissions for Length of Last Word.
        auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
        auto last = find_if_not(first, s.rend(), ::isalpha);

        return distance(first, last);
    }
};