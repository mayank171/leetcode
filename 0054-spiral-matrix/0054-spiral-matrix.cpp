class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> vis(n*m,0);
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int i=0;
        int j=0;
        vis[i*m+j]=1;
        int ind=0;
        vector<int> ans;
        ans.push_back(matrix[i][j]);
        
        while(true)
        {
           // cout<<i<<" "<<j<<endl;
            int ind_x=i+dx[ind];
            int ind_y=j+dy[ind];
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
            {
                ans.push_back(matrix[ind_x][ind_y]);
                vis[ind_x*m+ind_y]=1;
                i=ind_x;
                j=ind_y;
            }
            else
            {
                ind=(ind+1)%4;
            }
            
            int flag=0;
            for(int ind1=0;ind1<4;ind1++)
            {
                int xx=dx[ind1]+i;
                int yy=dy[ind1]+j;
                
                if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx*m+yy]==0)
                {
                    flag=1;
                }
            }
            
            if(flag==0)
                break;
        }
        
        return ans;
        
    }
};