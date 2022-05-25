class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int magCharCount[26] = {0};
        
        for(char ch : magazine)
        {
            magCharCount[ch - 'a']++;
        }
        
        for(char ch : ransomNote)
        {
            if(magCharCount[ch - 'a'] > 0)
            {
                magCharCount[ch - 'a']--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};
