//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        sort(arr,arr+n);
        int ans=0;
        
        vector<int> temp;
        temp.push_back(arr[0]);
        
        for(int i=1;i<n;i++)
        {
            if(temp.back()==arr[i])
               continue;
            temp.push_back(arr[i]);
        }
        
        for(int i=0;i<temp.size();i++)
        {
            int start=i;
            int cur=temp[i];
            int j=i;
            while((j<temp.size() && j-start==temp[j]-cur))
            {
                j++;
            }
            ans=max(ans,(j-start));
         //   cout<<j<<" "<<start<<endl;
            i=j-1;
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