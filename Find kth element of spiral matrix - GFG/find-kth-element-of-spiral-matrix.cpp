//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        if(k>n*m)
          return 0;
        
 		int dx[4]={0,1,0,-1};
 		int dy[4]={1,0,-1,0};
 		
 		vector<int> vis(n*m,0);
 		
 		int ii=0;
 		int jj=0;
 		
 		int ans=a[0][0];
 		vis[0]=1;
 		
 		int indd=0;
 		while(true)
 		{
 		    int ct=0;
 		    int flag=0;
 		    for(int ind=indd;ind<4;ind++)
 		    {
 		        ct++;
 		        int ind_x=dx[ind]+ii;
 		        int ind_y=dy[ind]+jj;
 		        
 		        if(ct==4)
 		        {
 	               flag=1;
 		           break;
 		        }
 		        
 		        if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
 		        {
 		            k--;
 		            if(k==0)
 		              break;
 		              
 		           // cout<<ind_x<<" "<<ind_y<<endl;
 		            ans=a[ind_x][ind_y];
 		            vis[ind_x*m+ind_y]=1;
 		            ii=ind_x;
 		            jj=ind_y;
 		            break;
 		        }
 		        else
 		        {
 		            indd=(indd+1)%4;
 		        }
 		    }
 		    
 		    if(flag==1 || k==0)
 		       break;
 		       
 		       
 		}
 		
 		return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends