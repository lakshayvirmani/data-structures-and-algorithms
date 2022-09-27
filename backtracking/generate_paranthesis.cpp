class Solution {
    void generate(int open, int close, string cur, vector<string>& result)
    {
        if(open == 0 && close == 0)
        {
            result.push_back(cur);
            return;
        }
        
        if(open > 0)
        {
            cur.push_back('(');
            generate(open - 1, close, cur, result);
            cur.pop_back();
        }
        
        if(close > 0 && open < close)
        {
            cur.push_back(')');
            generate(open, close - 1, cur, result);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, "", result);
        return result;
    }
};
