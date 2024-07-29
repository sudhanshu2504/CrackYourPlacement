class MyQueue {
public:
    stack<int> main;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!main.empty()){
            int a = main.top();
            main.pop();
            temp.push(a);
        }
        int ans = temp.top();
        temp.pop();
        while(!temp.empty()){
            int a = temp.top();
            temp.pop();
            main.push(a);
        }
        return ans;
    }
    
    int peek() {
        stack<int> temp;
        while(!main.empty()){
            int a = main.top();
            main.pop();
            temp.push(a);
        }
        int ans = temp.top();
        while(!temp.empty()){
            int a = temp.top();
            temp.pop();
            main.push(a);
        }
        return ans;
        
    }
    
    bool empty() {
        return (main.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */