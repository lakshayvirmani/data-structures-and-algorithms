class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return recursiveCheck(0, s, dict, dp);
    }
private:    
    bool recursiveCheck(int i, string& s, unordered_set<string>& dict, vector<int>& dp)
    {   
        if(s.size() == 0)
        {
            return true;
        }
        
        if(dp[i] == -1)
        {
            bool result = dict.count(s.substr(i));
        
            for(int j = i; j < s.size() && !result; j++)
            {
                result = dict.count(s.substr(i, j - i + 1)) && recursiveCheck(j + 1, s, dict, dp);
            }
            
            dp[i] = result;
        }
        
        return dp[i];
    }
};
