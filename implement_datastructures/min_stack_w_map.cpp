class MinStack {
public:
    stack<int> s;
    map<int,int> eleCount;
    
    MinStack() {
        while(!s.empty())
        {
            s.pop();
        }
        
        eleCount.clear();
    }
    
    void push(int val) {
        s.push(val);
        eleCount[val]++;
    }
    
    void pop() {
        int val = s.top();
        s.pop();
        
        if(eleCount[val] == 1)
        {
            eleCount.erase(val);
        }
        else
        {
            eleCount[val]--;
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return eleCount.begin()->first;
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
