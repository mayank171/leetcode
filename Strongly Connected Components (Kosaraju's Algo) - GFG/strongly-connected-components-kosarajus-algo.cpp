// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    void topo(vector<int> adj[],stack<int> &stk,vector<int> &vis,int src)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
              topo(adj,stk,vis,it);
        }
        stk.push(src);
    }
    
    void dfs(int src,vector<int> &vis1,vector<int> adj1[])
    {
        vis1[src]=1;
        //temp.push_back(src);
        for(auto &it:adj1[src])
        {
            if(vis1[it]==0)
            {
                dfs(it,vis1,adj1);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> stk;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
              topo(adj,stk,vis,i);    
            }
        }
            
        
        vector<int> adj1[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                adj1[adj[i][j]].push_back(i);
            }
        }
        
        // for(int i=0;i<V;i++)
        // {
        //     for(int j=0;j<adj1[i].size();j++)
        //     {
        //         cout<<adj1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> vis1(V,0);
        
        //vector<vector<int>> ans;
        
        int ct=0;
        while(!stk.empty())
        {
            int x=stk.top();
            vector<int> temp;
            stk.pop();
            
            if(vis1[x]==0)
            {
                ct++;
               dfs(x,vis1,adj1);
              // ans.push_back(temp);
               
            }
               
        }
        
        return ct;
       // return ans.size();
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends