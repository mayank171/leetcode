class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        stack<int> stk1;
        stack<int> stk2;
        
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        
        for(int i=0;i<n;i++)
        {
            pref[i]=i;
            suff[i]=n-i-1;
        }
        
        
        for(int i=0;i<n;i++)
        {
            while(!stk1.empty() && arr[stk1.top()]>arr[i])
            {
                suff[stk1.top()]=i-stk1.top()-1;
                stk1.pop();
            }
            
            stk1.push(i);
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stk2.empty() && arr[stk2.top()]>=arr[i])
            {
                pref[stk2.top()]=stk2.top()-i-1;
                stk2.pop();
            }
            
            stk2.push(i);
        }
        
        int m=1e9+7;
        
        
//         for(auto &it:pref)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         for(auto &it:suff)
//         {
//             cout<<it<<" ";
//         }
        
       // return 0;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int x=(arr[i]*1LL*(pref[i]+1)*1LL*(suff[i]+1))%m;
            ans=(ans+x)%m;
        }
        
        return ans;
    }
};