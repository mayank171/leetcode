//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
              
            }
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ans=-1;
        vector<int> vis(n*m,0);
        
        while(!q.empty())
        {
            int t=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
           // cout<<i<<" "<<j<<" "<<t<<" "<<ct<<endl;
            q.pop();
            
            ans=max(ans,t);
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==1)
                {
                    ct--;
                    vis[ind_x*m+ind_y]=1;
                    grid[ind_x][ind_y]=2;
                    q.push({t+1,{ind_x,ind_y}});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        
        return ans;
        
    }
};



















//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends