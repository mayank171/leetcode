class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        
        int n=values.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0 || gap==1)
                    continue;
                else if(gap==2)
                {
                    dp[i][j]=values[i]*values[i+1]*values[j];
                }
                else
                {
                    int mini=1e9;
                    for(int k=i+1;k<j;k++)
                    {
                        int x=dp[i][k];
                        int y=dp[k][j];
                        int z=values[i]*values[k]*values[j];
                        cout<<x<<" "<<y<<" "<<z<<endl;
                        mini=min(mini,x+y+z);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        
        for(auto &it:dp)
        {
            for(auto &it1:it)
                cout<<it1<<" ";
            cout<<endl;
        }
        
        return dp[0][n-1];
        
    }
};