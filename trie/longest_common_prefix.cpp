class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<vector<bool>> t;
        
        for(int i=0; i<strs.size(); i++)
        {
            string cur = strs[i];
            for(int j=0; j<=cur.size(); j++)
            {
                if(t.size() == j)
                {
                    t.push_back(vector<bool>(27, false));
                }
                
                if(j < cur.size())
                {
                    t[j][cur[j]-'a'] = true;
                }
                else
                {
                   t[j][26] = true; 
                }
            }
        }
        
        string result = "";
        bool flag = true;
        for(int i=0; i<t.size() && flag == true; i++)
        {
            int cnt = 0;
            for(int j=0; j<=26; j++)
            {
                if(t[i][j] == true)
                {
                    if(cnt == 1)
                    {
                        result.pop_back();
                        flag = false;
                        break;
                    }
                    else
                    {
                        cnt++;
                        if(j != 26)
                        {
                            result.push_back('a'+j);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
