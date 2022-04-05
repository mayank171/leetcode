// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if(X==0)
	      return 0;
	    
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    
	    
	   // vector<int> adj1[V];
	   // vector<int> vis(V,0);
	    
	   // for(int i=0;i<V;i++)
	   // {
	   //     vis[i]=1;
	   //     for(int j=0;j<adj[i].size();j++)
	   //     {
	   //        if(!vis[j])
	   //        {
	   //            adj1[i].push_back(adj[i][j]);
	   //            vis[j]=1;
	   //        }
	   //     }
	   //     cout<<endl;
	   // }
	    
	   // for(int i=0;i<V;i++)
	   // {
	   //     for(int j=0;j<adj1[i].size();j++)
	   //     {
	   //        cout<<adj1[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	    
	    
	    vector<int> vis(V,0);
	    vis[0]=1;
	    
	    while(!q.empty())
	    {
	        
	        int front=q.front().first;
	        int level=q.front().second;
	        if(front==X)
	               return level;
	        q.pop();
	        
	        for(auto &it:adj[front])
	        {
	           if(vis[it]==0)
	           {
	              q.push({it,level+1});
	              vis[it]=1;
	           }
	            
	        }
	        
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends