class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx0, idx2;
        idx0 = 0;
        idx2 = nums.size() - 1;
        
        for(int i = 0; i <= idx2;)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[idx0]);
                idx0++;
                i++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i], nums[idx2]);
                idx2--;
            }
            else
            {
                i++;
            }
        }
    }
};
