class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        
        
        int n=pref.size();
        
        if(n==1)
            return pref;
        
        vector<int> ans(n);
        ans[0]=pref[0];
        
        int prev=ans[0];
        
        for(int i=1;i<n;i++)
        {
            if(pref[i]==0)
            {
                ans[i]=pref[i-1];
            }
            else if(pref[i-1]==0)
            {
                ans[i]=pref[i];
            }
            else
            {
                ans[i]=pref[i-1]^pref[i];
                prev=ans[i];
            }
            
            //cout<<prev<<endl;
        }
        
        ans[n-1]=pref[n-1]^pref[n-2];
        
        return ans;
    }
};