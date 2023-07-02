class Solution {
public:
    
    void solve(vector<vector<int>> &vp,vector<int> &v,int ind,int &ans,int n,int p)
    {
        if(ind==vp.size())
        {
            int x=0;
            for(auto &it:v)
            {
                if(it!=0)
                   return;
            }
            ans=max(ans,p);
            
            return ;
        }
        
        v[vp[ind][0]]++;
        v[vp[ind][1]]--;
        solve(vp,v,ind+1,ans,n,p+1);
        v[vp[ind][0]]--;
        v[vp[ind][1]]++;
        solve(vp,v,ind+1,ans,n,p);
        
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> v(n,0);
        int ans=0;
        solve(requests,v,0,ans,n,0);
        
        return ans;
    }
};