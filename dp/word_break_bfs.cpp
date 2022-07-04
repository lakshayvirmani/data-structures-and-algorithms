class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        
        int start;
        
        while(!q.empty())
        {
            start = q.front();
            q.pop();
            
            if(visited[start])
            {
                continue;
            }
            
            for(int end = start + 1; end <= n; end++)
            {
                if(dict.find(s.substr(start, end - start)) != dict.end())
                {
                    q.push(end);
                    if(end == n)
                    {
                        return true;
                    }
                }
            }
            
            visited[start] = true;
        }
        
        return false;
    }
};
