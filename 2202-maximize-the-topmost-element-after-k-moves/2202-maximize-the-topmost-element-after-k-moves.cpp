class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        deque<int> stk;
        int size=nums.size();
        
        for(int i=size-1;i>=0;i--)
        {
            stk.push_front(nums[i]);
        }
        
        if(k==0)
            return stk.front();
        
        int maxi=*max_element(nums.begin(),nums.end());
        
       // int maxi2=*max_element(nums.begin(),nums.begin()+k);
        
        cout<<maxi<<endl;
        
        int ans=0;
        if(k>size)
        {
            if(size==1 && k&1)
                return -1;
            else
                return maxi;
        }
        else
        {
            
            priority_queue<int> pq;
            
            while(k)
            {
                 if(k==1)
                 {
                     
                     if(pq.empty())
                     {
                         if(stk.size()>1)
                         {
                             int a=stk.front();
                             stk.pop_front();
                             // if(stk.front()>a)
                             // {
                                 ans=stk.front();
                                 break;
//                              }
//                              else
//                              {
                                 
//                              }
                         }
                         ans=-1;
                         break;
                     }
                     else
                     {
                         int x=pq.top();
                         ans=x;
                         
                         if(stk.size()>1)
                         {
                             int a=stk.front();
                             stk.pop_front();
                             if(stk.front()>ans)
                             {
                                 ans=stk.front();
                             }
                             else
                             {
                                 stk.push_front(a);
                                 
                             }
                         }
                         
                         break;
                        
                     }
                 }
                 // else if(stk.empty())
                 // {
                 //     stk.push_front(pq.top());
                 //     pq.pop();
                 // }
                 else
                 {
                     int x=stk.front();
                     stk.pop_front();
                     pq.push(x);
                 }
                k--;
            }
        }
        return ans;
        
    }
};