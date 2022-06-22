class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int numEdges = 0;
        vector<int> indegree(numCourses, 0);
        
        // construct graph, count edges and populate indegree
        for(auto prerequisite : prerequisites)
        {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            numEdges++;
            indegree[prerequisite[1]]++;
        }
        
        // construct set S
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            numEdges -= adj[cur].size();
            
            for(int neighbor : adj[cur])
            {
                if(indegree[neighbor] == 1)
                {
                    q.push(neighbor);
                }
                indegree[neighbor]--;
            }
            
            //adj[cur].clear();
        }
        
        return (numEdges == 0);
    }
};
