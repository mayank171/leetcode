class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int ans=0;
        int n=nums.size();
        
        int i=-1;
        int j=-1;
        set<int> odd;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(nums[i]&1)
                    odd.insert(i);
                if(odd.size()==k)
                {
                    ans+=(*odd.begin()-j);
                }
                else if(odd.size()>k)
                {
                    odd.erase(i);
                    i--;
                    break;
                }
            }
            
            while(j<i && odd.size()>=k)
            {
                flag2=1;
                
                j++;
                if(nums[j]&1)
                    odd.erase(j);
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};