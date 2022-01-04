// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            
            int l=txt.length();
            int pl=pat.length();
            
            int p=0;
            
            for(int i=0;i<l;i++)
            {
                if(txt[i]==pat[p])
                {
                    p++;
                }
                else if(p==pl)
                {
                    ans.push_back(i-pl+1);
                    p=0;
                    i-=pl;
                }
                else
                {
                    if(p>0)
                      i-=p;
                    p=0;
                    
                }
            }
            if(p==pl)
            {
                ans.push_back(l-pl+1);
            }
            
            if(ans.size()==0)
            {
                ans.push_back(-1);
                
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