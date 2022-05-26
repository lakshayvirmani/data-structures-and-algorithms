class MinStack {
    stack<int> s;
    stack<pair<int, int>> minS;
public:
    MinStack() {
        while(!s.empty())
        {
            s.pop();
        }
        while(!minS.empty())
        {
            minS.pop();
        }
    }
    
    void push(int val) {
        s.push(val);
        
        if(minS.empty() || s.top() < minS.top().first)
        {
            minS.push({val,1});
        }
        else if(s.top() == minS.top().first)
        {
            pair<int,int> cur = minS.top();
            minS.pop();
            cur.second++;
            minS.push(cur);
        }
    }
    
    void pop() {
        if(minS.top().first == s.top())
        {
            pair<int,int> cur = minS.top();
            minS.pop();
            if(cur.second > 1)
            {
                cur.second--;
                minS.push(cur);
            }
        }
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
