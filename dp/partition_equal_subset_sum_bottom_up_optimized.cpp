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
        
        vector<bool> dp (subsetSum + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n && !dp[subsetSum]; i++)
        {
            for(int j = subsetSum; j >= 1; j--)
            {
                dp[j] = dp[j] || (nums[i-1] <= j && dp[j-nums[i-1]]);
            }
        }
        
        return dp[subsetSum];
    }
};
