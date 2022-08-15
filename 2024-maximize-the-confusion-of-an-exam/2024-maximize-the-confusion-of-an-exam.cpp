class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        int n=s.length();
        int i=-1;
        int j=-1;
        int ans1=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(s[i]=='F')
                {
                    if(k==0)
                    {
                        i--;
                        break;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            
            while(j<i)
            {
                flag2=1;
                ans1=max(ans1,i-j);
                j++;
                if(s[j]=='F')
                {
                    k++;
                    break;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        i=-1;
        j=-1;
        int ans2=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(s[i]=='T')
                {
                    if(k==0)
                    {
                        i--;
                        break;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            
            while(j<i)
            {
                flag2=1;
                ans2=max(ans2,i-j);
                j++;
                if(s[j]=='T')
                {
                    k++;
                    break;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return max(ans1,ans2);
        
    }
};