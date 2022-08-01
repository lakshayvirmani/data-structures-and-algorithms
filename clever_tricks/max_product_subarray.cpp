class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result, maxSoFar, tmpMax, minSoFar, cur;
        
        result = maxSoFar = minSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            cur = nums[i];
            
            tmpMax = max(cur, max(maxSoFar * cur, minSoFar * cur));
            minSoFar = min(cur, min(maxSoFar * cur, minSoFar * cur));
            
            maxSoFar = tmpMax;
            
            result = max(result, maxSoFar);
        }
        
        return result;
    }
};
