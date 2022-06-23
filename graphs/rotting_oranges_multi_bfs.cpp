class Solution {
    vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countFresh = 0;
        
        // initialize multi-source bfs
        queue<vector<int>> q;
        vector<vector<bool>> rotten;
        for(int i = 0; i < m; i++)
        {
            rotten.push_back(vector<bool>(n, false));
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    // store distance (time) from nearest rotten orange along with the indices
                    q.push({0, i, j});
                    rotten[i][j] = true;
                }
                else if(grid[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }
        
        // multi-source bfs
        int result = 0;
        while(!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();
            
            int dis = cur[0];
            int i = cur[1];
            int j = cur[2];
            
            result = max(result, dis);
            
            for(auto move : moves)
            {
                int newI = i + move[0];
                int newJ = j + move[1];
                
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1 && !rotten[newI][newJ])
                {
                    rotten[newI][newJ] = true;
                    q.push({dis + 1, newI, newJ});
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
