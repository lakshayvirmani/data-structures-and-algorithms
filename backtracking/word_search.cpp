class Solution {
    vector<vector<int>> moves = {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        
        for(int i = 0; i < board.size() && !result; i++)
        {
            for(int j = 0; j < board[0].size() && !result; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> visited;
                    for(int k = 0; k < board.size(); k++)
                    {
                        visited.push_back(vector<bool>(board[0].size(), false));
                    }
                    dfs(i, j, 1, board, word, visited, result);
                }
            }
        }
        return result;
    }
private:
    void dfs(int row, int col, int idx, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, bool& result)
    {
        if(result)
        {
            return;
        }
        
        if(idx == word.size())
        {
            result = true;
            return;
        }
        
        visited[row][col] = true;
        
        for(int i = 0; i < moves.size() && !result; i++)
        {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];
            
            if(newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size())
            {
                if(!visited[newRow][newCol] && board[newRow][newCol] == word[idx])
                {
                    dfs(newRow, newCol, idx + 1, board, word, visited, result);
                }
            }
        }
        
        visited[row][col] = false;
    }
};
