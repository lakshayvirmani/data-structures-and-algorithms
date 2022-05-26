class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0, current;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'V')
            {
                current = 5;
            }
            else if(s[i] == 'L')
            {
                current = 50;
            }
            else if(s[i] == 'D')
            {
                current = 500;
            }
            else if(s[i] == 'M')
            {
                current = 1000;
            }              
            else if(s[i] == 'I')
            {
                current = 1;
            }
            else if(s[i] == 'X')
            {
                current = 10;
            }
            else
            {
                current = 100;
            }

            if(i != (n-1) && (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) || (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) || (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')))
            {
                current *= -1;
            }                                                                        
            
            ans += current;
        }
        
        return ans;
    }
};
