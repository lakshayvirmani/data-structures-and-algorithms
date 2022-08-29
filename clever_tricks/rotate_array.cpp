class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        // swap n times
        int count = 0, start = 0;
        int i, newPos, temp, prev;
        while(count < n)
        {
            i = start;
            prev = nums[start];

            while(true && count < n)
            {
                newPos = (i + k) % n;
                temp = nums[newPos];
                nums[newPos] = prev;
                prev = temp;
                i = newPos;
                count++;

                if(start == i)
                {
                    break;
                }
            }

            start++;
        }
        
        return;
    }
};
