class Solution {
public:
    int findComplement(int num) {
    	int temp = num;
        int bitCount = 1;
        while(temp != 0)
        {
        	temp >>= 1;
        	bitCount <<= 1;
        }
        return ((bitCount - 1) ^ num);
    }
};


/* Following code is referenced from internet
* int findComplement(int num) {  
*        unsigned int mask = ~0;  
*        while(num&mask) mask <<= 1;  
*        return (~mask) ^ num; // return (~mask) & (~num);
*    } 
*/