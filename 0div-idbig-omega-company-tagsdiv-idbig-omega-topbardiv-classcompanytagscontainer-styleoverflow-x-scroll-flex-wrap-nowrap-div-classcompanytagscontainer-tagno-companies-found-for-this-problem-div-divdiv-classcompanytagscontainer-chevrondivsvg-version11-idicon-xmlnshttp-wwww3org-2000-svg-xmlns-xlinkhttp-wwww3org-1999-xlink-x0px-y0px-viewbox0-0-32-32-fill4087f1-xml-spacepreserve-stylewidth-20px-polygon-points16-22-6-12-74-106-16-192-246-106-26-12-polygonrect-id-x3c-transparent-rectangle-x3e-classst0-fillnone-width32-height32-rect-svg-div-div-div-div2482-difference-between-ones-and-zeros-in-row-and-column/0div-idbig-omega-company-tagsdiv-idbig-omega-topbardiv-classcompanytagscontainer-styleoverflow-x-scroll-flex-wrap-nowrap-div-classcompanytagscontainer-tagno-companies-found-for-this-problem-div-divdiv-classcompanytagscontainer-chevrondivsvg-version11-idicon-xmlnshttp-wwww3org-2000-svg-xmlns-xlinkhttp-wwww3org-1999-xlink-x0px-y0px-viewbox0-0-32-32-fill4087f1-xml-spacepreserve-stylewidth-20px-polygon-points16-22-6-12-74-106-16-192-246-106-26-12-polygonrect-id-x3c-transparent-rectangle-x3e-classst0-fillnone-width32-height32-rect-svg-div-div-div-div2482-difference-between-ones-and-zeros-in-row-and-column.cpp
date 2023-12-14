class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> onei(n,0);
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ct++;
            }
            
            onei[i]=ct;
        }
        
        vector<int> onej(m,0);
        
        for(int j=0;j<m;j++)
        {
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==1)
                    ct++;
            }
            
            onej[j]=ct;
        }
        
        vector<int> zeroi(n,0);
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    ct++;
            }
            
            zeroi[i]=ct;
        }
        
        vector<int> zeroj(m,0);
        
        for(int j=0;j<m;j++)
        {
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==0)
                    ct++;
            }
            
            zeroj[j]=ct;
        }
        
      
        
        
        for(int i=0;i<n;i++)
        {
           // cout<<onei[i]<<" "<<zeroi[i]<<endl;
            for(int j=0;j<m;j++)
            {
                int ct=onei[i]-zeroi[i];
                ct+=(onej[j]-zeroj[j]);
          //      cout<<onej[j]<<"_"<<zeroj[j]<<endl;
                grid[i][j]=ct;
            }
            
        }
        
        return grid;
        
    }
};