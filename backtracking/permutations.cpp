class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
private:
    void backtrack(int first, vector<int>& nums, vector<vector<int>>& result)
    {
        if(first == nums.size())
        {
            result.push_back(nums);
        }
        
        for(int i = first; i < nums.size(); i++)
        {
            swap(nums[i], nums[first]);
            
            backtrack(first + 1, nums, result);
            
            swap(nums[first], nums[i]);
        }
    }
};
