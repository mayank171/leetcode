class Solution {
public:
    
    
    int countBattleships(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<int> vis(n*m,0);
        int ans=0;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && vis[i*m+j]==0) 
                {
                    ans++;
                    queue<pair<int,int>>  q;
                    q.push({i,j});
                    vis[i*m+j]=1;
                    
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && board[ind_x][ind_y]=='X')
                            {
                                vis[ind_x*m+ind_y]=1;
                                q.push({ind_x,ind_y});
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};