class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end());
        
        int curStart = intervals[0][0];
        int curEnd = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(curEnd >= intervals[i][0])
            {
                curEnd = max(curEnd, intervals[i][1]);
            }
            else
            {
                result.push_back(vector<int>({curStart, curEnd}));
                curStart = intervals[i][0];
                curEnd = intervals[i][1];
            }
        }
        
        result.push_back(vector<int>({curStart, curEnd}));
        
        return result;
    }
};
