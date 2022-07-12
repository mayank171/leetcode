// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length();
	    int m=str2.length();
	    
	    vector<int> front(m+1,0);
	    
	    for(int i=1;i<n+1;i++)
	    {
	        vector<int> cur(m+1,0);
	        for(int j=1;j<m+1;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                cur[j]=1+front[j-1];
	            }
	            else
	            {
	                cur[j]=max(front[j],cur[j-1]);
	            }
	        }
	        front=cur;
	    }
	    
	    return (n-front[m]+m-front[m]);
	    
	    
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends