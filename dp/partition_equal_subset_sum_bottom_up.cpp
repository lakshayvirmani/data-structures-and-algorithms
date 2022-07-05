class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
        {
            totalSum += num;
        }
        
        if(totalSum % 2 != 0)
        {
            return false;
        }
        
        int subsetSum = totalSum / 2;
        int n = nums.size();
        
        vector<vector<bool>> dp;
        for(int i = 0; i <= n; i++)
        {
            dp.push_back(vector<bool>(subsetSum + 1, false));
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= subsetSum; j++)
            {
                dp[i][j] = dp[i-1][j] || (nums[i-1] <= j && dp[i-1][j-nums[i-1]]);
            }
        }
        
        return dp[n][subsetSum];
    }
};
