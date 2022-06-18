class Solution {
private:
    void check(vector<int> &v,vector<vector<int>> &vp,int ssf,int ind,int n,int &ans,int k)
    {
        if(ind==n)
        {
            
            if(ssf==k)
            {
                int size=vp.size();
            
                int maxisum=INT_MIN;
                for(int i=0;i<size;i++)
                {
                    int sum=0;
                    for(int j=0;j<vp[i].size();j++)
                    {
                        sum+=vp[i][j];
                    }
                    maxisum=max(maxisum,sum);
                }
                
                ans=min(ans,maxisum);
                
            }
            
            return ;
        }
        
        for(int j=0;j<k;j++)
        {
      
            if(vp[j].size()==0)
            {
        
                vp[j].push_back(v[ind]);
                check(v,vp,ssf+1,ind+1,n,ans,k);
                vp[j].pop_back();
                break;
            }
            else
            {
                vp[j].push_back(v[ind]);
                check(v,vp,ssf,ind+1,n,ans,k);
                vp[j].pop_back();
            }
        }
        
        
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n=cookies.size();
        
        vector<vector<int>> vp(k);
        
        int ans=INT_MAX;
        
        check(cookies,vp,0,0,n,ans,k);
        
        return ans;
        
    }
};