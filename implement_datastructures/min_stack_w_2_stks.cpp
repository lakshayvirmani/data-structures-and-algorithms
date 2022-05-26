class MinStack {
    stack<int> s;
    stack<int> minS;
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
        
        if(minS.empty() || s.top() <= minS.top())
        {
            minS.push(val);
        }
    }
    
    void pop() {
        if(minS.top() == s.top())
        {
            minS.pop();
        }
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
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
