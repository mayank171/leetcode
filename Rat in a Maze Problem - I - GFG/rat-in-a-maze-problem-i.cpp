// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    
    void check(vector<vector<int>> &m,int x,int y,int f_x,int f_y,string str,vector<string> &ans,vector<vector<int>> &vis)
    {
        if(x==f_x-1 && y==f_y-1)
        {
            ans.push_back(str);
            return ;
        }
        
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};    
        
        
        for(int i=0;i<4;i++)
        {
            int x_ind=x+dx[i];
            int y_ind=y+dy[i];
            
            
            if(x_ind>=0 && x_ind<f_x && y_ind>=0 && y_ind<f_y && m[x_ind][y_ind]==1 && vis[x_ind][y_ind]==0)
            {
                if(i==0)
                {
                    str.push_back('D');
                }
                else if(i==1)
                {
                    str.push_back('L');
                }
                else if(i==2)
                {
                    str.push_back('R');
                }
                else
                {
                    str.push_back('U');
                }
                vis[x][y]=1;
                check(m,x_ind,y_ind,f_x,f_y,str,ans,vis);
                str.pop_back();
                vis[x][y]=0;
            }
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        int x=0;
        int y=0;
        
        
        
        int f_x=n;
        int f_y=n;
        
        vector<string> ans;
        
        vector<int> temp(n,0);
        
         vector<vector<int>> vis(n, vector<int> (n, 0));
        
        if(m[0][0]==0)
           return ans;
        
        string str="";
        
        int a[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=m[i][j];
            }
        }
        
        check(m,x,y,f_x,f_y,str,ans,vis);
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends