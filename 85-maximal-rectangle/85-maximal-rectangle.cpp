class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> last(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            int lt=m;
            for(int j=m-1;j>=0;j--)
            {
                if(matrix[i][j]=='0')
                {
                    lt=j;
                }
                else
                {
                    last[i][j]=lt;
                }
            }
        }
        
    
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            
            for(int j=0;j<m;j++)
            {
                int row=0;
                int col=0;
                if(matrix[i][j]=='1')
                {
                    col=last[i][j]-j;
                    row++;
                    ans=max(ans,row*col);
                    
                    for(int k=i+1;k<n;k++)
                    {
                        if(matrix[k][j]=='0')
                            break;
                        else
                        {
                            row++;
                            col=min(col,last[k][j]-j);
                            ans=max(ans,row*col);
                        }
                    }
                }
                
               // cout<<row<<" "<<col<<endl;
                //ans=max(ans,row*col);
            }
        }
        
        return ans;
        
    }
};