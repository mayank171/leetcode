// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    
    void dfs(vector<int> adj[],vector<int> &disc,vector<int> &parent,vector<int> &low,vector<bool> &ap,int src,vector<int> &vis)
    {
        static int time=0;
        int count=0;
        disc[src]=low[src]=time;
        time++;
        vis[src]=1;
        //count++;
        
        for(auto &it:adj[src])
        {
            if(parent[src]==it)
                continue;
            else if(vis[it]==1)
            {
                low[src]=min(low[src],disc[it]);
            }
            else
            {
                parent[it]=src;
                count++;
                dfs(adj,disc,parent,low,ap,it,vis);
                
                low[src]=min(low[src],low[it]);
                
                if(parent[src]==-1)
                {
                    if(count>=2)
                    {
                        ap[src]=true;
                    }
                }
                else 
                {
                    if(low[it]>=disc[src])
                    {
                        ap[src]=true;
                    }
                }
            }
            
        }
    }
    
  public:
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> disc(V,-1);
        vector<int> parent(V,-1);
        vector<int> low(V,-1);
        vector<bool> ap(V,false);
        vector<int> vis(V,0);
        
        
        for(int i=0;i<V;i++)
        {
            if(disc[i]==-1)
            {
                dfs(adj,disc,parent,low,ap,i,vis);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<V;i++)
        {
            if(ap[i]==true)
              ans.push_back(i);
        }
        
        if(ans.size()>0)
        return ans;
        
        return {-1};
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends