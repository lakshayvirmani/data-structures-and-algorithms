class Solution {
public:
    bool isLetter(char ch)
    {
        int charVal = int(ch);
        return ((charVal >= int('A') && charVal <= int('Z')) || (charVal >= int('a') && charVal <= int('z')));
    }
    
    bool isNumeric(char ch)
    {
        int charVal = int(ch);
        return (charVal >= int('0') && charVal <= int('9'));
    }
    
    bool isAlphaNumeric(char ch)
    {
        return (isLetter(ch) || isNumeric(ch));
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i<=j)
        {
            if(isAlphaNumeric(s[i]) && isAlphaNumeric(s[j]))
            {
                if(s[i] == s[j] || (isLetter(s[i]) && isLetter(s[j])  && (s[i] - 'A' == s[j] - 'a' || s[i] - 'a' == s[j] - 'A')))
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
            else if(!isAlphaNumeric(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return true;
    }
};
