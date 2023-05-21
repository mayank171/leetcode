class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        int i,j;
        int flag=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    flag=1;
                    break;
                }   
            }
            if(flag==1)
                break;
        }
        
        q.push({i,j});
        vector<int> vis(n*m,0);
        vis[i*m+j]=1;
        queue<pair<pair<int,int>,int>> q1;
       
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        while(!q.empty())
        {
            int ii=q.front().first;
            int jj=q.front().second;
          //  cout<<ii<<" "<<jj<<endl;
            q1.push({{ii,jj},0});
            q.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+ii;
                int ind_y=dy[ind]+jj;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({ind_x,ind_y});
                }
            }
        }
        
        int ans=0;
        
        while(!q1.empty())
        {
            
            int ii=q1.front().first.first;
            int jj=q1.front().first.second;
            int ct=q1.front().second;
         //   cout<<ii<<" "<<jj<<" "<<ct<<endl;
            q1.pop();
            
            if(grid[ii][jj]==1 && ct>0)
            {
                ans=ct-1;
                break;
            }
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+ii;
                int ind_y=dy[ind]+jj;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q1.push({{ind_x,ind_y},ct+1});
                }
            }
        }
        
        return ans;
    }
};





















