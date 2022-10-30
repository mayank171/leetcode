class Solution {
public:
    
    bool solve(long long n,int target)
    {
        long long sum=0;
        long long ct=0;
        while(n)
        {
            sum+=n%10;
            n=n/10;
            ct++;
        }
        
        if(sum<=target)
            return true;
        return false;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        
        long long sum=0;
        
        long long nn=n;
        
        long long ct=0;
        
        while(nn)
        {
            sum+=nn%10;
            nn=nn/10;
            ct++;
        }
        
        if(sum<=target)
            return 0;
        
        long long res=0;
        string temp="";
        for(int i=ct-1;i>=0;i--)
        {
            if(solve(n,target))
                break;
            
            long long x=n%10;
            x=10-x;
            
            if(x!=10)
            {
                res=10*res+x;
                n=n/10+1;
                temp+=(x+'0');
            }
            else
            {
                res*=10;
                n=n/10;
                temp+='0';
            }   
            
            cout<<x<<" "<<n<<" "<<res<<endl;
        }
        
        cout<<res<<" "<<temp<<endl;
        
        reverse(temp.begin(),temp.end());
        
        long long k=0;
        int l=temp.length();
        int j=0;
        
        while(j<l)
        {
            k=k*10+(temp[j]-'0');
            j++;
        }
        
        return k;
    }
};