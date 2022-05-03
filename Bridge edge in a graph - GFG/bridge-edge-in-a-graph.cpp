// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    
    void dfs(vector<int> &disc,vector<int> &parent,vector<int> &low,set<pair<int,int>> &st,int src,vector<int> adj[])
    {
        static int time=0;
        disc[src]=low[src]=time;
        time++;
        
        for(auto &it:adj[src])
        {
            if(disc[it]==-1)
            {
                parent[it]=src;
                dfs(disc,parent,low,st,it,adj);
                low[src]=min(low[it],low[src]);
                
                if(low[it]>disc[src])
                {
                    st.insert({it,src});
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
        
        
        
        
        
        vector<int> disc(V,-1);
        vector<int> parent(V,-1);
        vector<int> low(V,-1);
        set<pair<int,int>> st;
        
        for(int i=0;i<V;i++)
        {
            if(disc[i]==-1)
            {
                dfs(disc,parent,low,st,i,adj);
            }
        }
        
        // for(auto &it:st)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        if(st.find({c,d})!=st.end() || st.find({d,c})!=st.end())
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