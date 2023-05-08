class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        vector<int> vis(n*m,0);
        vis[0]=1;
        
        int ans=0;
        
        while(!pq.empty())
        {
            int val=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
            cout<<x<<" "<<y<<endl;
            pq.pop();
            
            ans=max(ans,val);
            
            if(x==n-1 && y==m-1)
            {
                
                break;
            }
            
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    pq.push({grid[ind_x][ind_y],{ind_x,ind_y}});
                }
            }
        }
        
        return ans;
        
    }
};