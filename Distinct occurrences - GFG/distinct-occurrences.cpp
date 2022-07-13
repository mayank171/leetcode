// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    int subsequenceCount(string S, string T)
    {
      //Your code here
      int n=S.length();
      int m=T.length();
      
      vector<int> front(m+1,0);
      front[0]=1;
      
      for(int i=1;i<n+1;i++)
      {
          for(int j=m;j>0;j--)
          {
              int l=0;
              int r=0;
              if(S[i-1]==T[j-1])
              {
                  l=front[j-1];
              }
              r=front[j];
              front[j]=(l+r)%mod;
          }
      }
      
      return front[m];
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends