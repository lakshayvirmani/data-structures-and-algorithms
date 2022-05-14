#include<map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> valueToIndexMap;
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++)
        {
            auto find_result = valueToIndexMap.find(target - nums[i]);
            
            if(find_result != valueToIndexMap.end())
            {
                result.push_back(i);
                result.push_back(find_result->second);
                break;
            }
            
            valueToIndexMap[nums[i]] = i;
        }
        
        return result;
    }
};
