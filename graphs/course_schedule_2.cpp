class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList (numCourses);
        vector<int> indegree (numCourses, 0);
        
        // initialize
        for(const vector<int>& prereq : prerequisites)
        {
            adjList[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        queue<int> q;
        
        // find courses with no dependency
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        // topological sort
        vector<int> result;
        int numEdgesLeft = prerequisites.size();
        while(!q.empty())
        {
            const int& u = q.front();
            result.push_back(u);
            
            for(const int& v : adjList[u])
            {
                indegree[v]--;
                
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
            
            numEdgesLeft -= adjList[u].size();
            q.pop();
        }
        
        // cycle exists
        if(numEdgesLeft != 0)
        {
            result.clear();
        }
        
        return result;
    }
};
