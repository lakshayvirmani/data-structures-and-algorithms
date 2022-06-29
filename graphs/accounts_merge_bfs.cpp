class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> m;
        map<string, unordered_set<string>> e;
        
        for(auto account : accounts)
        {
            m[account[1]] = account[0];
            
            for(int i = 2; i < account.size(); i++)
            {
                e[account[i]].insert(account[1]);
                e[account[1]].insert(account[i]);
            }
        }
        
        string email = "";
        
        unordered_set<string> visited;
        vector<vector<string>> result;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            email = it->first;
            if(visited.find(email) == visited.end())
            {
                vector<string> cur;
                cur.push_back("");
                cur.push_back(email);
                
                queue<string> q;
                q.push(it->first);
                visited.insert(it->first);
                
                while(!q.empty())
                {
                    email = q.front();
                    q.pop();
                    
                    if(m.find(email) != m.end())
                    {
                        cur[0] = m[email];
                    }
                    
                    for(string neighbor : e[email])
                    {
                        if(visited.find(neighbor) == visited.end())
                        {
                            visited.insert(neighbor);
                            q.push(neighbor);
                            cur.push_back(neighbor);
                        }
                    }
                }
                
                result.push_back(cur);
            }
        }
        
        for(auto& mergedResult : result)
        {
            sort(mergedResult.begin() + 1, mergedResult.end());
        }
        
        return result;
    }
};
