class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();

        int el=-1;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(el==-1)
            {
                el=nums[i];
                ct=1;
            }
            else if(el==nums[i])
            {
                ct++;
            }
            else
            {
                ct--;

                if(ct==0)
                {
                    el=-1;
    
                }
            }
        }

        ct=0;
        for(int i=0;i<n;i++)
        {
            if(el==nums[i])
               ct++;
        }

        if(ct>floor(n/(float)2))
           return el;
        return -1;
    }
};