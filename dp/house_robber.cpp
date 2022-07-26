class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int result = 0;
        if(n == 1)
        {
            result = nums[0];
        }
        else if(n == 2)
        {
            result = max(nums[0], nums[1]);
        }
        else
        {
            vector<int> dp(3, 0);
            
            dp[0] = 0;
            dp[1] = nums[0];
            dp[2] = max(nums[0], nums[1]);
            
            for(int i = 2; i < n; i++)
            {
                dp[0] = dp[1];
                dp[1] = dp[2];
                dp[2] = max(dp[1], nums[i] + dp[0]); 
            }
            
            result = max(dp[1], dp[2]);
        }
        
        return result;
    }
};
