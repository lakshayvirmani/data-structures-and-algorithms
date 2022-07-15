class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sSize = s.size(), pSize = p.size();
        
        if(pSize > sSize)
        {
            return result;
        }
        
        int sCount[26], pCount[26];
        
        for(int i = 0; i < 26; i++)
        {
            sCount[i] = 0;
            pCount[i] = 0;
        }
        
        for(char ch : p)
        {
            pCount[ch - 'a']++;
        }
        
        int i = 0, j = 0;
        while(j < sSize)
        {
            sCount[s[j] - 'a']++;
            
            if(j - i + 1 == pSize)
            {
                if(checkCounts(pCount, sCount))
                {
                    result.push_back(i);
                }
                
                sCount[s[i] - 'a']--;
                i++;
            }
            
            j++;
        }
        
        return result;
    }

private:
    bool checkCounts(int pCount[26], int sCount[26])
    {
        for(int i = 0; i < 26; i++)
        {
            if(pCount[i] != sCount[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
