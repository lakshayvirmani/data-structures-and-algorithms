class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string result = "";
        
        if(m.find(key) != m.end())
        {
            auto it = m[key].upper_bound(timestamp);
            it--;
            
            if(it->first <= timestamp)
            {
                result = it->second;
            }
        }
        
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
