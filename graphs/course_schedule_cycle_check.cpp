class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // construct graph
        for(auto prerequisite : prerequisites)
        {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        vector<int> visitStatus(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            if(visitStatus[i] == 0 && adj[i].size() > 0)
            {
                if(isCyclic(i, adj, visitStatus))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool isCyclic(int course, vector<vector<int>>& adj, vector<int>& visitStatus)
    {
        visitStatus[course] = 1;
        
        for(int i : adj[course])
        {
            if(visitStatus[i] == 1 || (visitStatus[i] == 0 && isCyclic(i, adj, visitStatus)))
            {
                return true;
            }
        }
        
        visitStatus[course] = 2;
        
        return false;
    }
};
