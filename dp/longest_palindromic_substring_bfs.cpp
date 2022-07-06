class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        queue<vector<int>> q;
        q.push({0, n - 1});
        
        int i, j;
        string result;
        while(!q.empty())
        {
            i = q.front()[0];
            j = q.front()[1];
            q.pop();
            
            if(isPalin(i, j, s))
            {
                result = s.substr(i, j - i + 1);
                break;
            }
            
            q.push({i + 1, j});
            q.push({i, j - 1});
        }
        
        return result;
    }
private:
    bool isPalin(int i, int j, string& s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
