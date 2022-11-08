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
    
    int dfs(vector<vector<char>> &mat,vector<int> &vis,int row,int col,int n,int m,int pr,int pc)
    {
       
        vis[row*m+col]=1;
        
        for(int ind=0;ind<4;ind++)
        {
            int ind_x=dx[ind]+row;
            int ind_y=dy[ind]+col;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && mat[ind_x][ind_y]=='O' && vis[ind_x*m+ind_y]==0)
            {
                dfs(mat,vis,ind_x,ind_y,n,m,pr,pc);
            }
        }
        
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        
        set<pair<int,int>> st1;
        
        set<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==m-1 || i==n-1 || j==0) && mat[i][j]=='O')
                {
                    st1.insert({i,j});
                }
                else if(mat[i][j]=='O')
                {
                    st.insert({i,j});    
                }
                
            }
        }
        
        
        vector<int> vis(n*m,0);
        
        for(auto &it:st1)
        {
            int i=it.first;
            int j=it.second;
           // cout<<i<<" "<<j<<endl;
            dfs(mat,vis,i,j,n,m,-1,-1);
        }
        
        for(auto &it:st)
        {
            if(vis[it.first*m+it.second]==0)
            {
                mat[it.first][it.second]='X';
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