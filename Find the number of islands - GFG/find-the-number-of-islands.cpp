// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    void dfs(vector<vector<char>>& grid, vector<int> &vis,int r,int c,int n,int m)
    {
        vis[r*m+c]=1;
        
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        
        for(int ind=0;ind<8;ind++)
        {
            int ind_x=dx[ind]+r;
            int ind_y=dy[ind]+c;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]=='1' && vis[ind_x*m+ind_y]==0)
            {
                dfs(grid,vis,ind_x,ind_y,n,m);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(vis[i*m+j]==0)
                    {
                        ct++;
                      // cout<<"cndicn"<<endl;
                        dfs(grid,vis,i,j,n,m);
                    }
                }
            }
        }
        
        return ct;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends