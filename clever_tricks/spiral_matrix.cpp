class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> moves({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        int moveIdx, minRow, minCol, maxRow, maxCol;
        
        moveIdx = minCol = 0;
        minRow = 1;
        maxRow = matrix.size() - 1;
        maxCol = matrix[0].size() - 1;
        
        vector<int> result;
        int i = 0, j = 0, numElements = matrix.size() * matrix[0].size();
        while(numElements != 0)
        {
            result.push_back(matrix[i][j]);
            
            if(moveIdx == 0 && j == maxCol)
            {
                moveIdx = 1;
                maxCol--;
            }
            else if(moveIdx == 1 && i == maxRow)
            {
                moveIdx = 2;
                maxRow--;
            }
            else if(moveIdx == 2 && j == minCol)
            {
                moveIdx = 3;
                minCol++;
            }
            else if(moveIdx == 3 && i == minRow)
            {
                moveIdx = 0;
                minRow++;
            }
                
            i += moves[moveIdx][0];
            j += moves[moveIdx][1];
            
            numElements--;
        }
        
        return result;
    }
};
