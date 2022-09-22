/*
 You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
 Return the sum of all subarray ranges of nums.
 A subarray is a contiguous non-empty sequence of elements within an array.

 * 1 <= nums.length <= 1000
 * -10e9 <= nums[i] <= 10e9
*/
#include <vector>
#include <stack>

using namespace std;

long long subArrayRangesOn2(vector<int>& nums)
{
    //O(n2)
    int n = nums.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int minVar = INT_MAX, maxVar = INT_MIN;
        for (int j = i; j < n; j++)
        {
            minVar = min(minVar, nums[j]);
            maxVar = max(maxVar, nums[j]);
            res += maxVar - minVar;
        }
    }
    return res;
}

// need to reconsider
long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
    stack<int> minStack, maxStack;

    for (int i = 0; i < n; i++)
    {
        while (!minStack.empty() && nums[minStack.top()] > nums[i])
        {
            minStack.pop();
        }
        minLeft[i] = minStack.empty() ? -1 : minStack.top();
        minStack.push(i);

        while (!maxStack.empty() && nums[maxStack.top()] <= nums[i])
        {
            maxStack.pop();
        }
        maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
        maxStack.push(i);
    }

    minStack = stack<int>();
    maxStack = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!minStack.empty() && nums[minStack.top()] >= nums[i])
        {
            minStack.pop();
        }
        minRight[i] = minStack.empty() ? n : minStack.top();
        minStack.push(i);

        while(!maxStack.empty() && nums[maxStack.top()] < nums[i])
        {
            maxStack.pop();
        }
        maxRight[i] = maxStack.empty() ? n : maxStack.top();
        maxStack.push(i);
    }

    long long sumMax = 0, sumMin = 0;
    for (int i = 0; i < n; i++)
    {
        sumMax += (long long)(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
        sumMin += (long long)(minRight[i] - i) * (i - minLeft[i]) * nums[i];
    }

    return sumMax - sumMin;
}