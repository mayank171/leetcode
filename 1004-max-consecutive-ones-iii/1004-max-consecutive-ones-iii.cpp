class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(k==0)
        {
            int ct=0;
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==1)
                    ct++;
                else if(nums[i]==0)
                {
                    maxi=max(maxi,ct);
                    ct=0;
                } 
            }
            
            maxi=max(maxi,ct);
            
            return maxi;
        }
        
        int i=-1;
        int j=-1;
        int maxi=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
        
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(nums[i]==0)
                {
                    if(k==0)
                    {
                        i--;
                        break;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            
            while(j<i)
            {
                flag2=1;
                maxi=max(maxi,i-j);
                j++;
                if(nums[j]==0)
                {
                    k++;
                    break;
                }
            }
            
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return maxi;
        
    }
};