class Solution {
    void process(string & s, int & i, char & curS)
    {
        int cnt = 0;
        while(i >= 0 && (s[i] == '#' || cnt > 0))
        {
            if(s[i] == '#')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            
            i--;
        }

        if(i >= 0)
        {
            curS = s[i];
            i--;
        }
        else
        {
            curS = NULL;
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        char curS, curT;
        
        curS = curT = NULL;
        
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        while(i >= 0 || j >= 0)
        {
            process(s, i, curS);
            process(t, j, curT);
            
            if(curS != curT)
            {
                return false;
            }
        }
        
        return i == -1 && j == -1;
    }
};
