class Solution {
public:
     bool palindrome(string s)
    {
        int l=s.length();
        
        for(int i=0,j=l-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(auto &it:words)
        {
            if(palindrome(it))
            {
                return it;
            }
        }
        
        return "";
        
        
    }
};