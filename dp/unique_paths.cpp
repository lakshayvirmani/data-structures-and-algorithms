class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        int j = 1;
        
        for(int i = n; i <= m + n - 2; i++)
        {
            ans = (ans * i) / j;
            j += 1;
        }
        
        return ans;
    }
};
