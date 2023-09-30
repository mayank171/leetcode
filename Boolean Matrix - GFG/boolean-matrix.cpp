//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> v1(n,0);
        vector<int> v2(m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    v1[i]=1;
                    v2[j]=1;
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(v1[i]==1)
            {
                for(int j=0;j<m;j++)
                {
                    matrix[i][j]=1;
                }
            }
        }
        
        for(int j=0;j<m;j++)
        {
            if(v2[j]==1)
            {
                for(int i=0;i<n;i++)
                {
                    matrix[i][j]=1;
                }
            }
        }
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends