class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int ans=0;
        
        int l1=min(s.length(),t.length());
        
        for(int i=0;i<l1;i++)
        {
            ans^=((s[i]-'a')^(t[i]-'a'));
        }
        
        ans^=(t[t.length()-1]-'a');
        
        return ans+'a';
    }
};