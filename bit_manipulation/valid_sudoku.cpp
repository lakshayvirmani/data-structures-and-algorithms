class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9, m = 9;
        
        vector<int> seenRows(9, false);
        vector<int> seenCols(9, false);
        vector<int> seenBlocks(9, false);
        
        bool isValid = true;
        int blockIdx, valIdx, mask;
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
                    mask = 1 << valIdx;
                    
                    if((seenRows[i] & mask) || (seenCols[j] & mask) || (seenBlocks[blockIdx] & mask))
                    {
                        isValid = false;
                    }
                    else
                    {
                        seenRows[i] |= mask;
                        seenCols[j] |= mask;
                        seenBlocks[blockIdx]|= mask;
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
