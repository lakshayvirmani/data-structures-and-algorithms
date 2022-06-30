class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> e;
        
        for(auto account : accounts)
        {
            for(int i = 2; i < account.size(); i++)
            {
                e[account[i]].insert(account[1]);
                e[account[1]].insert(account[i]);
            }
        }
        
        string name = "";
        string email = "";
        
        unordered_set<string> visited;
        vector<vector<string>> result;
        for(auto& account : accounts)
        {
            name = account[0];
            email = account[1];
            if(visited.find(email) == visited.end())
            {
                vector<string> cur;
                cur.push_back(name);
                cur.push_back(email);
                
                queue<string> q;
                q.push(email);
                visited.insert(email);
                
                while(!q.empty())
                {
                    email = q.front();
                    q.pop();
                    
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
                
                sort(cur.begin() + 1, cur.end());
                
                result.push_back(cur);
            }
        }
        
        return result;
    }
};
