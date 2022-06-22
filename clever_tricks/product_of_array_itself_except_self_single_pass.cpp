class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prodLeft, prodRight;
        vector<int> result (n, 1);
        
        prodLeft = nums[0];
        prodRight = nums[n-1];
        for(int i = 1; i < n; i++)
        {
            result[i] *= prodLeft;
            prodLeft *= nums[i];
            
            result[n-i-1] *= prodRight;
            prodRight *= nums[n-i-1];
        }
        
        return result;
    }
};
