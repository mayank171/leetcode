class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int> v1(n,0);
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    ct++;
            }
            
            v1[i]=ct;
        }
        
        vector<int> v2(m,0);
        
        for(int j=0;j<m;j++)
        {
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(mat[i][j]==1)
                    ct++;
            }
            
            v2[j]=ct;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && v1[i]==1 && v2[j]==1)
                    ans++;
            }
        }
        
        return ans;
    }
};

/*
   1  1  1
1 
1
1



*/