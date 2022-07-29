class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int diff, reserve = 0, req = 0, result;
        for(int i = 0; i < n; i++)
        {
            diff = gas[i] - cost[i];
            
            if(diff >= 0)
            {
                if(reserve == 0)
                {
                    result = i;
                }
                
                reserve += diff;
            }
            else
            {
                if(-diff > reserve)
                {
                    diff += reserve;
                    reserve = 0;
                    req += -diff;
                }
                else
                {
                    reserve += diff;
                }
            }
        }
        
        if(req > reserve)
        {
            result = -1;
        }
        
        return result;
    }
};
