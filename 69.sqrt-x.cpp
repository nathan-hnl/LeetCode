/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution {
public:
    int mySqrt(int x) {

        /*
         * Runtime: 4 ms, faster than 75.01% of C++ online submissions for Sqrt(x).
         * Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Sqrt(x).
        */
        int l = 1, r = x;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l - 1;
    }
};

