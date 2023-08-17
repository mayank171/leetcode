class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    mat[i][j]=-1;
                }
                else
                {
                    pq.push({0,{i,j}});            
                }
            }
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+i;
                int ind_y=dy[ind]+j;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && mat[ind_x][ind_y]==-1)
                {
                    mat[ind_x][ind_y]=1+d;
                    pq.push({1+d,{ind_x,ind_y}});
                }
            }
        }
        
        return mat;
    }
};















