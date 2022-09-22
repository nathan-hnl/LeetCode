/*
 *
 Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
 A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
 Return the maximum length of a subarray with positive product.
*/
#include <vector>

using namespace std;

int getMaxLen(vector<int>& nums)
{
    int length = nums.size();
    vector<int> positive(length), negative(length);
    if (nums[0] > 0)
    {
        positive[0] = 1;
    }
    else if (nums[0] < 0)
    {
        negative[0] = 1;
    }

    int maxLength = positive[0];
    for (int i = 1; i < length; ++i)
    {
        if (nums[i] > 0)
        {
            positive[i] = positive[i - 1] + 1;
            negative[i] = (negative[i - 1] > 0 ? negative[i - 1] + 1 : 0);
        }
        else if (nums[i] < 0)
        {
            positive[i] = (negative[i - 1] > 0 ? negative[i - 1] + 1 : 0);
            negative[i] = positive[i - 1] + 1;
        }
        else
        {
            positive[i] = 0;
            negative[i] = 0;
        }
        maxLength = max(maxLength, positive[i]);
    }
    return maxLength;
}

int getMaxLenFast(vector<int>& nums)
{
    int length = nums.size();
    int positive = (nums[0] > 0);
    int negative = (nums[0] < 0);
    int maxLength = positive;
    
    for (int i = 1; i < length; ++i)
    {
        if (nums[i] > 0)
        {
            ++positive;
            negative = (negative > 0 ? negative + 1 : 0);
        }
        else if (nums[i] < 0)
        {
            int newPositive = negative > 0 ? negative + 1 : 0;
            int newNegative = positive + 1;
            tie(positive, negative) = {newPositive, newNegative};
        }
        else
        {
            positive = negative = 0;
        }
        maxLength = max(maxLength, positive);
    }
    
    return maxLength;
}