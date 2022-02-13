// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    
	    vector<int> indeg(V,0);
	    
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indeg[adj[i][j]]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indeg[i]&1)
	           return false;
	    }
	    
	    return true;
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends