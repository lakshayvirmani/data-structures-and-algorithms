class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        
        for(int n : asteroids)
        {
            if(n > 0)
            {
                result.push_back(n);
            }
            else
            {
                n = abs(n);
                bool exploded = false;
                
                while(!result.empty() && result.back() > 0)
                {
                    if(n > result.back())
                    {
                        result.pop_back();
                    }
                    else if(n == result.back())
                    {
                        result.pop_back();
                        exploded = true;
                        break;
                    }
                    else
                    {
                        exploded = true;
                        break;
                    }
                }
                
                if(!exploded)
                {
                    result.push_back(-n);
                }
            }
        }
        
        return result;
    }
};
