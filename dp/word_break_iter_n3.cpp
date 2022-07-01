class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        vector<vector<bool>> dp;
        for(int i = 0; i < n; i++)
        {
            dp.push_back(vector<bool>(n, false));
            dp[i][i] = dict.count(s.substr(i, 1));
        }
        
        int j;
        for(int l = 2; l <= n; l++)
        {
            for(int i = 0; i + l - 1 < n; i++)
            {
                j = i + l - 1;
                dp[i][j] = dict.count(s.substr(i, j - i + 1));
                
                for(int k = i; k < j && !dp[i][j]; k++)
                {
                    dp[i][j] = dp[i][k] && dp[k+1][j];
                }
            }
        }
        
        return dp[0][n-1];
    }
};
