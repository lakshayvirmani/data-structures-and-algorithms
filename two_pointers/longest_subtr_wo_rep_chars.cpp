class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charToIdxMap;
        
        int n = s.size(), result = 0;
        
        for(int i = 0, j = 0; j < n; j++)
        {
            if(charToIdxMap.find(s[j]) != charToIdxMap.end())
            {
                i = max(charToIdxMap[s[j]], i);
            }
            
            result = max(result, j - i + 1);
            charToIdxMap[s[j]] = j + 1;
        }
        
        return result;
    }
};
