class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(m.find(sum - k) != m.end())
            {
                count += m[sum-k];
            }
            
            m[sum]++;
        }
        
        return count;
    }
};
