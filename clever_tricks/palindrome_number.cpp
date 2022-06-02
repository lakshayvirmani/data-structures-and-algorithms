class Solution {
public:
    bool isPalindrome_revertHalfNumber(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        
        int y = 0;
        
        while(x > y)
        {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        
        return x == y || x == y/10;
    }

    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        
        long l = 1, r = 10;
        
        while(x >= l)
        {
            l *= 10;
        }
        
        if(l > 1)
        {
            l /= 10;
        }
        
        int lDigit, rDigit;
        
        while(l >= r)
        {
            lDigit = int(x / l);
            lDigit %= 10;
            
            rDigit = x % r;
            rDigit = int(rDigit / int(r / 10));
            
            if(lDigit != rDigit)
            {
                return false;
            }
            
            l /= 10;
            r *= 10;
        }
        
        return true;
    }
};
