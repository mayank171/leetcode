// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    private:
    void check(string &str,string &ans,int k,int idx)
    {
        
        ans = max(ans, str);
        if(k == 0 || str[idx] == '\0')
            return;
        for(int i=idx+1; str[i] != '\0'; i++){
            if(str[i] <= str[idx])
                continue;
            swap(str[i], str[idx]);
            check(str, ans, k-1, idx+1);
            swap(str[i], str[idx]);
        }
        check(str, ans, k, idx+1);
        
        
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        set<string> st;
        int l=str.length();
        string ans=str;
        check(str,ans,k,0);
        
        // for(auto &it:st)
        // {
        //     cout<<it<<endl;
        // }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends