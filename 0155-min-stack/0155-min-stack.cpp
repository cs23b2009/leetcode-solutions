class MinStack {
public:
    stack <pair <int,int>> st;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else{
            pair <int,int> p = st.top();
            if(p.second>val) st.push({val,val});
            else st.push({val,p.second});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        pair <int,int> p = st.top();
        return p.first;
    }
    
    int getMin() {
        pair <int,int> p = st.top();
        return p.second;
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