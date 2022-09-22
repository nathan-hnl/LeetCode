/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        /*
        Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count and Say.
        Memory Usage: 9.1 MB, less than 32.01% of C++ online submissions for Count and Say.
        */
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);
        string ans = "";

        int count = 1;
        int i = 1;
        for (; i < s.length(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                ans.push_back(count + '0');
                ans.push_back(s[i - 1]);
                count = 1;
            }
            else
                count++;
        }

        ans.push_back(count + '0');
        ans.push_back(s[i - 1]);
        return ans;
    }
};

