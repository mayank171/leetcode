// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    void check(vector<int> adj[],vector<int> &vis,int src)
    {
        vis[src]=1;
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                check(adj,vis,it);
            }
        }
    }
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        //int ct=0;
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')
                {
                    mp.insert({{i,j},ct});
                    ct++;
                }
            }
        }
        
        vector<int> adj[ct];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')
                {
                    int dx[4]={-1,0,1,0};
                    int dy[4]={0,1,0,-1};
                    auto it1=mp.find({i,j});
                    
                    
                    for(int ind=0;ind<4;ind++)
                    {
                        int x_ind=i+dx[ind];
                        int y_ind=j+dy[ind];
                        
                        if(x_ind>=0 && x_ind<n && y_ind>=0 && y_ind<m && grid[x_ind][y_ind]=='X')
                        {
                            auto it=mp.find({x_ind,y_ind});
                            adj[it1->second].push_back(it->second);
                        }
                    }
                }
                
            }
        }
        
        // for(int i=0;i<ct;i++)
        // {
        //     cout<<i<<"->";
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> vis(ct,0);
        
        int ans=0;
        for(int i=0;i<ct;i++)
        {
            int ct=0;
            if(vis[i]==0)
            {
                ans++;
                check(adj,vis,i);
              
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends