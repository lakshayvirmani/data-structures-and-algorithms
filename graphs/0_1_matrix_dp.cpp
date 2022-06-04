class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i < n; i++)
        {
            result.push_back(vector<int>(m, INT_MAX));
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    result[i][j] = 0;
                }
                else 
                {
                    if(i != 0 && result[i-1][j] != INT_MAX)
                    {
                        result[i][j] = min(result[i][j], result[i-1][j] + 1);
                    }
                    
                    if(j != 0 && result[i][j-1] != INT_MAX)
                    {
                        result[i][j] = min(result[i][j], result[i][j-1] + 1);
                    }
                }
            }
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i != n-1 && result[i+1][j] != INT_MAX)
                {
                    result[i][j] = min(result[i][j], result[i+1][j] + 1);
                }

                if(j != m-1 && result[i][j+1] != INT_MAX)
                {
                    result[i][j] = min(result[i][j], result[i][j+1] + 1);
                }
            }
        }
        
        return result;
    }
};
