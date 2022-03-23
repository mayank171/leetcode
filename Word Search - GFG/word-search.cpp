// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(int x,int y,vector<vector<char>> &board,vector<int> &vis,int n,int m,int index,int l,string word)
    {
        vis[x*m+y]=1;
        
        //         // cout<<l<<endl;
        // cout<<l<<endl;
        // cout<<l<<endl;
        
        if(index==l-1)
          return true;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int ind_x=dx[i]+x;
            int ind_y=dy[i]+y;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && board[ind_x][ind_y]==word[index+1] && vis[ind_x*m+ind_y]==0)
            {
                vis[ind_x*m+ind_y]=1;
                if(check(ind_x,ind_y,board,vis,n,m,index+1,l,word))
                    return true;
                
            }
        }
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        int l=word.length();
        
        int n=board.size();
        int m=board[0].size();
        
        bool ans=false;
        
        for(int i=0;i<n;i++)
        {
            int ind=0;
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    ind=0;
                    //queue<pair<pair<int,int>,int>> q;
                    vector<int> vis(n*m,0);
                   // q.push({{i,j},ind});
                    vis[i*m+j]=1;
                    ans=check(i,j,board,vis,n,m,ind,l,word);
                    if(ans==true)
                    return true;
                    // while(!q.empty())
                    // {
                    //     int x=q.front().first.first;
                    //     int y=q.front().first.second;
                    //     int index=q.front().second;
                    //   // cout<<x<<" "<<y<<" "<<index<<endl;
                    //     q.pop();
                        
                    //     if(index+1==l)
                    //       return 1;
                        
                    //     int dx[4]={-1,0,1,0};
                    //     int dy[4]={0,1,0,-1};
                        
                    //     for(int i=0;i<4;i++)
                    //     {
                    //         int ind_x=dx[i]+x;
                    //         int ind_y=dy[i]+y;
                            
                    //         if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && board[ind_x][ind_y]==word[index+1] && vis[ind_x*m+ind_y]==0)
                    //         {
                    //             vis[ind_x*m+ind_y]=1;
                    //             q.push({{ind_x,ind_y},index+1});
                    //         }
                    //     }
                        
                    // }
                }
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends