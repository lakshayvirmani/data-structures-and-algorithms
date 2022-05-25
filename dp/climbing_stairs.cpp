class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
        {
            return n;
        }
        
        int a = 1;
        int b = 2;
        int cur;
        
        for(int i=3; i<=n; i++)
        {
            cur = a + b;
            a = b;
            b = cur;
        }
        
        return b;
    }
};
