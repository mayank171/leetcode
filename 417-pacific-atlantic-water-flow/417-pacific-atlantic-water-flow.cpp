class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,0));
        
        vector<int> visp(n*m,0);
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            q.push({0,i});
            visp[0*m+i]=1;
            pacific[0][i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            q.push({i,0});
            visp[i*m+0]=1;
            pacific[i][0]=1;
        }
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && heights[x][y]<=heights[ind_x][ind_y] && visp[ind_x*m+ind_y]==0)
                {
                    q.push({ind_x,ind_y});
                    pacific[ind_x][ind_y]=1;
                    visp[ind_x*m+ind_y]=1;
                }
            }
        }
        
        
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        
        vector<int> visa(n*m,0);
        queue<pair<int,int>> qa;
        
        for(int i=m-1;i>=0;i--)
        {
            qa.push({n-1,i});
            visa[(n-1)*m+i]=1;
            atlantic[n-1][i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            qa.push({i,m-1});
            visa[i*m+(m-1)]=1;
            atlantic[i][m-1]=1;
        }
        
        while(!qa.empty())
        {
            int x=qa.front().first;
            int y=qa.front().second;
            qa.pop();
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && heights[x][y]<=heights[ind_x][ind_y] && visa[ind_x*m+ind_y]==0)
                {
                    qa.push({ind_x,ind_y});
                    atlantic[ind_x][ind_y]=1;
                    visa[ind_x*m+ind_y]=1;
                }
            }
        }
        
        vector<vector<int>> ans;
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<pacific[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<atlantic[i][j]<<" ";
                if(pacific[i][j]==atlantic[i][j] && pacific[i][j]==1)
                    ans.push_back({i,j});
            }
           // cout<<endl;
        }
        
        return ans;
        
        
        
    }
};