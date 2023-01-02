//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    int size=edges.size();
	    vector<int> dist(n,1000000);
	    
	    for(int k=0;k<n-1;k++)
	    {
	        for(int i=0;i<size;i++)
	        {
	            int src=edges[i][0];
	            int dest=edges[i][1];
	            int w=edges[i][2];
	            if(dist[dest]>dist[src]+w)
	            {
	                dist[dest]=dist[src]+w;
	            }
	        }
	    }
	    
	   for(int i=0;i<size;i++)
	   {
	       int src=edges[i][0];
	       int dest=edges[i][1];
	       int w=edges[i][2];
	       if(dist[dest]>dist[src]+w)
	       {
	           return 1;
	       }
	   }
	   
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends