class Trie {
    bool isEndOfWord;
    unordered_map<char, Trie*> map;
    
public:
    Trie() {
        isEndOfWord = false;
    }
    
    void insert(string word) {
        auto tmp = this;
        
        for(char ch : word)
        {
            if(tmp->map.find(ch) == tmp->map.end())
            {
                tmp->map[ch] = new Trie();
            }
            
            tmp = tmp->map[ch];
        }
        
        tmp->isEndOfWord = true;
    }
    
    bool search(string word) {
        auto tmp = this;
        
        for(char ch : word)
        {
            if(tmp->map.find(ch) == tmp->map.end())
            {
                return false;
            }
            
            tmp = tmp->map[ch];
        }
        
        return tmp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        auto tmp = this;
        
        for(char ch : prefix)
        {
            if(tmp->map.find(ch) == tmp->map.end())
            {
                return false;
            }
            
            tmp = tmp->map[ch];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
