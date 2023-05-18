//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        
        vector<int> vis(N*M,0);
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1 && vis[i*M+j]==0 && (i==0 || j==0 || i==N-1 || j==M-1))
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i*M+j]=1;
                    
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;
                            
                            if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && matrix[ind_x][ind_y]==1 && vis[ind_x*M+ind_y]==0)
                            {
                                q.push({ind_x,ind_y});
                                vis[ind_x*M+ind_y]=1;
                            }
                        }
                    }
                }
            }
        }
        
        int ans=0;
        
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(matrix[i][j]==1 && vis[i*M+j]==0)
                {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i*M+j]=1;
                    
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;
                            
                            if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && matrix[ind_x][ind_y]==1 && vis[ind_x*M+ind_y]==0)
                            {
                                q.push({ind_x,ind_y});
                                vis[ind_x*M+ind_y]=1;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends