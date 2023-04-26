class Solution {
public:
    int trap(vector<int>& v) {
        
        int n=v.size();
//         vector<int> prefix(n);
//         prefix[0]=v[0];
        
//         for(int i=1;i<n;i++)
//         {
//             prefix[i]=max(v[i],prefix[i-1]);
//         }
        
//         vector<int> suffix(n);
//         suffix[n-1]=v[n-1];
        
//         for(int i=n-2;i>=0;i--)
//         {
//             suffix[i]=max(v[i],suffix[i+1]);
//         }
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             ans+=(min(prefix[i],suffix[i])-v[i]);
//         }
        
//         return ans;
        
        int l=0;
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        
        while(l<r)
        {
            if(v[l]<v[r])
            {
                if(v[l]>=lmax)
                {
                    lmax=v[l];
                }
                else
                {
                    ans+=lmax-v[l];
                }
                l++;
            }
            else
            {
                if(v[r]>=rmax)
                {
                    rmax=v[r];
                }
                else
                {
                    ans+=rmax-v[r];
                }
                r--;    
            }
        }
        
        return ans;
        
    }
};
















