// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        if(A[0][0]==0)
          return -1;
          
          if(A[X][Y]==0)
          return -1;
        
        vector<int> vis(N*M,0);
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        vis[0]=1;
        
        int min=INT_MAX;
        
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dis=q.front().second;
            q.pop();
           // cout<<x<<" "<<y<<endl;
            
            if(x==X && y==Y)
            {
                //cout<<dis<<endl;
                if(dis<min)
                min=dis;
                continue;
            }
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && A[ind_x][ind_y]==1 && vis[ind_x*M+ind_y]==0)
                {
                    vis[ind_x*M+ind_y]=1;
                    q.push({{ind_x,ind_y},dis+1});
                }
            }
        }
        
        if(min==INT_MAX)
        return -1;
        else
        return min;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends