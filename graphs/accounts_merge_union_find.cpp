class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        map<string, int> emailToIdxMap;
        vector<int> par (n);
        
        string name = "";
        string email = "";
        
        for(int i = 0; i < n; i++)
        {
            par[i] = i;
            name = accounts[0][0];
            for(int j = 1; j < accounts[i].size(); j++)
            {
                email = accounts[i][j];
                
                if(emailToIdxMap.find(email) == emailToIdxMap.end())
                {
                    emailToIdxMap[email] = i;
                }
                else
                {
                    merge(i, emailToIdxMap[email], par);
                }
            }
        }
        
        unordered_map<int, vector<string>> result;
        for(auto it = emailToIdxMap.begin(); it != emailToIdxMap.end(); it++)
        {
            int idx = find(it->second, par);
            
            if(result[idx].size() == 0)
            {
                result[idx].push_back(accounts[idx][0]);
            }
            
            result[idx].push_back(it->first);
        }
        
        vector<vector<string>> finalResult;
        for(auto it = result.begin(); it != result.end(); it++)
        {
            finalResult.push_back(it->second);
        }
        
        return finalResult;
    }
private:
    void merge(int i, int j, vector<int>& par)
    {
        i = find(i, par);
        j = find(j, par);
        
        par[i] = j;
    }
    
    int find(int i, vector<int>& par)
    {
        if(par[i] != i)
        {
            par[i] = find(par[i], par);
        }
        return par[i];
    }
};
