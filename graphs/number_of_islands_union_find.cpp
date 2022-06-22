class Solution {
    vector<vector<int>> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // initialize
        vector<int> p (m*n), r(m*n, 0);
        for(int i = 0; i < m*n; i++)
        {
            p[i] = i;
        }
        
        // merge adjacent land
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != '1')
                {
                    continue;
                }
                
                for(vector<int> move : moves)
                {
                    int newI = i + move[0];
                    int newJ = j + move[1];
                    
                    if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == '1')
                    {
                        U(idx(i, j, n), idx(newI, newJ, n), p, r);
                    }
                }
            }
        }
        
        // count islands
        int result = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != '1')
                {
                    continue;
                }
                
                int nodeIdx = idx(i, j, n);
                if(F(nodeIdx, p) == nodeIdx)
                {
                    result++;
                }
            }
        }
        
        return result;
    }
private:
    int idx(int i, int j, int m)
    {
        return i * m + j;
    }
    
    void U(int i, int j, vector<int>& p, vector<int>& r)
    {
        i = F(i, p);
        j = F(j, p);
        
        if(i != j)
        {
            if(r[i] < r[j])
            {
                p[j] = i;
                r[i]++;
            }
            else
            {
                p[i] = j;
                r[j]++;
            }
        }
    }
    
    int F(int i, vector<int>& p)
    {
        if(p[i] != i)
        {
            p[i] = F(p[i], p);
        }
        
        return p[i];
    }
};
