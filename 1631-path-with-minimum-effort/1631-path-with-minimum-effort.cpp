class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        
        vector<int> vis(n*m,1e9);
        vis[0]=heights[0][0];
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ans=1e9;
        while(!q.empty())
        {
            int cur=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            
           // cout<<cur<<" "<<i<<" "<<j<<endl;
            
            if(i==n-1 && j==m-1)
            {
                ans=min(ans,cur);
               // continue;
            }
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && max(cur,abs(heights[i][j]-heights[ind_x][ind_y]))<vis[ind_x*m+ind_y])
                {
                    // if(ind_x==n-1 && ind_y==m-1)
                    // {
                    //     ans=min(ans,max(cur,abs(heights[i][j]-heights[ind_x][ind_y])));
                    //     continue;
                    // }
                    vis[ind_x*m+ind_y]=max(cur,abs(heights[i][j]-heights[ind_x][ind_y]));
                    q.push({max(cur,abs(heights[i][j]-heights[ind_x][ind_y])),{ind_x,ind_y}});
                }
            }
        }
        
        return ans;
        
    }
};