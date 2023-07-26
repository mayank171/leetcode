class Solution {
public:
    
    bool isPalindrome(string &s)
    {
        for(int i=0,j=s.length()-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        
        return true;
    }
    
    void solve(string &s,int ind,int n,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<n;i++)
        {
            string str=s.substr(ind,i-ind+1);
            if(isPalindrome(str))
            {
                temp.push_back(str);
                solve(s,i+1,n,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.length();
        
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,n,ans,temp);
        
        return ans;
    }
};