class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int> (n,-1));
        
        int x=1;
        int i=0;
        int j=0;
        int ind=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        ans[0][0]=1;
        x++;
        
        while(true)
        {
            int flag=0;
            for(int k=0;k<4;k++)
            {
                int ii=dx[k]+i;
                int jj=dy[k]+j;
                
                if(ii>=0 && ii<n && jj>=0 && jj<n && ans[ii][jj]==-1)
                {
                    flag=1;
                }
            }
            
            if(flag==0)
               break;
            
            int ind_x=dx[ind]+i;
            int ind_y=dy[ind]+j;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<n && ans[ind_x][ind_y]==-1)
            {
              //  cout<<ind_x<<" "<<ind_y<<" "<<x<<endl;
                ans[ind_x][ind_y]=x;
                i=ind_x;
                j=ind_y;
                x++;
            }
            else
            {
                ind=(ind+1)%4;
                //continue;
            }
            
          //  int flag=0;
            
        }
        
        return ans;
        
    }
};