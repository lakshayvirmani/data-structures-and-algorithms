class Solution {
    pair<int, int> moves[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i < n; i++)
        {
            result.push_back(vector<int>(m, INT_MAX));
        }
        
        queue<pair<int, int>> q;
        
        // add all the 0s to the queue
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            
            int curX = cur.first;
            int curY = cur.second;
            
            for(auto move : moves)
            {
                int newX = move.first + curX;
                int newY = move.second + curY;

                if(newX < 0 || newX >= mat.size() || newY < 0 || newY >= mat[0].size() || mat[newX][newY] == 0 || result[newX][newY] <= result[curX][curY] + 1)
                {
                    continue;
                }
                else
                {
                    result[newX][newY] = result[curX][curY] + 1;
                    q.push({newX, newY});
                }
            }
        }
        
        return result;
    }
};
