class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        vector<int> counter(26, 0);
        
        for(char ch : tasks)
        {
            counter[ch - 'A']++;
        }
        
        int fMax = *(max_element(counter.begin(), counter.end()));
        int nMax = 0;
        for(int f : counter)
        {
            if(f == fMax)
            {
                nMax++;
            }
        }
        
        return max((int) tasks.size(), n * (fMax - 1) + nMax);
    }
};
