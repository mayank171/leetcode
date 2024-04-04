class Solution {
public:
    int maxDepth(string s) {
        
        int n=s.length();
        int ans=0;
        int cur=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                cur++;
            else if(s[i]==')')
                cur--;
            ans=max(ans,cur);
        }
        
        return ans;
    }
};