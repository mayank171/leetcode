// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    
    bool check(vector<int> adj[],vector<int> &vis,int src,set<int> &st,int n,int m)
    {
        
        st.insert(src);
        vis[src]=1;
        
        if(st.size()==n)
        {
            return true;
        }
        
        
        for(auto &it:adj[src])
        {
            if(vis[it]==-1)
            {
                
                if(check(adj,vis,it,st,n,m))
                   return true;
                
               // vis[it]=-1;
               
            }
        }
        st.erase(src);
        vis[src]=-1;
        
        return false;
    }
    
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        
        vector<int> adj[N+1];
        set<int> st;
        
        for(int i=0;i<M;i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        vector<int> vis(N+1,-1);
        
        for(int i=0;i<N+1;i++)
        {
            if(check(adj,vis,i,st,N,M))
              return true;
        }
        
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends