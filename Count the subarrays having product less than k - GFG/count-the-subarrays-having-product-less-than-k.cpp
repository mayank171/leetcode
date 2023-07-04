//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        int i=-1;
        int j=-1;
        int ans=0;
        long long prod=1;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                prod*=a[i];
                if(prod<k)
                {
                    ans+=(i-j);
                }
                else
                {
                    break;
                }
            }
            
            while(j<i && prod>=k)
            {
                flag2=1;
                j++;
                prod/=a[j];
                
                if(prod<k)
                {
                    ans+=(i-j);
                }
            }
            
            if(flag1==0 && flag2==0)
               break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends