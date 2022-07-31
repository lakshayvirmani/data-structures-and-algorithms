class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9, m = 9;
        
        vector<vector<bool>> seenRows(9, vector<bool>(9, false));
        vector<vector<bool>> seenCols(9, vector<bool>(9, false));
        vector<vector<bool>> seenBlocks(9, vector<bool>(9, false));
        
        bool isValid = true;
        int blockIdx, valIdx;
        for(int i = 0; i < n && isValid; i++)
        {
            for(int j = 0; j < m && isValid; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                
                valIdx = board[i][j] - '1';
                if(valIdx >= 0 && valIdx < 9)
                {
                    blockIdx = (i / 3) * 3 + (j / 3);
                    if(seenRows[i][valIdx] || seenCols[j][valIdx] || seenBlocks[blockIdx][valIdx])
                    {
                        isValid = false;
                    }
                    else
                    {
                        seenRows[i][valIdx] = true;
                        seenCols[j][valIdx] = true;
                        seenBlocks[blockIdx][valIdx] = true;
                    }
                }
                else
                {
                    isValid = false;
                }
            }
        }
        
        return isValid;
    }
};
