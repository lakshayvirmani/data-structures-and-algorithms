class Solution {
    vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    void traverseAndColor(int i, int j, vector<vector<bool>>& color, const vector<vector<int>>& heights, const int& m, const int& n)
    {
        queue<vector<int>> q;
        q.push({i, j});
        color[i][j] = true;
        
        while(!q.empty())
        {
            const vector<int>& cur = q.front();
            
            for(const vector<int>& move : moves)
            {
                i = cur[0] + move[0];
                j = cur[1] + move[1];
                
                if(i >= 0 && i < m && j >= 0 && j < n && color[i][j] == 0 && heights[cur[0]][cur[1]] <= heights[i][j])
                {
                    q.push({i,j});
                    color[i][j] = true;
                }
            }
            
            q.pop();
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> color1(m, vector<bool>(n, 0)), color2(m, vector<bool>(n, 0));
        int i, j;
        
        // pacific ocean
        i = 0, j = 0;
        while(i < m)
        {
            if(color1[i][j] == 0)
            {
                traverseAndColor(i, j, color1, heights, m, n);
            }
            i++;
        }
        
        i = 0, j = 0;
        while(j < n)
        {
            if(color1[i][j] == 0)
            {
                traverseAndColor(i, j, color1, heights, m, n);
            }
            j++;
        }
        
        // atlantic ocean
        i = 0, j = n-1;
        while(i < m)
        {
            if(color2[i][j] == 0)
            {
                traverseAndColor(i, j, color2, heights, m, n);
            }
            i++;
        }
        
        i = m-1, j = 0;
        while(j < n)
        {
            if(color2[i][j] == 0)
            {
                traverseAndColor(i, j, color2, heights, m, n);
            }
            j++;
        }
        
        vector<vector<int>> result;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(color1[i][j] + color2[i][j] == 2)
                {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
