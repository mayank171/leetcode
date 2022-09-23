class MinStack {
    
    long mini;
    stack<pair<long,long>> stk;
    
public:
    MinStack() {
        mini=LONG_MAX;
    }
    
    void push(int val) {
        //cout<<"vdvdvv"<<val<<endl;
        if(mini>val || stk.empty())
        {
            mini=val;
            stk.push({2*1ll*val+1,val});
        }
        else
        {
            long b=stk.top().first;
            stk.push({b,val});
        }
        
    }
    
    void pop() {
       // cout<<"popopov"<<stk.top().second<<endl;
        if(stk.size()==1)
        {
            stk.pop();
            return ;
        }
        stk.pop();
        mini=(stk.top().first-1)/2;            
        
    }
    
    int top() {
        
        //cout<<"topdvv"<<stk.top().second<<endl;
        return stk.top().second;
    }
    
    int getMin() {
      //  cout<<"minvdvv"<<mini<<endl;
        int x=mini;
        return x;
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