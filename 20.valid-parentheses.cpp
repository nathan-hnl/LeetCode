/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.37%)
 * Total Accepted:    574.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */

#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        initSolutionPair();

        stack<char> vStack;
        for (auto sChar : s)
        {
            auto charSearch = m_valuePair.find(sChar);
            if (charSearch != m_valuePair.end())
            {
                //char topElement = vStack.empty() ? '#' : vStack.top();
                char topElement;
                if (vStack.empty())
                    topElement = '#';
                else
                {
                    topElement = vStack.top();
                    vStack.pop();
                }

                if (topElement != m_valuePair.at(sChar))
                    return false;
            }
            else
                vStack.push(sChar);
        }

        return vStack.empty();
    }

    void initSolutionPair()
    {
        if (m_valuePair.empty())
        {
            m_valuePair.insert(make_pair(')', '('));
            m_valuePair.insert(make_pair(']', '['));
            m_valuePair.insert(make_pair('}', '{'));
        }
    }

private:
    unordered_map<char, char> m_valuePair;
};

