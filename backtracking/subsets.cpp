class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        populateSubsets(0, cur, nums, result);
        return result;
    }
private:
    void populateSubsets(int i, vector<int>& cur, vector<int>& nums, vector<vector<int>>& result)
    {
        if(i == nums.size())
        {
            result.push_back(cur);
            return;
        }
        
        populateSubsets(i + 1, cur, nums, result);
        
        cur.push_back(nums[i]);
        populateSubsets(i + 1, cur, nums, result);
        cur.pop_back();
    }
};
