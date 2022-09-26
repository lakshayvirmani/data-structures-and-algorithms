class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i > maxReachable)
            {
                break;
            }
            
            maxReachable = max(maxReachable, nums[i] + i);
        }
        
        return (maxReachable >= (n - 1));
    }
};
