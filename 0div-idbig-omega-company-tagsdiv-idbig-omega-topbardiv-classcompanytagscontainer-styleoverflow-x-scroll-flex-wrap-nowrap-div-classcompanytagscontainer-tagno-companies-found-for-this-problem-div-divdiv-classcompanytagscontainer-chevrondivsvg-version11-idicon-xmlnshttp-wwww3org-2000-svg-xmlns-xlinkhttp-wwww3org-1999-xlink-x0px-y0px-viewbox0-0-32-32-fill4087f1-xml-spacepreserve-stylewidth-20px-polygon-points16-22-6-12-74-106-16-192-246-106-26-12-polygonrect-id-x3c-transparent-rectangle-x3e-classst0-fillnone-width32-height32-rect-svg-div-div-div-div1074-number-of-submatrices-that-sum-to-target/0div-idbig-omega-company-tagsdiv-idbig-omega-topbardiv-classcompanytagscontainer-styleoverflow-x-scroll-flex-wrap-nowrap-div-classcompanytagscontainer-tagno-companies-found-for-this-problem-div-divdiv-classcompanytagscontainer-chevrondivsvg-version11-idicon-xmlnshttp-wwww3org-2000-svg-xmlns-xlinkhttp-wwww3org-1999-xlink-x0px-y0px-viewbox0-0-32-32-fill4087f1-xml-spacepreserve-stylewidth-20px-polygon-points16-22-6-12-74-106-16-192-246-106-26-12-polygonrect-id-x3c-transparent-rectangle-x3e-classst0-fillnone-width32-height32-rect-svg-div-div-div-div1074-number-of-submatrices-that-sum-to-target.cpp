class Solution {
public:
    
    int solve(vector<int> &v,int target)
    {
        map<int,int> mp;
        mp[0]=1;
        
        int ans=0;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
      //      cout<<sum<<" ";
            if(mp[sum-target]!=0)
            {
                ans+=mp[sum-target];
            }
            mp[sum]++;
        }
        // cout<<endl;
        // cout<<ans<<endl;
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ans=0;
        for(int i1=0;i1<n;i1++)
        {
            vector<int> v(m,0);
            for(int i2=i1;i2<n;i2++)
            {
                for(int j=0;j<m;j++)
                {
                    v[j]+=matrix[i2][j];
                }
                
                ans+=solve(v,target);
            }
        }
        
        return ans;
    }
};