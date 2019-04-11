

class Solution {
public:
    bool canWinNim(int n) {
        return (n & 0x03) != 0;
        //n % 4 == 0, if you left 4, you'll win
    }
};