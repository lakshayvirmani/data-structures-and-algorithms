class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int j = 1; j < n; j++)
        {
            for(int i = 0; i < j; i++)
            {
                if(nums[i] < nums[j])
                {
                    dp[j] = max(dp[j], 1 + dp[i]);
                }
            }
        }
        
        return *(max_element(dp.begin(), dp.end()));
    }
};
