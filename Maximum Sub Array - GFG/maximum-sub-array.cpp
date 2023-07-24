//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    int ind1=-1;
	    int ind2=-1;
	    
	    int l=-1;
	    int r=-1;
	    
	    int maxsum=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)
	        {
	            int l=i;
	            int r=i;
	            int j=i;
	            int sum=0;
	            while(j<n && a[j]>=0)
	            {
	                sum+=a[j];
	                r=j;
	                j++;
	            }
	            
	        //    cout<<l<<" "<<r<<endl;
	            
	            if(sum>maxsum)
	            {
	                maxsum=sum;
	                ind1=l;
	                ind2=r;
	            }
	            else if(sum==maxsum)
	            {
	               // cout<<"333<"<<endl;
	                if(r-l>ind2-ind1)
	                {
	                    ind1=l;
	                    ind2=r;
	                }
	            }
	            i=j;
	        }
	    }
	    
	    if(ind1==-1)
	    {
	        for(int i=0;i<n;i++)
	        {
	            if(a[i]==0)
	            {
	                return {0};
	            }
	        }
	        
	        return {-1};
	    }
	       
	    vector<int> ans;
	    for(int i=ind1;i<=ind2;i++)
	    {
	        ans.push_back(a[i]);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends