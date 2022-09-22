/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        /*
         * Runtime: 8 ms, faster than 27.58% of C++ online submissions for Add Binary.
         * Memory Usage: 9.3 MB, less than 52.73% of C++ online submissions for Add Binary.
        */
        string res = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0)
        {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }

        return carry == 1 ? "1" + res : res;


        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
         * Memory Usage: 8.7 MB, less than 76.36% of C++ online submissions for Add Binary.
        */
        int alength = a.length();
        int blength = b.length();
        int addBit = 0;
        int i = alength - 1, j = blength - 1;
        string str, result;

        while (i >= 0 || j >= 0) {
            str += ((i >= 0 ? a[i] : '0') + (j >= 0 ? b[j] : '0') + addBit - 2 * '0') % 2 + '0';
            addBit = ((i >= 0 ? a[i] : '0') + (j >= 0 ? b[j] : '0') + addBit - 2 * '0') / 2;
            i--; j--;
        }
        if (addBit)
            str += '1';

        for (int p = str.length() - 1; p >= 0; p--) {
            result += str[p];
        }

        return result;
    }
};

