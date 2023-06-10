//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]*a[1]>b[0]*b[1])
           return true;
        return false;
    }
  
    int maxHeight(int heights[],int width[],int length[],int n)
    {
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({heights[i],width[i],length[i]});
            v.push_back({width[i],length[i],heights[i]});
            v.push_back({length[i],heights[i],width[i]});
            v.push_back({width[i],heights[i],length[i]});
            v.push_back({length[i],width[i],heights[i]});
            v.push_back({heights[i],length[i],width[i]});
            
        }
        
        // for(auto &it:v)
        // {
        //     sort(it.begin(),it.end());
        // }
        
        sort(v.begin(),v.end(),comp);
        
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        // }
        
        int size=v.size();
        vector<int> dp(size,0);
        dp[0]=v[0][2];
        
        for(int i=1;i<size;i++)
        {
            dp[i]=v[i][2];
            for(int j=0;j<i;j++)
            {
                if(v[j][0]>v[i][0] && v[j][1]>v[i][1])
                   dp[i]=max(dp[i],dp[j]+v[i][2]);
            }
        }
        
        int ans=0;
        for(int i=0;i<size;i++)
        {
            ans=max(ans,dp[i]);
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
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends