class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = calcCoinChange(coins, amount, dp);
        
        if(result == INT_MAX)
        {
            result = -1;
        }
        
        return result;
    }
private:
    int calcCoinChange(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount < 0)
        {
            return INT_MAX;
        }
        
        if(dp[amount] == -1)
        {
            if(amount == 0)
            {
                dp[amount] = 0;
            }
            else
            {
                int result = INT_MAX;

                for(int coin : coins)
                {
                    result = min(result, calcCoinChange(coins, amount - coin, dp));
                }

                if(result != INT_MAX)
                {
                    result += 1;
                }

                dp[amount] = result;
            }
        }
        
        return dp[amount];
    }
};
