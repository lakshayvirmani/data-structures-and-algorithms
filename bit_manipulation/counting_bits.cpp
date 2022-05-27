class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cnt (n + 1, 1);
        cnt[0] = 0;
        int prev = 1, cur = 2;
        
        for(int i=1; i<=n; i++)
        {
            
            if(i > cur)
            {
                prev = cur;
                cur *= 2;
            }
            
            if(i != cur)
            {
                cnt[i] += cnt[i-prev];
            }
        }
        
        return cnt;
    }
};
