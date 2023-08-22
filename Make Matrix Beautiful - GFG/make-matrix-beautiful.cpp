//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<long long> rows;
        
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[i][j];
            }
            rows.push_back(sum);
        }
        
        vector<long long> cols;
        
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[j][i];
            }
            cols.push_back(sum);
        }
        
        long long maxi1=*max_element(rows.begin(),rows.end());
        long long maxi2=*max_element(cols.begin(),cols.end());
        
        if(maxi1>maxi2)
        {
            int ans=0;
            for(auto &it:rows)
            {
                ans+=(maxi1-it);
            }
            
            return ans;
        }
        else
        {
            int ans=0;
            for(auto &it:cols)
            {
                ans+=(maxi2-it);
            }
            
            return ans;
        }
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends