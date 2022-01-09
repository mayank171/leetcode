// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    private:
        vector<int> z_algo(string s)
        {
            int l=0;
            int r=0;
            int len=s.length();
            
            vector<int> z(len);
            
            for(int i=1;i<len;i++)
            {
                if(i>r)
                {
                    l=r=i;
                    while(r<len && s[r]==s[r-l])
                    {
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
                else
                {
                    int ind=i-l;
                    if(i+z[ind]<=r)
                    {
                        z[i]=z[ind];
                    }
                    else
                    {
                        l=i;
                        while(r<len && s[r]==s[r-l])
                        {
                            r++;
                        }
                        z[i]=r-l;
                        r--;
                    }
                }
            }
            
            return z;
            
        }
    public:
        vector <int> search(string pat, string txt)
        {
            string tot=pat+'$'+txt;
            vector<int> z=z_algo(tot);
            
            vector<int> ans;
            
            for(int i=0;i<z.size();i++)
            {
                if(z[i]==pat.length())
                {
                    ans.push_back(i-pat.length());
                }
                //cout<<z[i]<<" ";
            }
            
            return ans;
            
        }
     
};

// { Driver Code Starts.
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends