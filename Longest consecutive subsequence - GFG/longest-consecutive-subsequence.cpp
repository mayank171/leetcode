//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    
    
    int findLongestConseqSubseq(int arr[], int N)
    {
        vector<int> v(1e5+10,0);
        
        for(int i=0;i<N;i++)
        {
            v[arr[i]]=1;
        }
        
        
        int ans=0;
        for(int i=0;i<1e5+10;i++)
        {
            if(v[i]==1)
            {
                int j=i;
                int ct=0;
                while(j<1e5+10 && v[j]==1)
                {
                    ct++;
                    j++;
                }
                
                if(ct>ans)
                   ans=max(ct,ans);
                
                i=j;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends