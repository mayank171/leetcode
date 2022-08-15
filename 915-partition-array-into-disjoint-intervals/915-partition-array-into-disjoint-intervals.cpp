class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> maxLeft(n+1);
        maxLeft[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            maxLeft[i]=max(nums[i],maxLeft[i-1]);
        }
        
        vector<int> minRight(n+1);
        minRight[n]=1e8;
        
        for(int i=n-1;i>=0;i--)
        {
            minRight[i]=min(nums[i],minRight[i+1]);
        }
        
        int ctr=0;
        
//         for(auto &it:maxLeft)
//             cout<<it<<" ";
//         cout<<endl;
        
//         for(auto &it:minRight)
//             cout<<it<<" ";
//         cout<<endl;
        
        
        ctr=1;
        for(int i=0;i<n-1;i++)
        {
            if(maxLeft[i]>minRight[i+1])
            {
                ctr++;
            }
            else
                break;
        }
        
        return ctr;
        
    }
};