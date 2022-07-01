class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return recursiveCheck(s, dict);
    }
private:    
    bool recursiveCheck(string s, unordered_set<string>& dict)
    {   
        if(s.size() == 0)
        {
            return true;
        }
        
        bool result = dict.count(s);
        
        for(int i = 0; i < s.size() && !result; i++)
        {
            result = dict.count(s.substr(0, i + 1)) && recursiveCheck(s.substr(i + 1), dict);
        }
        
        return result;
    }
};
