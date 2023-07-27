//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int check(vector<vector<int>> &grid,int n,int i,int j)
    {
        int ii=i-1;
        int jj=j-1;
        while(ii>=0 && jj>=0)
        {
            if(grid[ii][jj]==1)
               return false;
            ii--;
            jj--;
        }
        
        ii=i+1;
        jj=j-1;
        while(ii<n && jj>=0)
        {
            if(grid[ii][jj]==1)
               return false;
            ii++;
            jj--;
        }
        
        ii=i;
        jj=j-1;
        while(jj>=0)
        {
            if(grid[ii][jj]==1)
               return false;
            jj--;
        }
        
        return true;
    }

    void solve(int n,vector<vector<int>> &ans,vector<int> &temp,int j,vector<vector<int>> &grid)
    {
        if(j==n)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            grid[i][j]=1;
            if(check(grid,n,i,j))
            {
                temp.push_back(i+1);
                solve(n,ans,temp,j+1,grid);
                temp.pop_back();
            }
            grid[i][j]=0;
        }
    }

    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> grid(n,vector<int> (n,0));
        solve(n,ans,temp,0,grid);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends