class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement, cnt;
        
        majorityElement = nums[0];
        cnt = 1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(majorityElement == nums[i])
            {
                cnt++;
            }
            else if(cnt == 1)
            {
                majorityElement = nums[i];
            }
            else
            {
                cnt--;
            }
        }
        
        return majorityElement;
    }
};
