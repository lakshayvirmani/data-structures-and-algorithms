class Solution {
    int find(int i, vector<int>& par)
    {
        if(par[i] == -1)
        {
            return i;
        }
        
        par[i] = find(par[i], par);
        return par[i];
    }
    
    bool merge(int i, int j, vector<int>& par, vector<int>& rnk)
    {
        int parI = find(i, par);
        int parJ = find(j, par);
        
        // i and j already belong to the same set. cycle detected.
        if(parI == parJ)
        {
            return false;
        }
        
        if(rnk[parI] < rnk[parJ])
        {
            par[parJ] = parI;
            rnk[parI]++;
        }
        else
        {
            par[parI] = parJ;
            rnk[parJ]++;
        }
        
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        
        if(numEdges != n - 1)
        {
            return false;
        }
        
        vector<int> par (n, -1), rnk(n, 0);
        for(const vector<int>& edge : edges)
        {
            if(!merge(edge[0], edge[1], par, rnk))
            {
                return false;
            }
        }
        
        return true;
    }
};
