//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &v){
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> ans(n,vector<int> (m,-1));
        vector<int> vis(n*m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='W')
                {
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                    vis[i*m+j]=1;
                }
            }
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && v[ind_x][ind_y]=='H')
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({dist+1,{ind_x,ind_y}});
                    ans[ind_x][ind_y]=2*(dist+1);
                }
                else if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && (v[ind_x][ind_y]=='.'))
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({dist+1,{ind_x,ind_y}});
                    //ans[ind_x][ind_y]=2*(dist+1);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='N' || v[i][j]=='.')
                   ans[i][j]=0;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends