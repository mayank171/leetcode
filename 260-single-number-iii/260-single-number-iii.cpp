class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        int x=0;
       for(auto &it:nums)
       {
           x^=it;
       }
        
        int ind=0;
        for(int i=0;i<=31;i++)
        {
            if(x&(1<<i))
            {
                ind=i;
                break;
            }
        }
        
        cout<<ind<<endl;
        
        int xor_a=0;
        int xor_b=0;
        
        for(auto &it:nums)
        {
             if(it&(1<<ind))
                 xor_a^=it;
             else
                 xor_b^=it;
        }
        
        cout<<xor_a<<" "<<xor_b<<endl;
        
        vector<int> ans;
        ans.push_back(xor_a);
        ans.push_back(xor_b);
        
        
        return ans;
        
        
        
//         sort(nums.begin(),nums.end());
        
//         int l=nums.size();
        
//         vector<int> ans;
        
//         for(int i=0;i<l;i++)
//         {
            
//             if(i==l-1)
//             {
//                 ans.push_back(nums[i]);
//                 break;
//             }
            
//             if(nums[i]==nums[i+1])
//             {
//                 i++;
//             }
//             else 
//             {
//                 ans.push_back(nums[i]);
//             }
            
//             if(ans.size()==2)
//             {
//                 break;
//             }
            
//         }
        
//         return ans;
        
    }
};