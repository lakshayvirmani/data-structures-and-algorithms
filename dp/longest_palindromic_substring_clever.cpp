class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> result = {1, 0, 0};
        for(int i = 0; i < s.size(); i++)
        {
            checkPalin(i, i, s, result);
            checkPalin(i, i + 1, s, result);
        }
        return s.substr(result[1], result[2] - result[1] + 1);
    }
private:
    void checkPalin(int i, int j, string& s, vector<int>& result)
    {
        while(i >= 0 && j < s.size())
        {
            if(s[i] != s[j])
            {
                break;
            }
            
            if(j - i + 1 > result[0])
            {
                result[0] = j - i + 1;
                result[1] = i;
                result[2] = j;
            }
            
            i--;
            j++;
        }
        
        return;
    }
};
