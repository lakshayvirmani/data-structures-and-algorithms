class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        int i, j, maxReps, result;
        unordered_map<char, int> m;
        
        i = j = maxReps = result = 0;
        while(j < n)
        {
            m[s[j]]++;
            maxReps = max(maxReps, m[s[j]]);
            
            if(j - i + 1 - maxReps > k)
            {
                m[s[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};
