class Trie {
    bool isEndOfWord;
    Trie *map[26];
    
public:
    Trie() {
        isEndOfWord = false;
        for(int i=0; i<26; i++)
        {
            map[i] = NULL;
        }
    }
    
    void insert(string word) {
        auto tmp = this;
        
        for(char ch : word)
        {
            if(tmp->map[ch-'a'] == NULL)
            {
                tmp->map[ch-'a'] = new Trie();
            }
            
            tmp = tmp->map[ch-'a'];
        }
        
        tmp->isEndOfWord = true;
    }
    
    Trie* searchPrefix(string word) {
        auto tmp = this;
        
        for(char ch : word)
        {
            if(tmp->map[ch-'a'] == NULL)
            {
                return NULL;
            }
            
            tmp = tmp->map[ch-'a'];
        }
        
        return tmp;
    }
    
    bool search(string word) {
        auto tmp = searchPrefix(word);
        return tmp != NULL && tmp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        auto tmp = searchPrefix(prefix);
        return tmp != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
