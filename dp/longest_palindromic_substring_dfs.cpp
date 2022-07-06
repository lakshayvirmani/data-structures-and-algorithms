class Solution {
public:
    string longestPalindrome(string s) {
        return findLongestPalin(0, s.size() - 1, s);
    }
private:
    string findLongestPalin(int i, int j, string& s)
    {
        if(i > j)
        {
            return "";
        }
        
        string result;
        if(isPalin(i, j, s))
        {
            result = s.substr(i, j - i + 1);
        }
        else
        {
            string resultA = findLongestPalin(i + 1, j, s);
            string resultB = findLongestPalin(i, j - 1, s);
            
            if(resultA.size() > resultB.size())
            {
                result = resultA;
            }
            else
            {
                result = resultB;
            }
        }
        
        return result;
    }
    
    bool isPalin(int i, int j, string& s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
