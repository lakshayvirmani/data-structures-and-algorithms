class Solution {
    unordered_map<char, string> mapping = {{'2', "abc"},
                                           {'3', "def"},
                                           {'4', "ghi"},
                                           {'5', "jkl"},
                                           {'6', "mno"},
                                           {'7', "pqrs"},
                                           {'8', "tuv"},
                                           {'9', "wxyz"}};
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if(digits.size() > 0)
        {
            constructCombinations(0, "", digits, result);
        }
        
        return result;
    }
    
private:
    void constructCombinations(int i, string cur, string& digits, vector<string>& result)
    {
        if(i == digits.size())
        {
            result.push_back(cur);
            return;
        }
        
        char digit = digits[i];
        string mappedLetters = mapping[digit];
        for(char ch : mappedLetters)
        {
            cur.push_back(ch);
            constructCombinations(i + 1, cur, digits, result);
            cur.pop_back();
        }
    }
};
