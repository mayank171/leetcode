class MyStack {
public:
    
    // queue<int> q1;
    // queue<int> q2;
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
       // q1.push(x);
        int size=q.size();
        
        q.push(x);
        
        while(size--)
        {
            int x=q.front();
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        
//         while(q1.size()>1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         int x=q1.front();
//         q1.pop();
        
//         while(!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }
        
//         return x;
        
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        
//         while(q1.size()>1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         int x=q1.front();
//         q1.pop();
//         q2.push(x);
        
//         while(!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }
        
//         return x;
        
        return q.front();
    }
    
    bool empty() {
        
//         if(q1.size()==0)
//             return true;
//         return false;
        
        if(q.size()==0)
            return true;
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