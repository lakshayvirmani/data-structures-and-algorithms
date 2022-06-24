class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        calc(candidates, target, 0, vector<int>(), result);
        return result;
    }
private:
    void calc(vector<int>& candidates, int target, int i, vector<int> cur, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(cur);
            return;
        }
        
        for(int j = i; j < candidates.size(); j++)
        {
            if(candidates[j] > target)
            {
                break;
            }

            cur.push_back(candidates[j]);
            calc(candidates, target - candidates[j], j, cur, result);
            cur.pop_back();
        }
    }
};
