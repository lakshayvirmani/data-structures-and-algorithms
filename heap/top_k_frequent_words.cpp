class Solution {
    struct comparator
    {
        bool operator()(const pair<int, string>& left, const pair<int, string>& right)
        {
            return (left.first > right.first) || (left.first == right.first && left.second < right.second);
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreqMap;
        
        for(const string& word : words)
        {
            wordFreqMap[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        
        for(auto it = wordFreqMap.begin(); it != wordFreqMap.end(); it++)
        {
            if(pq.size() < k)
            {
                pq.push({it->second, it->first});
            }
            else
            {
                const pair<int, string>& top = pq.top();
                if(it->second > top.first || (it->second == top.first && it->first < top.second))
                {
                    pq.pop();
                    pq.push({it->second, it->first});
                }
            }
        }
        
        vector<string> result(k);
        for(int i = k - 1; i >= 0; i--)
        {
            result[i] = pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};
