//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        
        string ans;
        for(int i=0;i<D;i++)
        {
            ans.push_back('0');
        }
        
        for(int i=D-1;i>=0;i--)
        {
            if(S-9>0)
            {
                ans[i]='9';
                S-=9;
            }
            else
            {
                if(S<=0)
                  return "-1";
                else
                {
                    if(i!=0)
                    {
                       ans[i]=(S-1)+'0';
                       ans[0]='1';
                    }
                    else
                    {
                        ans[i]=S+'0';
                    }
                    break;
                }
            }
            
           // cout<<ans<<endl;
        }
        
        int ind=-1;
        for(int i=D-1;i>0;i--)
        {
            if(ans[i]!=ans[i-1] && ans[i]!='0' && ans[i-1]!='9')
            {
                ind=i;
                break;
            }
        }
        
      //  cout<<ans<<endl;
        
        if(ind==-1)
           return "-1";
           
        ans[ind]=ans[ind]-1;
        ans[ind-1]=ans[ind-1]+1;
        
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends