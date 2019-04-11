#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numsCount = nums.size();
        int result = 0;
        for (int i = 0; i < numsCount; i++)
        {
        	result ^= nums[i];
        }
        return result;
    }
};