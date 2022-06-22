class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, INT_MAX);
        vector<int> sortedCoins(coins.begin(), coins.end());
        sort(sortedCoins.begin(), sortedCoins.end());
        
        // initialize
        dp[0] = 1;
        
        for(int i = 1; i <= amount; i++)
        {
            int change = INT_MAX;
            
            for(int coin : sortedCoins)
            {
                if(coin > i)
                {
                    break;
                }
                
                change = min(change, dp[i - coin]);
            }
            
            if(change != INT_MAX)
            {
                dp[i] = change + 1;
            }
        }
        
        if(dp[amount] == INT_MAX)
        {
            return -1;
        }
        
        return dp[amount] - 1;
    }
};
