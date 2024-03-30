class Solution {
public:

    int solve(vector<int> &nums,int n)
    {
        int i=-1;
        int j=-1;

        map<int,int> mp;
        int ans=0;

        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                mp[nums[i]]++;
                if(mp.size()>1)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                       mp.erase(nums[i]);
                    i--;
                    break;
                }
            }

            while(j<i && mp.size()==1)
            {
                flag2=1;
                ans+=(i-j);
                j++;
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                   mp.erase(nums[j]);
            }

            if(flag1==0 && flag2==0)
               break;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n=nums.size();

        if(k==1)
          return solve(nums,n);

        int j=-1;

        map<int,int> mp1;
        map<int,int> mp2;
        int is=-1;
        int ib=-1;
        int ans=0;

        while(true)
        {
            int flag1=0;
            int flag2=0;
            int flag3=0;

            
            while(ib<n-1)
            {
                ib++;
                if(mp2.size()<=k)
                {
                    flag2=1;
                    mp2[nums[ib]]++;
                }
                   
                
                if(mp2.size()>k)
                {
                    flag2=0;
                    mp2[nums[ib]]--;
                    if(mp2[nums[ib]]==0)
                       mp2.erase(nums[ib]);
                    ib--;
                    break;
                }
            }

            while(is<ib)
            {
                is++;
                if(mp1.size()<=k-1)
                {
                    flag1=1;
                    mp1[nums[is]]++;
                }   
                
                if(mp1.size()>k-1)
                {
                    flag1=0;
                    mp1[nums[is]]--;
                    if(mp1[nums[is]]==0)
                       mp1.erase(nums[is]);
                    is--;
                    break;
                }
            }

            
            while( j<is && mp1.size()==k-1 && mp2.size()==k)
            {
                flag3=1;
                ans+=(ib-is);
                j++;
                mp1[nums[j]]--;
                if(mp1[nums[j]]==0)
                   mp1.erase(nums[j]);
                mp2[nums[j]]--;
                if(mp2[nums[j]]==0)
                   mp2.erase(nums[j]);
            }

            if(flag2==0 && flag3==0 && flag1==0)
               break;
            
        }

        return ans;
    }
};