//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
    void solve(vector<int> &nums,int ind,int n,vector<int> &v)
    {
        if(ind>=n)
        {
            return ;
        }
        
        int left=2*ind+1;
        solve(nums,left,n,v);
        v.push_back(nums[ind]);
        int right=2*ind+2;
        solve(nums,right,n,v);
        
    }
  
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> temp=A;
        
        //sort(A.begin(),A.end());
        
        vector<int> v;
        
        solve(A,0,n,v);
        
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        // reverse(v.begin(),v.end());
        // v.pop_back();
        // reverse(v.begin(),v.end());
        
        
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({v[i],i});
        }
        
        sort(vp.begin(),vp.end());
        
        int ans=0;
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            int j=i;
            if(vp[j].second==j || vis[j]==1)
               continue;
            int ct=0;
            while(vp[j].second!=j && vis[j]==0)
            {
                ct++;
                vis[j]=1;
                j=vp[j].second;
             //   cout<<j<<endl;
            }
            ans+=(ct-1);
        //    cout<<i<<" "<<ans<<endl;
        }
        
        return ans;
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends