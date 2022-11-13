//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    void dfs(vector<vector<char>> &mat,vector<int> &vis,int r,int c,int n,int m)
    {
        vis[r*m+c]=1;
        for(int i=0;i<4;i++)
        {
            int ind_x=dx[i]+r;
            int ind_y=dy[i]+c;
            
            if(ind_x>=0 && ind_x<n && ind_x>=0 && ind_y<m && mat[ind_x][ind_y]=='O' && vis[ind_x*m+ind_y]==0)
            {
                dfs(mat,vis,ind_x,ind_y,n,m);
            }
        }
        
    }
  

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<int> vis(n*m,0);
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O' && ( i==0 || i==n-1 || j==0 || j==m-1))
                {
                    v.push_back({i,j});
                }
            }
        }
        
        int size=v.size();
        
        for(int i=0;i<size;i++)
        {
            int r=v[i].first;
            int c=v[i].second;
            
            dfs(mat,vis,r,c,n,m);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O' && vis[i*m+j]==0)
                {
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends