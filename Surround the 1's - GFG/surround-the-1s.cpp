//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    int ct=0;
                    for(int ind=0;ind<8;ind++)
                    {
                        int ind_x=dx[ind]+i;
                        int ind_y=dy[ind]+j;
                        
                        if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && matrix[ind_x][ind_y]==0)
                        {
                            ct++;
                        }
                    }    
                    if(ct%2==0 && ct>0)
                    {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends