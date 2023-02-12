//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           
            int ans=0;
            for(int i=0;i<n;i++)
            {
                int start=i;
            
                while(start<n && arr[start]==0)
                {
                    start++;
                    
                }
                
                int end=start;
                int ctneg=0;
                int firstneg=-1;
                int lastneg=-1;
                
                while(end<n && arr[end]!=0)
                {
                    if(arr[end]<0)
                    {
                        if(firstneg==-1)
                           firstneg=end;
                        lastneg=end;
                        ctneg++;
                    }
                    end++;
                }
                
                if(ctneg%2==0)
                {
                    ans=max(ans,end-start);
                }
                else
                {
                   if(firstneg!=-1)
                      ans=max(ans,end-firstneg-1);
                   if(lastneg!=-1)
                      ans=max(ans,lastneg-start);
                }
                i=end;
            }
            
            return ans;
              
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends