class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]].size() < 3)
            {
                m[nums[i]].push_back(i);
            }
        }
        
        set<vector<int>> answer;
        for(auto it1 = m.begin(); it1 != m.end(); it1++)
        {
            int num1 = it1->first;
            
            for(auto it2 = it1; it2 != m.end(); it2++)
            {
                int num2 = it2->first;
                int num3 = -(num1 + num2);
                
                if(m.find(num3) != m.end())
                {
                    vector<int>& idxs1 = it1->second;
                    vector<int>& idxs2 = it2->second;
                    vector<int>& idxs3 = m.find(num3)->second;
                    
                    for(int idx1 : idxs1)
                    {
                        for(int idx2 : idxs2)
                        {
                            for(int idx3 : idxs3)
                            {
                                if(idx1 != idx2 && idx2 != idx3 && idx1 != idx3)
                                {
                                    vector<int> result;
                                    result.push_back(nums[idx1]);
                                    result.push_back(nums[idx2]);
                                    result.push_back(nums[idx3]);
                                    sort(result.begin(), result.end());
                                    answer.insert(result);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return vector<vector<int>> (answer.begin(), answer.end());
    }
};
