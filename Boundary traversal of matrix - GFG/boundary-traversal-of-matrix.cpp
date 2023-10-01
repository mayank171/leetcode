//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
         vector<int> ans;
        
        int row_start=0,row_end=n-1;
        int col_start=0,col_end=m-1;
        int count=0;
        int total=n*m;
        while(count<total){
            for(int col=col_start;col<=col_end&&count<total;col++){
                ans.push_back(matrix[row_start][col]);
                count++;
            }
            row_start++;
            
            for(int row=row_start;row<=row_end&&count<total;row++){
                ans.push_back(matrix[row][col_end]);
                count++;
            }
            col_end--;
            
            for(int col=col_end;col>=col_start&&count<total;col--){
                ans.push_back(matrix[row_end][col]);
                count++;
            }
            row_end--;
            
            for(int row=row_end;row>=row_start&&count<total;row--){
                ans.push_back(matrix[row][col_start]);
                count++;
            }
            col_start++;
            break;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends