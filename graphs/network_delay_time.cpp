class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // initialize
        vector<int> dis(n+1, INT_MAX);
        dis[0] = 0;
        dis[k] = 0;
        
        // relax all edges n-1 times
        for(int i = 0; i < n - 1; i++)
        {
            for(const vector<int>& time : times)
            {
                const int& u = time[0];
                const int& v = time[1];
                const int& w = time[2];
                
                if(dis[u] != INT_MAX && dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
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
