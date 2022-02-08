// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool check(vector<int> adj[],int N)
    {
        vector<int> indeg(N,0);
        queue<int> q;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indeg[adj[i][j]]++;
            }
        }
        
        vector<int> topo;
        
        for(int i=0;i<N;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        
        // for(auto it:indeg)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        int c=0;
        while(!q.empty())
        {
            int node=q.front();
            c++;
            q.pop();
            
            for(auto &it:adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                    //c++;
                }
            }
        }
        
        // cout<<c<<endl;
        
        if(c==N)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    
	    vector<int> adj[N];
	    
	    int size=pre.size();
	    
	    for(int i=0;i<size;i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    
	   // for(int i=0;i<N;i++)
	   // {
	   //     for(int j=0;j<adj[i].size();j++)
	   //     {
	   //         cout<<adj[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	    if(check(adj,N))
	       return true;
	   else
	       return false;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends