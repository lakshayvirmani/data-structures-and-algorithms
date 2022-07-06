class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        for(int l = 0; l <= nums.size(); l++)
        {
            vector<int> cur;
            populateSubsets(0, l, cur, nums, result);
        }
        
        return result;
    }
private:
    void populateSubsets(int i, int l, vector<int>& cur, vector<int>& nums, vector<vector<int>>& result)
    {
        if(cur.size() == l)
        {
            result.push_back(cur);
            return;
        }
        
        for(; i < nums.size(); i++)
        {
           cur.push_back(nums[i]);
           populateSubsets(i + 1, l, cur, nums, result);
           cur.pop_back(); 
        }
    }
};
