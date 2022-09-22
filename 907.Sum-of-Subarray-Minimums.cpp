/*
 *
 Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
*/
#include <vector>
#include <stack>

using namespace std;

int sumSubarrayMins(vector<int>& arr)
{
    int res = 0, n = arr.size();
    static const int M = 1e9+7;
    stack<int> st {{-1}};
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i)
    {
        while (st.top() != -1 && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        dp[i + 1] = (dp[st.top() + 1] + (i - st.top()) * arr[i]) % M;
        st.push(i);
        res = (res + dp[i + 1]) % M;
    }
    return res;
}

// other methods need to be digged.