class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        vector<int> vis(n*m,1e9);
        vis[0]=0;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ans=1e9;
        
        while(!pq.empty())
        {
            int h=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            cout<<h<<" "<<x<<","<<y<<endl;
            pq.pop();
            
            if(x==n-1 && y==m-1)
            {
                ans=min(ans,h);
              //  vis[x*m+y]=0;
                cout<<ans<<endl;
                continue;
            }
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]>max(h,abs(heights[ind_x][ind_y]-heights[x][y])))
                {            
                    vis[ind_x*m+ind_y]=max(h,abs(heights[ind_x][ind_y]-heights[x][y]));
                    pq.push({max(h,abs(heights[ind_x][ind_y]-heights[x][y])),{ind_x,ind_y}});       
                }
            }
        }
        
        return ans;
        
    }
};