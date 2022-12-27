//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        
        
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{k,0},{0,0}});
        
        int ans=1e8;
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        vector<vector<vector<int>>> vis(n,vector<vector<int>> (m,vector<int> (k+1,0)));
        vis[0][0][k]=1;
        
        
        while(!q.empty())
        {
            int ct=q.front().first.first;
            int moves=q.front().first.second;
            int i=q.front().second.first;
            int j=q.front().second.second;
            //cout<<i<<" "<<j<<endl;
            q.pop();
            
            if(i==n-1 && j==m-1)
            {
                ans=moves;
                break;
            }
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m)
                {
                    if(mat[ind_x][ind_y]==1 && ct>0  && vis[ind_x][ind_y][ct-1]==0)
                    {
                        vis[ind_x][ind_y][ct-1]=1;
                        q.push({{ct-1,moves+1},{ind_x,ind_y}});
                    }
                    else if(mat[ind_x][ind_y]==0 && vis[ind_x][ind_y][ct]==0)
                    {
                        vis[ind_x][ind_y][ct]=1;
                        q.push({{ct,moves+1},{ind_x,ind_y}});
                    }
                }
            }
            
        }
        
        if(ans==1e8)
           return -1;
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends