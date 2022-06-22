class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod;
        vector<int> result (n, 1);
        
        prod = nums[0];
        for(int i = 1; i < n; i++)
        {
            result[i] *= prod;
            prod *= nums[i];
        }
        
        prod = nums[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            result[i] *= prod;
            prod *= nums[i];
        }
        
        return result;
    }
};
