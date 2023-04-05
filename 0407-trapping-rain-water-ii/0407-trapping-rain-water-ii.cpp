class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int n=heightMap.size();
        int m=heightMap[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<n;i++)
        {
            vis[i][0]=1;
            vis[i][m-1]=1;
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m-1],{i,m-1}});
        }
        
        for(int i=0;i<m;i++)
        {
            vis[0][i]=1;
            vis[n-1][i]=1;
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[n-1][i],{n-1,i}});
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ans=0;
        
        
        while(!pq.empty())
        {
            int cur=pq.top().first;
            int ii=pq.top().second.first;
            int jj=pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+ii;
                int ind_y=dy[i]+jj;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x][ind_y]==0)
                {
                    vis[ind_x][ind_y]=1;
                    if(cur>heightMap[ind_x][ind_y])
                    {
                        ans+=abs(cur-heightMap[ind_x][ind_y]);
                        pq.push({cur,{ind_x,ind_y}});
                    }
                    else
                    {
                        pq.push({heightMap[ind_x][ind_y],{ind_x,ind_y}});        
                    }
                }
            }
        }
        
        return ans;
        
        
        
        
    }
};