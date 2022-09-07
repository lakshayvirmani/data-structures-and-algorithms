class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        
        // initialize
        // mark self-distances to 0
        for(int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
        }
        // add all edges
        for(const vector<int>& edge : edges)
        {
            const int& u = edge[0];
            const int& v = edge[1];
            const int& w = edge[2];
            
            dis[u][v] = w;
            dis[v][u] = w;
        }
        
        // update all weights using all possible middle edges
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        
        // find city
        int minCity = 0, minCount = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(dis[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            
            if(count <= minCount)
            {
                minCount = count;
                minCity = i;
            }
        }
        
        return minCity;
    }
};
