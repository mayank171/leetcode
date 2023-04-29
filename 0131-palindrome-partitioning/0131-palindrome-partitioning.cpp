class Solution {
public:
    
    bool isPalindrome(string &s)
    {
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            if(s[i]!=s[l-i-1])
                return false;
        }
        return true;
    }
    
    void solve(string &s,int n,vector<vector<string>> &ans,vector<string> &temp,int ind)
    {
       // cout<<ind<<endl;
        if(ind==n)
        {
            // for(auto &it:temp)
            //     cout<<it<<" ";
            // cout<<endl;
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            string str=s.substr(ind,i-ind+1);
            //cout<<str<<endl;
            if(isPalindrome(str))
            {
                temp.push_back(str);
                solve(s,n,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s,n,ans,temp,0);
        
        return ans;
    }
};