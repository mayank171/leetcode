//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M){
        
        vector<vector<int>> indian(N,vector<int> (M,0));
        
        queue<pair<int,int>> q1;
        vector<int> vis(N*M,0);
        for(int i=0;i<N;i++)
        {
            indian[i][0]=1;
            q1.push({i,0});
            vis[i*M]=1;
        }
        
        for(int i=0;i<M;i++)
        {
            indian[0][i]=1;
            q1.push({0,i});
            vis[0+i]=1;
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        
        while(!q1.empty())
        {
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && vis[ind_x*M+ind_y]==0 && mat[ind_x][ind_y]>=mat[i][j])
                {
                    indian[ind_x][ind_y]=1;
                    vis[ind_x*M+ind_y]=1;
                    q1.push({ind_x,ind_y});
                }
            }
        }
        
        vector<vector<int>> arabian(N,vector<int> (M,0));
        
        queue<pair<int,int>> q2;
        vector<int> vis1(N*M,0);
        for(int i=0;i<N;i++)
        {
            arabian[i][M-1]=1;
            q2.push({i,M-1});
            vis1[i*M+M-1]=1;
        }
        
        for(int i=0;i<M;i++)
        {
            arabian[N-1][i]=1;
            q2.push({N-1,i});
            vis1[(N-1)*M+i]=1;
        }
        
        while(!q2.empty())
        {
            int i=q2.front().first;
            int j=q2.front().second;
            q2.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && vis1[ind_x*M+ind_y]==0 && mat[ind_x][ind_y]>=mat[i][j])
                {
                    arabian[ind_x][ind_y]=1;
                    vis1[ind_x*M+ind_y]=1;
                    q2.push({ind_x,ind_y});
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(indian[i][j]==1 && arabian[i][j]==1)
                {
                    ans++;
                }
            }
        }
        
        return ans;
        
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends