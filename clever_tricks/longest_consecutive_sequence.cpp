class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(const int& num : nums)
        {
            s.insert(num);
        }
        
        int result = 0, cur;
        
        for(int num : nums)
        {
            if(s.find(num - 1) == s.end())
            {
                cur = 1;
                
                while(s.find(num + 1) != s.end())
                {
                    num++;
                    cur++;
                }
                
                result = max(result, cur);
            }
        }
        
        return result;
    }
};
