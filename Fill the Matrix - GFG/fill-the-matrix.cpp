//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        
        vector<vector<int>> mat(N,vector<int>(M,0));
        x--;
        y--;
        mat[x][y]=1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{x,y}});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ans=0;
        
        while(!q.empty())
        {
            int t=q.front().first;
            int ii=q.front().second.first;
            int jj=q.front().second.second;
            q.pop();
            
            ans=t;
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+ii;
                int ind_y=dy[ind]+jj;
                
                if(ind_x>=0 && ind_x<N && ind_y>=0 && ind_y<M && mat[ind_x][ind_y]==0)
                {
                    mat[ind_x][ind_y]=1;
                    q.push({t+1,{ind_x,ind_y}});
                }
            }
        }
        
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends