class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n=s.length();
        
        if(maxCost==0)
        {
            int ans=0;
            for(int i=0;i<n;i++)
            {
                int j=i;
                int ct=0;
                while(j<n && s[j]==t[j])
                {
                    ct++;
                    j++;
                }
                ans=max(ans,ct);
                i=j;
            }
            
            return ans;
        }
        
        int i=-1;
        int j=-1;
        
        int ans=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1 && maxCost>=0)
            {
                flag1=1;
                i++;
                maxCost-=abs(s[i]-t[i]);
                if(maxCost>=0)
                {
             //       cout<<i-j<<endl;
                   // i++;
                    ans=max(ans,i-j);
                }
                else
                {
               //     cout<<"o"<<endl;
                    break;
                }
            }
            
            while(j<=i && maxCost<0)
            {
                flag2=1;
                j++;
           //     cout<<i-j<<","<<endl;
                maxCost+=abs(s[j]-t[j]);
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};