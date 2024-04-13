class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            int ct=-1;
            for(int j=m-1;j>=0;j--)
            {
                if(matrix[i][j]!='0')
                {
                    if(ct==-1)
                       ct=j;
                    dp[i][j]=ct;
                }
                else
                {
                    ct=-1;
                }
            }
        }
        
        for(auto &it:dp)
        {
            for(auto &it1:it)
                cout<<it1<<" ";
            cout<<endl;
        }
        cout<<endl;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                int b=1e9;
                for(int k=i;k>=0;k--)
                {
                    if(matrix[k][j]=='1')
                    {
                        b=min(b,dp[k][j]-j+1);
                        ans=max(ans,(i-k+1)*b);
                    }
                    else
                        break;
                }
            }
        }
        
        
        return ans;
    }
};