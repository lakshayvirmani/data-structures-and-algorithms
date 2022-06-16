class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        unordered_set<int> dups;
        unordered_map<int, int> seen;
        
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++)
        {
            if(!dups.insert(nums[i]).second)
            {
                continue;
            }
            
            for(int j = i + 1; j < n; j++)
            {
                int reqSum = -(nums[i] + nums[j]);
                auto it = seen.find(reqSum);
                
                if(it != seen.end() && it->second == i)
                {
                    vector<int> triplet = {nums[i], nums[j], reqSum};
                    sort(triplet.begin(), triplet.end());
                    result.insert(triplet);
                }
                
                seen[nums[j]] = i;
            }
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};
