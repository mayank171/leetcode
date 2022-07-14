// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    
    void dfs(vector<int> adj[],int V,vector<int> &disc,vector<int> &low,vector<int> &parent,set<pair<int,int>> &st,int src)
    {
        static int t=0;
        disc[src]=low[src]=t;
        t++;
        
        for(auto &it:adj[src])
        {
            if(disc[it]==0)
            {
                parent[it]=src;
                dfs(adj,V,disc,low,parent,st,it);
                low[src]=min(low[src],low[it]);
                if(low[it]>disc[src])
                {
                    st.insert({it,src});
                    st.insert({src,it});
                }
            }
            else if(it!=parent[src])
            {
                low[src]=min(low[src],disc[it]);
            }
        }
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> disc(V);
        vector<int> low(V);
        set<pair<int,int>> st;
        vector<int> parent(V,-1);
        
        for(int i=0;i<V;i++)
        {
            if(disc[i]==0)
            {
                dfs(adj,V,disc,low,parent,st,i);
            }
        }
        
        if(st.find({c,d})!=st.end())
            return 1;
        return 0;
      
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends