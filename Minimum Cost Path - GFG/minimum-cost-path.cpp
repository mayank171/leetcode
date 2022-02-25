// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        int mini=INT_MAX;
        
        vector<int> vis(n*m,0);
        int sum=grid[0][0];
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({grid[0][0],{0,0}});
        vis[0]=1;
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
            pq.pop();
            
            if(x==n-1 && y==m-1)
            {
                mini=min(mini,distance);
            }
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    pq.push({grid[ind_x][ind_y]+distance,{ind_x,ind_y}});
                }
            }
            
        }
        
        return mini;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends