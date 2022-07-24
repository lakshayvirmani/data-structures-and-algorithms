class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), curTemp;
        vector<int> answer(n, 0);
        stack<int> stk;
        
        for(int i = n - 1; i >= 0; i--)
        {
            curTemp = temperatures[i];
            
            while(!stk.empty() && temperatures[stk.top()] <= curTemp)
            {
                stk.pop();
            }
            
            if(!stk.empty())
            {
                answer[i] = stk.top() - i;
            }
            
            stk.push(i);
        }
        
        return answer;
    }
};
