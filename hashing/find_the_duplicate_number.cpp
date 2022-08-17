class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int result = -1, idx;
        for(int i = 0; i < n; i++)
        {
            idx = abs(nums[i]);
            if(nums[idx] < 0)
            {
                result = idx;
                break;
            }
            else
            {
                nums[idx] *= -1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            nums[i] = abs(nums[i]);
        }
        
        return result;
    }
};
