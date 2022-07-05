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
        
        vector<vector<optional<bool>>> dp;
        for(int i = 0; i < n; i++)
        {
            dp.push_back(vector<optional<bool>>(subsetSum + 1, nullopt));
        }
        
        return dfs(nums, n, subsetSum, dp);
    }
private:
    bool  dfs(vector<int>& nums, int n, int subsetSum, vector<vector<optional<bool>>>& dp)
    {
        if(subsetSum == 0)
        {
            return true;
        }
        
        if(n == 0 || subsetSum < 0)
        {
            return false;
        }
        
        if(dp[n - 1][subsetSum] != nullopt)
        {
            return (dp[n - 1][subsetSum] == true);
        }
        
        bool result = dfs(nums, n - 1, subsetSum, dp) || dfs(nums, n - 1, subsetSum - nums[n - 1], dp);
        
        dp[n - 1][subsetSum] = result;
        
        return result;
    }
};
