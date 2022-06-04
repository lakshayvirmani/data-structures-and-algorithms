class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        
        int i, j;
        i = 0;
        j = nums.size() - 1;
        
        while(i <= j)
        {
            if(abs(nums[j]) >= abs(nums[i]))
            {
                result.push_back(nums[j] * nums[j]);
                j--;
            }
            else
            {
                result.push_back(nums[i] * nums[i]);
                i++;
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
