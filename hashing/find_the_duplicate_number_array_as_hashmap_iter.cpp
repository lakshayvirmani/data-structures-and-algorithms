class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = 0, temp;
        
        while(cur != nums[cur])
        {
            temp = nums[cur];
            nums[cur] = cur;
            cur = temp;
        }
        
        return cur;
    }
};
