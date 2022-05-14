class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result, max_ahead, i;
        
        result = 0;
        max_ahead = prices[prices.size() - 1];
        i = prices.size() - 2;
        
        while(i >= 0)
        {
            result = max(result, max_ahead - prices[i]);
            max_ahead = max(max_ahead, prices[i]);
            i--;
        }
        
        return result;
    }
};
