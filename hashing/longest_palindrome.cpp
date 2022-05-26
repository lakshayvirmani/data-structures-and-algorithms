#include<map>

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> charCount;
        
        for(char ch : s)
        {
            charCount[ch]++;
        }
        
        bool useOdd = false;
        int result = 0;
        for(auto it = charCount.begin(); it != charCount.end(); it++)
        {
            if(it->second % 2 == 0)
            {
                result += it->second;
            }
            else if(useOdd == false)
            {
                result += it->second;
                useOdd = true;
            }
            else
            {
                result += it->second - 1;
            }
        }
        
        return result;
    }
};
