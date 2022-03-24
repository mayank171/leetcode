// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     for(int j=0;j<m;j++)
	   //     {
	   //         if(grid[i][j]==0)
	   //            grid[i][j]=1;
	   //         else
	   //            grid[i][j]=0;
	   //     }
	   // }
	    
	   // queue<pair<int,int>> q;
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     for(int j=0;j<m;j++)
	   //     {
	   //         if(grid[i][j]==0)
	   //         {
	   //             q.push({i,j});
	   //         }
	   //         else
	   //         {
	   //             grid[i][j]=-1;
	   //         }
	   //     }
	   // }
	    
	   // while(!q.empty())
	   // {
	   //     int x=q.front().first;
	   //     int y=q.front().second;
	   //     q.pop();
	        
	   //     int dx[4]={-1,0,1,0};
	   //     int dy[4]={0,1,0,-1};
	        
	   //     for(int i=0;i<4;i++)
	   //     {
	   //         int ind_x=dx[i]+x;
	   //         int ind_y=dy[i]+y;
	            
	   //         if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==-1)
	   //         {
	   //             grid[ind_x][ind_y]=grid[x][y]+1;
	   //             q.push({ind_x,ind_y});
	   //         }
	            
	   //     }
	        
	   // }
	    
	   // return grid;
	   
	   
	   
	   queue<pair<int,pair<int,int>>> q;
	   
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(grid[i][j]==0)
	           {
	               grid[i][j]=-1;
	               
	           }
	           else
	           {
	               grid[i][j]=0;
	               q.push({0,{i,j}});
	               //cout<<grid[i][j]<<" ";
	           }
	       }
	   }
	   
	   
	   
	   while(!q.empty())
	   {
	       int dis=q.front().first;
	       int x=q.front().second.first;
	       int y=q.front().second.second;
	       //grid[x][y]=0;
	       q.pop();
	    
	       
	       int dx[4]={-1,0,1,0};
	       int dy[4]={0,1,0,-1};
	       
	       for(int ind=0;ind<4;ind++)
	       {
	           int ind_x=dx[ind]+x;
	           int ind_y=dy[ind]+y;
	           
	           if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==-1)
	           {
	               //grid[x][y]=0;
	               grid[ind_x][ind_y]=dis+1;
	               q.push({dis+1,{ind_x,ind_y}});
	           }
	       }
	       
	   }
	   
	   return grid;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends