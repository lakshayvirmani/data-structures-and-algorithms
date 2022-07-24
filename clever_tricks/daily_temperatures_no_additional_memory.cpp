class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), curTemp, j, hottestDay;
        vector<int> answer(n, 0);
        
        hottestDay = temperatures[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            curTemp = temperatures[i];
            hottestDay = max(hottestDay, curTemp);
            
            if(curTemp == hottestDay)
            {
                continue;
            }
            
            
            j = i + 1;
            while(temperatures[j] <= curTemp && answer[j] != 0)
            {
                j += answer[j];
            }
            
            answer[i] = j - i;
        }
        
        return answer;
    }
};
