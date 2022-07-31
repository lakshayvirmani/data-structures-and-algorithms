class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        string key;
        for(int i = 0; i < strs.size(); i++)
        {
            key = strs[i];
            sort(key.begin(), key.end());
            map[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto it = map.begin(); it != map.end(); it++)
        {
            result.push_back(it->second);
        }
        
        return result;
    }
};
