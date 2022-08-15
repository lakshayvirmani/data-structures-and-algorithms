struct TrieNode
{
    TrieNode* map[26];
    bool isEnd;
    
    TrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            map[i] = NULL;
        }
        
        isEnd = false;
    }
};

class Trie
{
    TrieNode* root;
    
public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void add(string word)
    {
        TrieNode* cur = root;
        
        for(char ch : word)
        {
            if(cur->map[ch-'a'] == NULL)
            {
                cur->map[ch-'a'] = new TrieNode();
            }
            
            cur = cur->map[ch-'a'];
        }
        
        cur->isEnd = true;
    }
    
    bool searchRec(string word, TrieNode* cur)
    {   
        for(int i = 0; i < word.size(); i++)
        {
            const char& ch = word[i];
            
            if(ch != '.')
            {
                if(cur->map[ch - 'a'] == NULL)
                {
                    return false;
                }
                cur = cur->map[ch - 'a'];
            }
            else
            {
                for(int j = 0; j < 26; j++)
                {
                    if(cur->map[j] != NULL && searchRec(word.substr(i + 1), cur->map[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        
        return cur->isEnd;
    }
    
    bool search(string word)
    {
        return searchRec(word, root);
    }
};

class WordDictionary {
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->add(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
