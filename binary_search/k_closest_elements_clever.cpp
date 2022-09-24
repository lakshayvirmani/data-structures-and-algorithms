class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // binary search to find the left bound
        int l, r, mid;
        l = 0, r = n - k;
        while(l < r)
        {
            mid = l + (r - l) / 2;
            
            if(x - arr[mid] > arr[mid + k] - x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        
        return vector(arr.begin() + l, arr.begin() + l + k);
    }
};
