class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        int totalSubsets = 1 << nums.size();
        for(int i = 0; i < totalSubsets; i++)
        {
            int j = i;
            vector<int> cur;
            int idx = n - 1;
            
            while(j != 0)
            {
                if(j & 1)
                {
                    cur.push_back(nums[idx]);
                }
                idx--;
                j >>= 1;
            }
            
            result.push_back(cur);
        }
        
        return result;
    }
};
