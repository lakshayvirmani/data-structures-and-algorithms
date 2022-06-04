class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int n, newStart, newEnd;
        n = intervals.size();
        
        // Search where to insert
        int i = 0;
        while(i < n && newInterval[0] > intervals[i][1])
        {
            // add the smaller non-overlapping intervals as is into the result
            result.push_back(intervals[i]);
            i++;
        }
        
        if(i < n)
        {
            newStart = min(intervals[i][0], newInterval[0]);
        }
        else
        {
            newStart = newInterval[0];
        }
        
        // Search till where to merge
        while(i < n && newInterval[1] >= intervals[i][0])
        {
            i++;
        }
        
        // check if merge needed
        if(i != 0 && i <= n && newInterval[1] >= intervals[i-1][0])
        {
            newEnd = max(newInterval[1], intervals[i-1][1]);
        }
        else
        {
            newEnd = newInterval[1];
        }
        
        // add the updated new interval into the result
        vector<int> updatedNewInterval;
        updatedNewInterval.push_back(newStart);
        updatedNewInterval.push_back(newEnd);
        
        result.push_back(updatedNewInterval);
        
        // add the remaining intervals into the result
        while(i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
