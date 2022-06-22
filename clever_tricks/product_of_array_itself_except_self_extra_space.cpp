class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodLeft (nums.begin(), nums.end()), prodRight (nums.begin(), nums.end());
        
        for(int i = 1; i < n; i++)
        {
            prodLeft[i] *= prodLeft[i-1];
            prodRight[n-i-1] *= prodRight[n-i];
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            int prod = 1;
            
            if(i > 0)
            {
                prod *= prodLeft[i-1];
            }
            
            if(i < n-1)
            {
                prod *= prodRight[i+1];
            }
            
            result.push_back(prod);
        }
        
        return result;
    }
};
