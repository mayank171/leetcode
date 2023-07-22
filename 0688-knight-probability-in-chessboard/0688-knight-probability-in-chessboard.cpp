class Solution {
public:
    
    int dx[8]={-1,-2,-2,-1,1,2,2,1};
    int dy[8]={-2,-1,1,2,2,1,-1,-2};
    
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>> cur(n,vector<double>(n));
        vector<vector<double>> next(n,vector<double>(n));
        cur[row][column]=1;
        
        for(int m=0;m<k;m++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(cur[i][j]!=0)
                    {
                        for(int ind=0;ind<8;ind++)
                        {
                            int ind_x=dx[ind]+i;
                            int ind_y=dy[ind]+j;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<n)
                            {
                                next[ind_x][ind_y]+=cur[i][j]*0.125;
                            }
                        }
                    }
                }
            }
            
            cur=next;
            vector<vector<double>> temp(n,vector<double>(n));
            next=temp;
        }
        
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=cur[i][j];
            }
        }
        
        return ans;
    }
};