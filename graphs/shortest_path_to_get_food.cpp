class Solution {
    vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int BFS(int i, int j, const vector<vector<char>>& grid, const int& m, const int& n)
    {
        int distance = 0;
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        q.push({i,j});
        visited[i][j] = true;
        q.push({-1, -1});
        
        while(!q.empty())
        {
            const vector<int>& cur = q.front();
            
            if(cur[0] == -1 && q.size() > 1)
            {
                distance++;
                q.push({-1, -1});
            }
            else
            {
                for(const vector<int>& move : moves)
                {
                    i = cur[0] + move[0];
                    j = cur[1] + move[1];

                    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 'X' && !visited[i][j])
                    {
                        if(grid[i][j] == '#')
                        {
                            return distance + 1;
                        }

                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
            
            q.pop();
        }
        
        return -1;
    }
    
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '*')
                {
                    return BFS(i, j, grid, m, n);
                }
            }
        }
        
        return -1;
    }
};
