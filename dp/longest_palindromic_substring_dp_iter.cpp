class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp;
        for(int i = 0; i < n; i++)
        {
            dp.push_back(vector<bool>(n, false));
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[i][j] = true;
            }
        }
        
        int j, maxLen, resultI, resultJ;
        
        maxLen = 1;
        resultI = 0;
        resultJ = 0;
        
        for(int l = 2; l <= n; l++)
        {
            for(int i = 0; i + l - 1 < n; i++)
            {
                j = i + l - 1;
                
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    if(l > maxLen)
                    {
                        maxLen = l;
                        resultI = i;
                        resultJ = j;
                    }
                }
            }
        }
        
        return s.substr(resultI, resultJ - resultI + 1);
    }
};
