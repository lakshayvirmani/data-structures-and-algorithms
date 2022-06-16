class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int target = 0; target < n - 2; target++)
        {
            if(target != 0 && nums[target] == nums[target - 1])
            {
                continue;
            }
            
            int reqSum = - nums[target];
            int i = target + 1;
            int j = n - 1;
            
            while(i < j)
            {
                if(i != target + 1 && nums[i] == nums[i - 1])
                {
                    i++;
                }
                else if(j != n - 1 && nums[j] == nums[j + 1])
                {
                    j--;
                }
                else if(nums[i] + nums[j] == reqSum)
                {
                    vector<int> cur;
                    cur.push_back(nums[target]);
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    result.push_back(cur);
                    
                    i++;
                    j--;
                }
                else if(nums[i] + nums[j] < reqSum)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
        
        return result;
    }
};
