class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // binary search to find the first element equal to x to just smaller
        int i, j, mid, reqIdx = 0;
        i = 0, j = n-1;
        while(i <= j)
        {
            mid = i + (j - i) / 2;
            
            if(arr[mid] <= x)
            {
                reqIdx = mid;
                i = mid + 1;
            }
            else
            {
                j =  mid - 1;
            }
        }
        
        // find the range of closest elements
        i = reqIdx;
        j = reqIdx + 1;
        while((i >= 0 || j < n) && j - i - 1 < k)
        {
            if(i < 0)
            {
                j++;
            }
            else if(j >= n)
            {
                i--;
            }
            else if(abs(arr[i] - x) <= abs(arr[j] - x))
            {
                i--;
            }
            else
            {
                j++;
            }
        }
        
        return vector(arr.begin() + i + 1, arr.begin() + i + 1 + k);
    }
};
