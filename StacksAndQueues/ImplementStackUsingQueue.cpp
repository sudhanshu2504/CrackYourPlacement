class MyStack {
public:
        queue<int> ds;
    MyStack() {
    }
    
    void push(int x) {
        int s = ds.size();
        ds.push(x);
        while(s--){
            ds.push(top());
            ds.pop();
        }
    }
    
    int pop() {
        int a = top();
        ds.pop();
        return a;
    }
    
    int top() {
        int t = ds.front();
        return t;
    }
    
    bool empty() {
        if(ds.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */