class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        
        int i = 0, n = s.size();
        
        // skip whitespace
        while(i < n && s[i] == ' ')
        {
            i++;
        }
        
        
        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }
        
        int digit;
        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            digit =  s[i] - '0';
            
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                if(sign == 1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        
        return sign * ans;
    }
};
