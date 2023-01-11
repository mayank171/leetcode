//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        
        vector<char> opr;
        vector<bool> val;
        
        int mod=1003;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='T' && s[i]!='F')
            {
                opr.push_back(s[i]);
            }
            else
            {
                if(s[i]=='T')
                   val.push_back(true);
                else
                   val.push_back(false);
            }
        }
        
        int size=val.size();
       // cout<<size<<endl;
        
        vector<vector<int>> dpt(size,vector<int>(size,0));
        vector<vector<int>> dpf(size,vector<int>(size,0));
        
        
        for(int gap=0;gap<size;gap++)
        {
            for(int i=0,j=gap;j<size;i++,j++)
            {
                if(gap==0)
                {
                    if(val[i]==true)
                       dpt[i][j]=1,dpf[i][j]=0;
                    else
                       dpf[i][j]=1,dpt[i][j]=0;
                }
                else
                {
                    for(int k=i;k<j;k++)
                    {
                        int lct=dpt[i][k];
                        int rct=dpt[k+1][j];
                        int lcf=dpf[i][k];
                        int rcf=dpf[k+1][j];
                        
                        if(opr[k]=='|')
                        {
                            dpt[i][j]=(dpt[i][j]+(lct*rct+lcf*rct+rcf*lct)%mod)%mod;
                            dpf[i][j]=(dpf[i][j]+(lcf*rcf)%mod)%mod;
                        }
                        else if(opr[k]=='&')
                        {
                            dpt[i][j]=(dpt[i][j]+(lct*rct)%mod)%mod;
                            dpf[i][j]=(dpf[i][j]+(lct*rcf+lcf*rct+lcf*rcf)%mod)%mod;
                        }
                        else
                        {
                            dpt[i][j]=(dpt[i][j]+(lct*rcf+rct*lcf)%mod)%mod;
                            dpf[i][j]=(dpf[i][j]+(lct*rct+rcf*lcf)%mod)%mod;
                        }
                    }
                    
                }
            }
            
            // if(gap==1)
            //   break;
        }
        
        // for(auto &it:dpt)
        // {
        //     for(auto &it1:it)
        //     {
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        // for(auto &it:dpf)
        // {
        //     for(auto &it1:it)
        //     {
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
        
       // return 0;
        
        return dpt[0][size-1];
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends