//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int gb=0;
    int solve(vector<int> adj[],int node)
    {
        if(adj[node].size()==0)
           return 0;
          
        vector<int> v;
        for(auto &it:adj[node])
        {
            v.push_back(1+solve(adj,it));
        }
        
        // cout<<node<<"+"<<endl;
        // for(auto &it:v)
        //     cout<<it<<"-";
        // cout<<endl;
        
        if(v.size()==0)
           return 0;
        
        if(v.size()==1 && (v[0]==1 || v[0]==2))
           return v[0];
        else if(v.size()==1)
        {
            gb+=v[0]-2;
            return 2;
        }
           
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans+=(v[i]-1);
        }
        
        gb+=ans;
        
      //  cout<<"++++"<<gb<<endl;
        
        
        return 1;
    }
    
    int solve(int N, vector<int> p){
        
        vector<int> adj[N];
        int root;
        for(int i=0;i<N;i++)
        {
            if(p[i]==-1)
            {
                root=i;
                continue;
            }
            adj[p[i]].push_back(i);
        }
        
        vector<int> dist;
        
        for(auto &it:adj[root])
        {
            int x=1+solve(adj,it);
            dist.push_back(x);
        }
        
        // cout<<0<<"+"<<endl;
        // for(auto &it:dist)
        //     cout<<it<<"-";
        // cout<<endl;
        
       if(dist.size()==0)
           return 0;
        
        if(dist.size()==1 && (dist[0]==1 || dist[0]==2))
           return gb;
        else if(dist.size()==1)
        {
            gb+=(dist[0]-2);
            return gb;
        }
           
        int ans=0;
        for(int i=0;i<dist.size();i++)
        {
            ans+=(dist[i]-1);
        }
        
        gb+=ans;
        
        
        return gb;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends