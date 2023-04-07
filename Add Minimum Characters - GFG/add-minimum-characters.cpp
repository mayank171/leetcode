//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        
        int n=str.length();
        
       // cout<<n<<endl;
        
        int flag=0;
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-i-1])
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0)
           return 0;
           
        int ans=0;
        int j=0;
        int start=n-1;
        int ct=0;
        for(int i=n-1;i>=0;i--)
        {
            if(str[i]!=str[j])
            {
              //  cout<<i<<" "<<j<<endl;
                
                if(ct>0)
                {
                    ans+=ct;
                    ct=0;
                }
                else
                   ans++;
               // cout<<ans<<endl;
                
                if(j!=0)
                {
                    j=0;
                    i++;
                }
                
            }
            else
            {
                j++;
               // start=i;
                ct++;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends