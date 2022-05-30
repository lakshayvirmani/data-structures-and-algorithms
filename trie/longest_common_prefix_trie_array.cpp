#import<algorithm>
class Trie
{
    bool isEnd;
    Trie *map[26];
    unsigned long minLenSoFar;
    
public:
    Trie()
    {
        isEnd = false;
        
        for(int i=0; i<26; i++)
        {
            map[i] = NULL;
        }
        
        minLenSoFar = INT_MAX;
    }
    
    void insert(string word)
    {
        auto tmp = this;
        
        for(int i=0; i<word.size() && i<minLenSoFar; i++)
        {
            char ch = word[i];
            
            if(tmp->map[ch-'a'] == NULL)
            {
                tmp->map[ch-'a'] = new Trie();
            }
            
            tmp = tmp->map[ch-'a'];
        }
        
        tmp->isEnd = true;
        minLenSoFar = min(minLenSoFar, word.size());
    }
    
    char getNextPrefixChar(Trie* tmp)
    {
        char ch = '\0';
        
        if(tmp->isEnd == false)
        {
            for(int i=0; i<26; i++)
            {
                if(tmp->map[i] != NULL)
                {
                    if(ch == '\0')
                    {
                        ch = 'a' + i;
                    }
                    else
                    {
                        ch = '\0';
                        break;
                    }
                }
            }
        }
        
        return ch;
    }
    
    string findLCP()
    {
        string result = "";
        auto tmp = this;
        
        do
        {
            char ch = getNextPrefixChar(tmp);
            
            if(ch != '\0')
            {
                result += ch;
                tmp = tmp->map[ch-'a'];
            }
            else
            {
                return result;
            }
        }
        while(tmp->isEnd != true);
        
        return result;
    }
};

class Solution {
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        for(string str : strs)
        {
            trie->insert(str);
        }
        return trie->findLCP();
    }
};
