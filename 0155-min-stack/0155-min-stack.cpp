class MinStack {
   vector<int> stack;
    vector<int> minstack;
public:
    
    MinStack() {

    }
    
    void push(int val) {
       stack.push_back(val);
        if(minstack.empty()|| minstack.back()>val)
         minstack.push_back(val);
        else minstack.push_back(minstack.back());
    }
    
    void pop() {
        stack.pop_back();
        minstack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();
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