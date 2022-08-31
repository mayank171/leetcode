class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> last(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            int lt=m;
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                {
                    lt=j;
                }
                else
                {
                    last[i][j]=lt;
                }
            }
        }
        
        for(auto &it:last)
        {
            for(auto &it1:it)
            {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    int x=last[i][j]-j;
                    ct+=x;
                    int mini=x;
                    
                    for(int k=i+1;k<n;k++)
                    {
                        if(mat[k][j]==0)
                            break;
                        mini=min(mini,last[k][j]-j);
                        ct+=mini;
                    }
                    
                }
            }
            ans+=ct;
        }
        
        return ans;
        
    }
};