class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        int count = 0;
        m[count] = -1;
        
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                count--;
            }
            else
            {
                count++;
            }
            
            if(m.find(count) != m.end())
            {
                result = max(result, i - m[count]);
            }
            else
            {
                m[count] = i;
            }
        }
        
        return result;
    }
};
