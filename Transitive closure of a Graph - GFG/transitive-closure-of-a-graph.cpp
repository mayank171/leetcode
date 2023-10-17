//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:

    void dfs(vector<vector<int>> &graph,int src,int N,int orig,vector<vector<int>> &ans,vector<int> &vis)
    {
        vis[src]=1;
        
        for(int i=0;i<N;i++)
        {
            if(graph[src][i]==1 && i!=src)
            {
                ans[orig][i]=1;
                if(vis[i]==0)
                   dfs(graph,i,N,orig,ans,vis);
            }
        }
    }


    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> ans(N,vector<int>(N,0));
        for(int i=0;i<N;i++)
        {
            vector<int> vis(N,0);
            dfs(graph,i,N,i,ans,vis);
        }
        
        for(int i=0;i<N;i++)
        {
            ans[i][i]=1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends