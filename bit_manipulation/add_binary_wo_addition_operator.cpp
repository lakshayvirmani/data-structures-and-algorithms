#include<bitset>
class Solution {
public:
    string addBinary(string a, string b) {
        long x = bitset<32>(a).to_ulong();
        long y = bitset<32>(b).to_ulong();
        long carry;
        
        while(y != 0)
        {
            carry = (x & y) << 1;
            x = x ^ y;
            y = carry;
        }
        
        string result;
        
        if(x == 0)
        {
            result.push_back('0');
        }
            
        while(x != 0)
        {
            result.push_back('0' + x % 2);
            x /= 2;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
