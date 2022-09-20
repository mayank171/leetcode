class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        vector<int> vis(n*m,INT_MAX);
        
        vis[0]=0;
        
        int ans=1e8;
        
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
         
            pq.pop();
            
            if(x==n-1 && y==m-1)
            {
                ans=min(ans,diff);
              //  cout<<"+"<<ans<<endl;
                continue;
            }
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]>max(diff,abs(heights[x][y]-heights[ind_x][ind_y]))) 
                {
                    vis[ind_x*m+ind_y]=max(diff,abs(heights[x][y]-heights[ind_x][ind_y]));
                    pq.push({max(diff,abs(heights[x][y]-heights[ind_x][ind_y])),{ind_x,ind_y}});
                }
            }
        }
        
        //cout<<endl;
        return ans;
        
    }
};