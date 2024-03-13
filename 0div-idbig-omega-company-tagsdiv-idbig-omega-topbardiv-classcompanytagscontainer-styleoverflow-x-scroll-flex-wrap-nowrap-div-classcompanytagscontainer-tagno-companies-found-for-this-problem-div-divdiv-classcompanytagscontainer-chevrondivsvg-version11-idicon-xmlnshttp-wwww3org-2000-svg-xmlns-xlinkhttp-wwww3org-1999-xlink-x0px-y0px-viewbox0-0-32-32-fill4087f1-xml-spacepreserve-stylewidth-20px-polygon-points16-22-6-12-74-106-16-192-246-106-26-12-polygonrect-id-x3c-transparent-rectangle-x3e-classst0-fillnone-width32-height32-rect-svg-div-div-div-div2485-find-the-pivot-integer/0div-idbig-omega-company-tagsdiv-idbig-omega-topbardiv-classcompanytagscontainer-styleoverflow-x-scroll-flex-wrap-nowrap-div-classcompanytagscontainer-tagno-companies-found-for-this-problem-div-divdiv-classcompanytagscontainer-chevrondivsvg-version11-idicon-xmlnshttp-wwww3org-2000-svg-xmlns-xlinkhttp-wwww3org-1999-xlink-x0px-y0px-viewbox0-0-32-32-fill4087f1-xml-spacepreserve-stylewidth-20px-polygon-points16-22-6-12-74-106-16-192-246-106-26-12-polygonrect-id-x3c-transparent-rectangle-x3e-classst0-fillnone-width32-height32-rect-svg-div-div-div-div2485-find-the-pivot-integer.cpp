class Solution {
public:
    int pivotInteger(int n) {
        
        if(n==1)
            return 1;
        vector<int> v1(n+1);
        v1[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            v1[i]=i+v1[i-1];
        }
        
        vector<int> v2(n+1);
        v2[n]=n;
        
        for(int i=n-1;i>=1;i--)
        {
            v2[i]=i+v2[i+1];
        }
        
      
        
        
        for(int i=2;i<n;i++)
        {
            if(v1[i]==v2[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};