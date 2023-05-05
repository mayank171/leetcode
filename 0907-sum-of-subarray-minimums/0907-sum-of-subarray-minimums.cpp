class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int> rightMin(n,n);
        vector<int> leftMin(n,-1);
        
        int ans=0;
        int mod=1e9+7;
        
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[stk.top()]>arr[i])
            {
                int ind=stk.top();
                stk.pop();
                rightMin[ind]=i;
            }
            stk.push(i);
        }
        
        while(!stk.empty())
            stk.pop();
        
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])
            {
                int ind=stk.top();
                stk.pop();
                leftMin[ind]=i;
            }
            stk.push(i);
        }
        
        
        for(int i=0;i<n;i++)
        {
            int left=(i-leftMin[i]);
            int right=(rightMin[i]-i);
            int x=(left*1ll*right)%mod;
            x=(x*1ll*arr[i])%mod;
            ans=(ans+x)%mod;
        }
        
        return ans;
    }
};