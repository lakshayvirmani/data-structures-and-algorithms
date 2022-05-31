class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, n;
        
        i = 0;
        n = nums.size();
        
        while(i < n && nums[i] != 0)
        {
            i++;
        }
        
        j = i + 1;
        while(j < n)
        {
            if(nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
