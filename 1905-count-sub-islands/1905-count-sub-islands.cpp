class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int ans=0;
        
        
        vector<int> vis2(n*m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && vis2[i*m+j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis2[i*m+j]=1;
                    int flag=0;
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                
                        if(grid1[ii][jj]==0)
                        {
                            flag=1;
                        }
        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;

                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid2[ind_x][ind_y]==1 && vis2[ind_x*m+ind_y]==0)
                            {
                                q.push({ind_x,ind_y});
                                vis2[ind_x*m+ind_y]=1;
                                
                            }
                        }
                    }
                    
                    if(flag==0)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};


















