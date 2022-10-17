//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int nums[], int n, int left, int right)
    {
        // Complete the function
        
        int ans=0;
        
        int ctless=0;
        int ct=0;
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<left)
            {
                ctless++;
                ct++;
            }
            else if(nums[i]>=left && nums[i]<=right)
            {
                if(ctless>0)
                {
                    v.push_back(ctless);
                    ctless=0;
                }
                ct++;
            }
            else if(nums[i]>right)
            {
                ans+=(ct*1ll*(ct+1))/2;
                if(ctless>0)
                   v.push_back(ctless);
                ctless=0;
                ct=0;
            }
                
        }
        
        if(ctless>0)
            v.push_back(ctless);
        
        if(ct>0)
            ans+=(ct*1ll*(ct+1))/2;
        
        int size=v.size();
        for(int i=0;i<size;i++)
        {
            ans-=(v[i]*1ll*(v[i]+1))/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends