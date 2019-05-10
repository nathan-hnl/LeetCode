class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int countBits = 0;
        while (z != 0) 
        {
        	if (z & 1 != 0)
        	{
        		countBits++;
        	}
        	z >>= 1;;
        }
        return countBits;
    }
};