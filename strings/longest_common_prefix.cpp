class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        bool flag = true;
        
        if(strs.size() == 1)
        {
            result = strs[0];
            return result;
        }
        
        while(flag)
        {
            for(int i=1; i<strs.size(); i++)
            {
                if(result.size() >= strs[i].size() || result.size() >= strs[i-1].size() || strs[i][result.size()] != strs[i-1][result.size()])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                result.push_back(strs[0][result.size()]);
            }
        }
        
        return result;
    }
};
