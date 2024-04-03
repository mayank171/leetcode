class Solution {
public:
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
    
    int dfs(vector<vector<char>> &board,int i,int j,int n,int m,vector<int> &vis,int ind,string &word)
    {
        if(ind==word.length()-1)
            return 1;
        
        vis[i*m+j]=1;
        
        for(int ind1=0;ind1<4;ind1++)
        {
            int ind_x=dx[ind1]+i;
            int ind_y=dy[ind1]+j;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && board[ind_x][ind_y]==word[ind+1])
            {
                if(dfs(board,ind_x,ind_y,n,m,vis,ind+1,word))
                    return 1;
            }
        }
        
        vis[i*m+j]=0;
        return 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<int> vis(n*m,0);
                    if(dfs(board,i,j,n,m,vis,0,word))
                        return true;
                }
            }
        }
        
        return false;
    }
};