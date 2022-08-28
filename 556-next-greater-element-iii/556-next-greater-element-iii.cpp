class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s=to_string(n);
        
        int l=s.length();
        
        
        int ind=l-1;
        
        for(int i=ind-1;i>=0;i--)
        {
            if(s[i]<s[ind])
            {
                break;
            }
            else
            {
                ind=i;
            }
        }
        
        if(ind==0)
        {
            return -1;
        }
        
        //cout<<ind<<endl;
        
        int mini=1e8;
        int ind1=-1;
        for(int i=ind;i<l;i++)
        {
            if(s[i]>s[ind-1] && abs((s[i]-'0')-(s[ind-1]-'0'))<mini)
            {
                ind1=i;
                mini=abs((s[i]-'0')-(s[ind-1]));
            }
        }
        
        swap(s[ind-1],s[ind1]);
        
        sort(s.begin()+ind,s.end());
        
        int k=0;
        long long ki=0;
        int j=0;
        while(j<l)
        {
            ki=ki*10+(s[j]-'0');
            if(ki>2147483647)
                return -1;
            k=k*10+(s[j]-'0');
            j++;
        }
        
        return k;
        
    }
};