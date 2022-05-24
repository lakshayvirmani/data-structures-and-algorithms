#include <queue>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        pair<int, int> moves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        if(image[sr][sc] == newColor)
        {
            return image;
        }
        
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int,int>> q;
        image[sr][sc] *= -1;
        q.push({sr, sc});
        
        while(!q.empty())
        {
            pair<int, int> current = q.front();
            int currentX = current.first;
            int currentY = current.second;
            int currentColor = -1 * image[currentX][currentY];
            q.pop();
            
            for(auto move : moves)
            {
                int newX = currentX + move.first;
                int newY = currentY + move.second;
                
                if(0 <= newX && newX < m && 0 <= newY && newY < n && image[newX][newY] >= 0 && image[newX][newY] == currentColor)
                {
                    image[newX][newY] *= -1;
                    q.push({newX, newY});
                }
            }
            
            image[currentX][currentY] = newColor;
        }
        
        return image;
    }
};
