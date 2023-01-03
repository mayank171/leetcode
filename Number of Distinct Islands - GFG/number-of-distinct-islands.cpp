//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        //         U R D L 
        
        
        set<string> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i*m+j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    string s="X";
                    
                    while(!q.empty())
                    {
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+r;
                            int ind_y=dy[ind]+c;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                            {
                                if(ind==0)
                                {
                                    s+='U';
                                    vis[ind_x*m+ind_y]=1;
                                    q.push({ind_x,ind_y});
                                }
                                else if(ind==1)
                                {
                                    s+='R';
                                    vis[ind_x*m+ind_y]=1;
                                    q.push({ind_x,ind_y});
                                }
                                else if(ind==2)
                                {
                                    s+='D';
                                    vis[ind_x*m+ind_y]=1;
                                    q.push({ind_x,ind_y});
                                }
                                else
                                {
                                    s+='L';
                                    vis[ind_x*m+ind_y]=1;
                                    q.push({ind_x,ind_y});
                                }
                            }
                            else 
                            {
                                s+='X';
                            }
                        }
                    }
                    
                    st.insert(s);
                }
            }
        }
        
        // cout<<st.size()<<endl;
        
      return st.size();  
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends