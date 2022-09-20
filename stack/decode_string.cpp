class Solution {
public:
    string decodeString(string s) {
        int n = s.size(), i = 0;
        stack<string> decodeStk;
        stack<int> repsStk;
        
        while(i < n)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || s[i] == '[')
            {
                decodeStk.push(string(1, s[i]));
                i++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                // calculate repetitions
                int reps = 0;
                while(i < n && s[i] != '[')
                {
                    reps = reps * 10 + s[i] - '0';
                    i++;
                }
                repsStk.push(reps);
            }
            else if(s[i] == ']')
            {
                // decode string
                int reps = repsStk.top();
                repsStk.pop();
                
                string cur = "";
                while(decodeStk.top() != "[")
                {
                    cur += decodeStk.top();
                    decodeStk.pop();
                }
                
                // remove "["
                decodeStk.pop();
                
                // decode current string
                string repeatedCur = "";
                while(reps--)
                {
                    repeatedCur += cur;
                }
                
                // push decoded string onto stk
                decodeStk.push(repeatedCur);
                
                i++;
            }
            else
            {
                throw "Not implemented.";
            }
        }
        
        string result = "";
        while(!decodeStk.empty())
        {
            result += decodeStk.top();
            decodeStk.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
