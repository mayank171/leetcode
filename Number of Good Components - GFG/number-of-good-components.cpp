//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>> &adj,int src,set<int> &st,vector<int> &vis)
    {
        vis[src]=1;
        st.insert(src);
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                dfs(adj,it,st,vis);
            }
        }
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& v) {
        
       
    //     vector<int> adj[10000];
    //   //  return 0;
        
    //     // for(int i=0;i<v.size();i++)
    //     // {
    //     //     cout<<v[i].size()<<endl;
    //     // }
    //     // return 0;
    //     for(int i=0;i<v.size();i++)
    //     {
    //         for(auto &it:v[i])
    //         {
    //             adj[it].push_back(i);
    //             adj[i].push_back(it);
                
    //         }
    //         // adj[v[i][0]].push_back(v[i][1]);
    //         // adj[v[i][1]].push_back(v[i][0]);
    //         // //return 0;
            
    //     }
       // return 0;
        
        vector<int> vis(V+1,0);
        int ans=0;
        
        for(int i=1;i<V+1;i++)
        {
            if(vis[i]==0)
            {
                //return 0;
                set<int> st;
                dfs(v,i,st,vis);
               // return 0;
                
                int indeg=st.size()-1;
                int flag=0;
                for(auto &it:st)
                {
                   // cout<<it<<endl;
                    if(v[it].size()!=indeg)
                    {
                        flag=1;
                        break;
                    }
                }
                
                if(flag==0)
                   ans++;
                   
                 //  return 0;
            }
            
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends