#include<stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            else
            {
                if(stk.empty() || (stk.top() == '(' and ch != ')') || (stk.top() == '{' and ch != '}') || (stk.top() == '[' and ch != ']'))
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        
        return stk.empty();
    }
};
