struct LinkedListNode {
    int key, val;
    LinkedListNode *prev, *next;
};

class LRUCache {
    unordered_map<int, LinkedListNode*> map;
    LinkedListNode *head, *tail;
    int maxCapacity;
    
public:
    LRUCache(int capacity) {
        head = new LinkedListNode();
        tail = new LinkedListNode();
        head->next = tail;
        tail->prev = head;
        maxCapacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
        {
            return -1;
        }
        
        LinkedListNode* cur = map[key];
        moveToFront(cur);
        
        return cur->val;
    }
    
    void put(int key, int value) {
        LinkedListNode* cur;
        
        if(map.find(key) == map.end())
        {
            if(map.size() == maxCapacity)
            {
                deleteLRUNode();
            }
            
            cur = new LinkedListNode();
            cur->key = key;
            cur->val = value;
            
            map[key] = cur;
        }
        else
        {
            cur = map[key];
            cur->val = value;
        }
        
        moveToFront(cur);
    }
    
private:
    void moveToFront(LinkedListNode* cur)
    {
        LinkedListNode* prev = cur->prev;
        LinkedListNode* next = cur->next;
        
        if(prev != NULL)
        {
            prev->next = next;
        }
        
        if(next != NULL)
        {
            next->prev = prev;
        }
        
        cur->next = head->next;
        cur->prev = head;
        
        head->next->prev = cur;
        head->next = cur;
    }
    
    void deleteLRUNode()
    {
        LinkedListNode* delNode = tail->prev;
        delNode->prev->next = tail;
        tail->prev = delNode->prev;
        
        map.erase(delNode->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
