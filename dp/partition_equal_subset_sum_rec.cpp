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
        
        return dfs(nums, n, subsetSum);
    }
private:
    bool  dfs(vector<int>& nums, int n, int subsetSum)
    {
        if(subsetSum == 0)
        {
            return true;
        }
        
        if(n == 0 || subsetSum < 0)
        {
            return false;
        }
        
        bool result = dfs(nums, n - 1, subsetSum) || dfs(nums, n - 1, subsetSum - nums[n - 1]);
        
        return result;
    }
};
