class Solution {
    string generateKey(int& x, int& y)
    {
        return to_string(x) + "," + to_string(y);
    }
    
    int dfs(int x, int y, unordered_map<string, int>& m)
    {
        string key = generateKey(x,y);
        if(m.find(key) != m.end())
        {
            return m[key];
        }
        
        if(x == 0 && y == 0)
        {
            return 0;
        }
        else if(x + y == 2)
        {
            return 2;
        }
        else
        {
            int result = 1 + min(dfs(abs(x-2), abs(y-1), m), dfs(abs(x-1), abs(y-2), m));
            m[key] = result;
            return result;
        }
    }
public:
    int minKnightMoves(int x, int y) {
        unordered_map<string, int> m;
        return dfs(abs(x), abs(y), m);
    }
};
