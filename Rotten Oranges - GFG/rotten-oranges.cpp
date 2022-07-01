// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        int ct_1=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ct_1++;
                else if(grid[i][j]==2)
                    q.push({0,{i,j}});
            }
        }
        
        int t=0;
        int ctr_1=0;
        
        vector<int> vis(n*m,0);
        
        while(!q.empty())
        {
            int timer=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            t=timer;
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=x+dx[ind];
                int ind_y=y+dy[ind];
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({timer+1,{ind_x,ind_y}});
                    ctr_1++;
                }
            }
        }
        
        if(ctr_1!=ct_1)
           return -1;
        
        return t;
        
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends