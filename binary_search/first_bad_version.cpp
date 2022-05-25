// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l, r, mid, result;
        
        l = 1;
        r = n;
        result = -1;
        
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            
            if(isBadVersion(mid))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return result;
    }
};
