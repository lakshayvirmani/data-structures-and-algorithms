class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> leaves;
        
        if(n < 2)
        {
            for(int i = 0; i < n; i++)
            {
                leaves.push_back(i);
            }
            
            return leaves;
        }
        
        vector<unordered_set<int>> adjList(n);
        
        // construct graph
        int u, v;
        for(auto edge : edges)
        {
            u = edge[0];
            v = edge[1];
            
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        
        // initiate topological sort
        for(int i = 0; i < n; i++)
        {
            if(adjList[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        
        // toposort
        int remainingNodes = n;
        while(remainingNodes > 2)
        {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            
            for(int leaf : leaves)
            {
                int neighbor = *(adjList[leaf].begin());
                
                adjList[neighbor].erase(leaf);
                
                if(adjList[neighbor].size() == 1)
                {
                    newLeaves.push_back(neighbor);
                }
            }
            
            leaves = newLeaves;
        }
        
        return leaves;
    }
};
