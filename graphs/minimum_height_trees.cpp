class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
        {
            return vector<int>({0});
        }
        
        
        vector<vector<int>> adjList(n);
        vector<int> edgeCounter(n, 0);
        
        for(vector<int> edge : edges)
        {
            edgeCounter[edge[0]]++;
            edgeCounter[edge[1]]++;
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> leafResult;
        int maxHeight = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(edgeCounter[i] == 1)
            {
                vector<bool> visited(n, false);
                vector<int> path;
                
                visited[i] = true;
                path.push_back(i);
                
                dfs(i, 0, maxHeight, visited, path, edgeCounter, leafResult, adjList);
            }
        }
        
        return leafResult;
    }
    
private:
    void dfs(int i, int curHeight, int& maxHeight, vector<bool>& visited, vector<int>& path, vector<int>& edgeCounter, vector<int>& leafResult, vector<vector<int>>& adjList)
    {
        if(curHeight >= maxHeight && edgeCounter[i] == 1)
        {
            processHeightAndUpdateResult(curHeight, maxHeight, path, leafResult);
        }
        
        for(int v : adjList[i])
        {
            if(!visited[v])
            {
                path.push_back(v);
                visited[v] = true;
                dfs(v, curHeight + 1, maxHeight, visited, path, edgeCounter, leafResult, adjList);
                path.pop_back();
            }
        }
    }
    
    void processHeightAndUpdateResult(int& curHeight, int& maxHeight, vector<int>& path, vector<int>& leafResult)
    {
        leafResult.clear();
        int n = path.size();

        if(n % 2 == 0)
        {
            leafResult.push_back(path[n/2 - 1]);
        }
        
        leafResult.push_back(path[n/2]);

        maxHeight = curHeight;
    }
};
