// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    // Code here
	    int x=KnightPos[0];
	    int y=KnightPos[1];
	    n++;
	    
	    int tar_x=TargetPos[0];
	    int tar_y=TargetPos[1];
	    
	    vector<int> vis(n*n,0);
	    
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{x,y}});
	    vis[x*n+y]=1;
	    
	    while(!q.empty())
	    {
	        int x=q.front().second.first;
	        int y=q.front().second.second;
	        int steps=q.front().first;
	        q.pop();
	        
	       // cout<<x<<" "<<y<<endl;
	        
	        if(x==tar_x && y==tar_y)
	          return steps;

	        
	        int dx[8]={-2,-1,-2,-1,1,2, 2, 1};
	        int dy[8]={-1,-2, 1, 2,2,1,-1,-2};
	        
	        for(int ind=0;ind<8;ind++)
	        {
	            int ind_x=x+dx[ind];
	            int ind_y=y+dy[ind];
	            
	            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<n && vis[ind_x*n+ind_y]==0)
	            {
	                vis[ind_x*n+ind_y]=1;
	                q.push({steps+1,{ind_x,ind_y}});
	            }
	        }
	        
	    }
	    return -1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends