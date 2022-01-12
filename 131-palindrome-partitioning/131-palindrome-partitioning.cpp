class Solution {
public:
    
//     bool isPalindrome(string str,int start,int end)
//     {
        
        
//         for(int i=start,j=end;i<=j;i++,j--)
//         {
//             if(str[i]!=str[j])
//             {
//                return false;
//             }
//         }
        
//         return true;
//     }
    
//     void f1(int ind, string s, vector<string> &temp, vector<vector<string>>& ans)
//     {
//         if(ind==s.length())
//         {
//             ans.push_back(temp);
//             return ;
//         }
        
//         for(int i=ind;i<s.length();i++)
//         {
//             if(isPalindrome(s,ind,i))
//             {
//                 temp.push_back(s.substr(ind,i-ind+1));
//                 f1(i+1,s,temp,ans);
//                 temp.pop_back();
//             }
//         }
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool palindrome(string s)
    {
        int l=s.length();
        
        for(int i=0,j=l-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    
    
    
    
    
    
    void f1(string s,int n,int ind, vector<string> &temp,vector<vector<string>> &ans)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<n;i++)
        {
            string str=s.substr(ind,i-ind+1);
           // cout<<str<<endl;
            
            if(palindrome(str))
            {
                temp.push_back(str);
                f1(s,n,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    
    
    
    vector<vector<string>> partition(string s) {
        
        
        
        
        int l=s.length();
        
        int ind=0;
        
        vector<string> temp;
        
        vector<vector<string>> ans;
        
        f1(s,l,ind,temp,ans);
        
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int ind=0;
        
        
//         vector<string> temp;
 
//         vector<vector<string>> ans;
        
//         f1(0,s,temp,ans);
        
//         return ans;
    }
};