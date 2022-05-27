class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // n & (n-1) sets the least significant bit of n to 0.
        while(n != 0)
        {
            n &= (n-1);
            count++;
        }
        
        return count;
    }
};
