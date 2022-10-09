class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int> nse(n);
        
        stack<int> stk;
        
        nse[n-1]=n;
        
        stk.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!stk.empty() && arr[i]<arr[stk.top()])
            {
                stk.pop();
            }
            
            if(stk.empty())
            {
                nse[i]=n;
            }
            else
            {
                nse[i]=stk.top();
            }
            stk.push(i);
        }
        
//         for(auto &it:nse)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        vector<int> pse(n);
        
        stack<int> stk1;
        
        pse[0]=-1;
        
        stk1.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!stk1.empty() && arr[i]<=arr[stk1.top()])
            {
                stk1.pop();
            }
            
            if(stk1.empty())
            {
                pse[i]=-1;
            }
            else
            {
                pse[i]=stk1.top();
            }
            stk1.push(i);
        }
        
//         for(auto &it:pse)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int width=abs(nse[i]-pse[i])-1;
            ans=max(ans,width*arr[i]);
        }
        
        return ans;
    }
};