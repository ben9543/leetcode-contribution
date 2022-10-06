class MinStack {
public:
    stack<int> s;
    stack<int> min_s;
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty())
            min_s.push(val);
        else
            min_s.push(min(min_s.top(), val));
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
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