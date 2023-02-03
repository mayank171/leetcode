//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int i=0;
        int j=0;
        int ind=0;
        
        pair<int,int> ans;
        int ii=0;
        int jj=0;
        while(i<R && j<C)
        {
            if(matrix[i][j]==0)
            {
                ii=i+dx[ind];
                jj=j+dy[ind];
                if(ii>=R || ii<0 || jj>=C || jj<0)
                {
                    ans={i,j};
                    break;
                }
                i=i+dx[ind];
                j=j+dy[ind];
            }
            else
            {
                matrix[i][j]=0;
                ind=(ind+1)%4;
                ii=i+dx[ind];
                jj=j+dy[ind];
                if(ii>=R || ii<0 || jj>=C || jj<0)
                {
                    ans={i,j};
                    break;
                }
                i=i+dx[ind];
                j=j+dy[ind];
            }
            
           // cout<<i<<" "<<j<<endl;
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends