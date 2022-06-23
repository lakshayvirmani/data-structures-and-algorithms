class Solution {
    vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countFresh = 0;
        
        // initialize multi-source bfs
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }
        
        // initial level marker
        q.push({-1, -1});
        
        // multi-source bfs
        int result = -1;
        while(!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();
            
            int i = cur[0];
            int j = cur[1];
            
            // we're crossing a level
            if(i == -1)
            {
                result++;
                
                // previous level nodes have been processed so we can add this marker now for the next level
                if(!q.empty())
                {
                    q.push({-1, -1});
                }
                
                continue;
            }
            
            for(auto move : moves)
            {
                int newI = i + move[0];
                int newJ = j + move[1];
                
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1)
                {
                    grid[newI][newJ] = 2;
                    q.push({newI, newJ});
                    countFresh--;
                }
            }
        }
        
        // verify if all the fresh oranges are rotten or not.
        if(countFresh != 0)
        {
            result = -1;
        }
        
        return result;
    }
};
