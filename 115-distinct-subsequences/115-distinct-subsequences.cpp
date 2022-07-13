class Solution {
public:
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        vector<int> front(m+1,0);
        front[0]=1;
        
        for(int i=1;i<n+1;i++)
        {
//             vector<int> cur(m+1,0);
//             cur[0]=1;
            for(int j=m;j>0;j--)
            {
                int l=0;int r=0;
                if(s[i-1]==t[j-1])
                    l=front[j-1];
                r=front[j];
                front[j]=(l+r)%mod;
            }
           // front=cur;
        }
        
        return front[m];
    
        
    }
};