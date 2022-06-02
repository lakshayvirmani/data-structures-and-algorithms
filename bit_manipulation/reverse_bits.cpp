class Solution {
public:
    uint32_t reverseBitsIterate(uint32_t n) {
        uint32_t ans = 0;
        int bits = 31;
        
        while(bits--)
        {
            ans |= n & 1;
            ans <<= 1;
            n >>= 1;
        }
        
        ans |= n & 1;
        
        return ans;
    }

    map<uint32_t, uint32_t> cache;

    uint32_t reverseByte(uint32_t byte)
    {
        if(cache.find(byte) != cache.end())
        {
            return cache[byte];
        }
        
        uint32_t temp = byte;
        uint32_t reversedByte = 0;
        uint32_t shifts = 7;
        while(shifts--)
        {
            reversedByte |=  temp & 1;
            reversedByte <<= 1;
            temp >>= 1;
        }
        
        reversedByte |=  temp & 1;
        
        cache[byte] = reversedByte;
        
        return reversedByte;
    }
    
    uint32_t reverseBitsBytewiseWithCache(uint32_t n) {
        uint32_t ans = 0;
        uint32_t steps = 3;
        while(steps--)
        {
            ans |= reverseByte(n & 0xff);
            ans <<= 8;
            n >>= 8;
        }
        
        ans |= reverseByte(n & 0xff);
        
        return ans;
    } 
};
