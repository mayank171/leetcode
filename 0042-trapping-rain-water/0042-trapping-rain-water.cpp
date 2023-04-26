class Solution {
public:
    int trap(vector<int>& v) {
        
        int n=v.size();
        vector<int> prefix(n);
        prefix[0]=v[0];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(v[i],prefix[i-1]);
        }
        
        vector<int> suffix(n);
        suffix[n-1]=v[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(v[i],suffix[i+1]);
        }
        
        //reverse(suffix.begin(),suffix.end());
        
        for(auto &it:prefix)
            cout<<it<<" ";
        cout<<endl;
        
        for(auto &it:suffix)
            cout<<it<<" ";
        cout<<endl;
        
        
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(prefix[i],suffix[i])-v[i]);
        }
        
        return ans;
        
    }
};