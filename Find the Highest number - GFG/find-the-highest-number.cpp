//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int check(vector<int> &v,int n,int mid)
    {
        if(mid==n-1)
            return 1;
        if(v[mid]>v[mid+1])
            return 1;
        return 0;
    }
    
    int findPeakElement(vector<int>& v) 
    {
        // Code here.
        int n=v.size();
        int pos=-1;
        int low=0;
        int high=n-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(v,n,mid))
            {
                pos=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return v[pos];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends