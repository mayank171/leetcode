//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        
        sort(arr.begin(),arr.end());
        int ans=0;
        
        set<int> st;
        
        for(auto &it:arr)
           st.insert(it);
           
        // for(auto &it:arr)
        //   cout<<it<<" ";
        // cout<<endl;
           
        
        for(int i=n-1;i>=0;i--)
        {
            if(i-1>=0 && arr[i]==arr[i-1])
            {
                int start=i;
                int flag=0;
                while(start-1>=0 && arr[start]==arr[start-1])
                {
                    start--;
                    ans++;
                    flag=1;
                }
                
                if(flag==1)
                   ans++;
                   
                i=start;
            }
            else if(st.find(1)!=st.end() && arr[i]!=1)
            {
                ans++;
            }
            else
            {
                for(int j=2;j*j<=arr[i];j++)
                {
                    if((st.find(j)!=st.end() && arr[i]%j==0) || (st.find(arr[i]/j)!=st.end() && arr[i]%(arr[i]/j)==0))
                    {
                        ans++;
                        break;
                    }
                }
            }
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends