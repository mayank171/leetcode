//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        int binExp(long long a,long long b,int mod)
        {
            long long ans=1;
            while(b)
            {
                if(b&1)
                {
                    ans=(ans*a)%mod;
                }
                a=(a*a)%mod;
                b>>=1;
            }
            return ans;
        }
    
        vector <int> search(string pat, string txt)
        {
            
            
            int mod=1e9+7;
            
            long long l1=pat.length();
            long long l2=txt.length();
            
           // cout<<l1<<" "<<l2<<endl;
            
            if(l1>l2)
               return {-1};
               
            long long p=1;
            long long hash1=0;
            for(int i=0;i<l1;i++)
            {
                hash1=(hash1+((pat[i]-'a'+1)*p)%mod)%mod;
                p=(p*31)%mod;
            }
            
            p=1;
            long long hash2=0;
            for(int i=0;i<l1;i++)
            {
                hash2=(hash2+((txt[i]-'a'+1)*p)%mod)%mod;
                p=(p*31)%mod;
            }
            
            vector<int> ans;
            
            if(hash1==hash2)
            {
                ans.push_back(1);
            }
            
            long long pL=1;
            long long pR=binExp(31,l1,mod);
            
            
            for(int i=l1;i<l2;i++)
            {
                hash2=(hash2-((txt[i-l1]-'a'+1)*pL)%mod+mod)%mod;
                hash2=(hash2+((txt[i]-'a'+1)*pR)%mod)%mod;
                hash1=(hash1*31)%mod;
                
                //cout<<i<<" "<<hash1<<" "<<hash2<<endl;
                
                if(hash1==hash2)
                   ans.push_back(i-l1+2);
            
                pL=(pL*31)%mod;
                pR=(pR*31)%mod;
                
            }
            
   
            if(ans.size()==0)
              return {-1};
            return ans;
            
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends