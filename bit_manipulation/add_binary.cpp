#include<algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int sum, carry;
        
        sum = carry = 0;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for(int i=0; i<a.size() || i < b.size(); i++)
        {
            sum = carry;
            
            if(i<a.size())
            {
                sum += a[i] - '0';
            }
            
            if(i<b.size())
            {
                sum += b[i] - '0';
            }
            
            carry = sum / 2;
            sum = sum % 2;
            
            result.push_back('0' + sum);
        }
        
        if(carry != 0)
        {
            result.push_back('0' + carry);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
