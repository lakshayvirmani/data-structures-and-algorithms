class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0, n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            result += i - nums[i];
        }
        
        result += n;
        
        return result;
    }
};
