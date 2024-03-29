class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
//                 |
//         1 3 2 3 3 
//             |
        
//         1           -
//         1 3         -
//         1 3 2       -
//         1 3 2 3
//         1 3 2 3 3
//         3           -
//         3 2         -
//         3 2 3 
//         3 2 3 3 
//         2           -    
//         2 3         -
//         2 3 3
//         3           -
//         3 3 
//         3
                    
        int i=-1;
        int j=-1;
        int n=nums.size();
        
        int maxi=*max_element(nums.begin(),nums.end());
        
        
        int ct=0;
        long long ans=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(nums[i]==maxi)
                    ct++;
                
                if(ct==k)
                    break;
            }
            
            while(j<i && ct==k)
            {
                flag2=1;
                ans+=(i-j)-1;
                j++;
                if(nums[j]==maxi)
                    ct--;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        cout<<ans<<endl;
        
//         if(ans==0)
//             return 0;
        
        ans+=((i-j)*1ll*(i-j+1))/2;
        
        long long x=(n*1ll*(n+1))/2;
        
        return x-ans;
    }
};