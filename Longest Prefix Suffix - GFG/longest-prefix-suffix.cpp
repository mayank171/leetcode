//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    
	    int n=s.length();
	    vector<int> pi(n,0);
	    
	    int j=0;
	    for(int i=1;i<n;i++)
	    {
	        if(s[i]==s[j])
	        {
	            pi[i]=j+1;        
	            j++;
	        }
	        else
	        {
	            int flag=0;
	            j=(j-1>=0)?pi[j-1]:flag=1;
	            
	            while(j>=0 && flag==0)
	            {
	                if(s[i]==s[j])
	                {
	                    break;
	                }
	                else
	                {
	                    j=(j-1>=0)?pi[j-1]:flag=1;
	                    if(flag==1)
	                       break;
	                }
	            }
	            
	            if(flag==1)
	            {
	                j=0;
	            }
	            else
	            {
	                pi[i]=j+1;
	                j++;
	            }
	        }
	    }
	    
	    return pi[n-1];
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends