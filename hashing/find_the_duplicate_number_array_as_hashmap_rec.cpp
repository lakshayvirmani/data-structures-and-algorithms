class Solution {
    int store(int cur, vector<int>& nums)
    {
        if(cur == nums[cur])
        {
            return cur;
        }
        
        int temp = nums[cur];
        nums[cur] = cur;
        return store(temp, nums);
    }
public:
    int findDuplicate(vector<int>& nums) {
        return store(0, nums);
    }
};
