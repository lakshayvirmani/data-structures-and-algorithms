struct comp
{
    bool operator()(const vector<int>& l, const vector<int>& r)
    {
        return l[1] >= r[1];
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adjList(n+1);
        for(const vector<int>& time : times)
        {
            const int& u = time[0];
            const int& v = time[1];
            const int& w = time[2];
            
            adjList[u].push_back({v, w});
        }
        
        // initialize
        vector<int> dis(n+1, INT_MAX);
        dis[0] = 0;
        dis[k] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        pq.push({k, 0});
        
        while(!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            
            const int& u = cur[0];
            const int& d = cur[1];
            
            if(dis[u] < d)
            {
                // no need to update neighbors
                continue;
            }
            
            for(const vector<int>& neigh : adjList[u])
            {
                const int& v = neigh[0];
                const int& w = neigh[1];
                
                if(dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pq.push({v, dis[v]});
                }
            }
        }
        
        // find farthest node from k
        int result = 0;
        for(const int& d : dis)
        {
            if(d == INT_MAX)
            {
                result = -1;
                break;
            }
            
            result = max(result, d);
        }
        
        return result;
    }
};
