class UnionFind
{
    vector<int> rnk, par;
public:
    UnionFind(int n)
    {
        par = vector<int>(n, -1);
        rnk = vector<int>(n, 0);
    }
    
    int find(int i)
    {
        if(par[i] == -1)
        {
            return i;
        }
        par[i] = find(par[i]);
        return par[i];
    }
    
    bool merge(int i, int j)
    {
        i = find(i);
        j = find(j);
        
        if(i == j && i != -1 && j != -1)
        {
            // already part of the same set
            return false;
        }
        
        // perform merge
        if(rnk[i] < rnk[j])
        {
            par[j] = i;
            rnk[i]++;
        }
        else
        {
            par[i] = j;
            rnk[j]++;
        }
        
        return true;
    }
};

class Solution {
    static bool comp(const vector<int>& left, const vector<int>& right)
    {
        return left[2] <= right[2];
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // sort the edges in the increasing order of weights
        sort(connections.begin(), connections.end(), comp);
        
        // find the first n - 1 edges that connect new components
        int cost = 0, numSelectedEdges = 0;
        UnionFind uf = UnionFind(n+1);
        for(const vector<int>& connection : connections)
        {
            if(uf.merge(connection[0], connection[1]))
            {
                cost += connection[2];
                numSelectedEdges++;
            }
            
            if(numSelectedEdges == n - 1)
            {
                break;
            }
        }
        
        // didn't merge n unique components
        if(numSelectedEdges != n - 1)
        {
            cost = -1;
        }
        
        return cost;
    }
};
