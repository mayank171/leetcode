class Solution {
public:
    bool validPalindrome(string s) {
        
        int l=s.length();
         
        int ind1=-1;
        int ind2=-1;
         
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-i-1])
            {
                ind1=i;
                ind2=l-i-1;
                break;
            }
        }
        
        if(ind1==-1 && ind2==-1)
            return true;
        
        cout<<ind1<<" "<<ind2<<endl;
        
        bool flag1=true;
        bool flag2=true;
        
        for(int i=ind1+1,j=ind2;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag1=false;
                break;
            }
        }
        
        for(int i=ind1,j=ind2-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag2=false;
                break;
            }
        }
        
        
        return flag1|flag2;
        
        
        
    }
};