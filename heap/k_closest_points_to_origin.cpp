class comp
{
    public:
        bool operator()(pair<int, int> & l, pair<int, int> & r)
        {
            return l.first < r.first;
        }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for(int i = 0; i<points.size(); i++)
        {
            auto point = points[i];
            int dis = point[0] * point[0] + point[1] * point[1];
            
            if(pq.size() < k)
            {
                pq.push({dis, i});
            }
            else if(dis < pq.top().first)
            {
                pq.pop();
                pq.push({dis, i});
            }
        }
        
        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return result;
    }
};
