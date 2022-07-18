class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        
        for(char ch : tasks)
        {
            counter[ch - 'A']++;
        }
        
        priority_queue<int> pq;
        for(int cnt : counter)
        {
            if(cnt != 0)
            {
                pq.push(cnt);
            }
        }
        
        n++;
        int result = 0, top;
        
        while(!pq.empty())
        {   
            if(n <= pq.size())
            {
                vector<int> collect;
                
                for(int k = 0; k < n; k++)
                {
                    top = pq.top();
                    
                    if(top - 1 > 0)
                    {
                        collect.push_back(top - 1);
                    }
                    
                    pq.pop();
                }
                
                for(int newVal : collect)
                {
                    
                    pq.push(newVal);
                }
                
                result += n;
            }
            else
            {
                top = pq.top();
                
                result += (top - 1) * n;
                
                while(!pq.empty() && pq.top() == top)
                {
                    result++;
                    pq.pop();
                }
                
                break;
            }
        }
        
        return result;
    }
};
