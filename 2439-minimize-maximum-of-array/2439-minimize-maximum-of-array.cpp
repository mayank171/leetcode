class Solution {
public:

    // int blackBox(vector<int> &nums,int n,int mid)
    // {
    //     vector<long long> pref(n);
    //     pref[0]=nums[0];

    //     if(pref[0]>mid*1)
    //        return 0;

    //     for(int i=1;i<n;i++)
    //     {
    //         pref[i]=pref[i-1]+nums[i];
    //         if(pref[i]>mid*1ll*(i+1))
    //            return 0;
    //     }

    //     return 1;
    // }

    int minimizeArrayValue(vector<int>& nums) {
        
        int n=nums.size();

        // int low=*min_element(nums.begin(),nums.end());
        // int high=*max_element(nums.begin(),nums.end());
        // int ans=high;

        // while(low<=high)
        // {
        //     int mid=low+(high-low)/2;

        //     int k=blackBox(nums,n,mid);
        //     //cout<<mid<<" "<<k<<endl;

        //     if(k)
        //     {
        //         ans=min(ans,mid);
        //         high=mid-1;
        //     }
        //     else
        //     {
        //         low=mid+1;
        //     }
        // }

        // return ans;

        int mini=nums[0];
        long long sum=nums[0];

        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            int x=ceil(sum/(double)(i+1));

            if(x>=mini)
            {
                mini=x;
            }
        }

        return mini;
    }
};


















