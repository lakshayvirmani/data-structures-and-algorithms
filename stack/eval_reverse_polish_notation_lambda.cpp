class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<char, function<int(int, int)>> operators = {
            {'+', [] (int a, int b) { return a + b; }},
            {'-', [] (int a, int b) { return a - b; }},
            {'*', [] (int a, int b) { return a * b; }},
            {'/', [] (int a, int b) { return a / b; }}
        };
        
        stack<int> stk;
        
        for(string s : tokens)
        {
            // check for operator
            if(s.length() == 1 && operators.find(s[0]) != operators.end())
            {
                int operand2 = stk.top();
                stk.pop();
                int operand1 = stk.top();
                stk.pop();
                
                stk.push(operators[s[0]](operand1, operand2));
            }
            else
            {
                stk.push(stoi(s));
            }
        }
        
        return stk.top();
    }
};
