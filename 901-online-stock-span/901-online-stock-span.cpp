class StockSpanner {
    
    vector<int> v;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        
       int ans=-1;    
    
       if(v.empty())
       {
           v.push_back(price);
           ans=1;
       }
       else
       {
           int size=v.size();
           
           
           for(int i=size-1;i>=0;i--)
           {
               if(v[i]>price)
               {
                   ans=size-i;
                   break;
               }
           }       
           
           
           if(ans==-1)
           {
               ans=size+1;
           }
           
           v.push_back(price);
           
           
       }
        
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */