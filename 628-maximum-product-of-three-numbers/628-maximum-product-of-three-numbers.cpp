class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        
        int n=nums.size();
        
//         sort(nums.begin(),nums.end());
        
//         return nums[n-1]*nums[n-2]*nums[n-3];
        
        int max1=-1e8;
        int max2=-1e8;
        int max3=-1e8;
        int min1=1e8;
        int min2=1e8;
        int min3=1e8;
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max1)
            {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2)
            {
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i]>max3)
            {
                max3=nums[i];
            }
            
            if(nums[i]<min1)
            {
                min3=min2;
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2)
            {
                min3=min2;
                min2=nums[i];
            }
            else if(nums[i]<min3)
            {
                min3=nums[i];
            }
            
            
        }
        
        cout<<max1<<" "<<max2<<" "<<max3<<endl;
        cout<<min1<<" "<<min2<<" "<<min3<<endl;
        
        vector<int> prod;
        prod.push_back(max1*max2*max3);
        prod.push_back(min1*min2*min3);
        prod.push_back(min1*min2*max1);
        
        
        return *max_element(prod.begin(),prod.end());
        
        
        
    }
};