class Solution {
public:
    long long appealSum(string s) {
        
        long long n=s.length();
        
        long long ans=0;
        
        long long total=(n*(n+1))/2;
        
        vector<long long> v(26,0);
        
        for( char ch='a';ch<='z';ch++)
        {
            int i=-1;
            int j=-1;
            long long ct=0;
            while(true)
            {
                int flag1=0;
                int flag2=0;
                while(i<n-1)
                {
                    flag1=1;
                    i++;
                    if(s[i]==ch)
                        break;
                    ct+=(i-j);
                }
                
                while(j<i)
                {
                    flag2=1;
                    j++;
                }
                
                if(flag1==0 && flag2==0)
                    break;
            }
            
            v[ch-'a']=(total-ct);
        }
        
        for(int i=0;i<26;i++)
        {
            ans+=v[i];
        }
        
        return ans;
        
    }
};