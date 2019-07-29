/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        //1.
        /*
        Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
        Memory Usage: 9.2 MB, less than 98.25% of C++ online submissions for Implement strStr().
        */
        if (needle.empty())
            return 0;

        int l1 = haystack.size(), l2 = needle.size();
        if (l1 < l2)
            return -1;

        for (int i = 0; i <= l1 - l2; ++i)
        {
            int j = 0;
            for (; j < l2; ++j)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }

            if (j == l2)
                return i;
        }

        return -1;

        //2.
        /*
        Runtime: 8 ms, faster than 84.38% of C++ online submissions for Implement strStr().
        Memory Usage: 9.3 MB, less than 92.23% of C++ online submissions for Implement strStr().
        */
        for (int i = 0; i <= l1 - l2; ++i)
        {
            if (haystack.substr(i, i+l2) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

