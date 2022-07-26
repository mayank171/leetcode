class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n==0)
            return;
        
        int i=0;
        
        while(i<m)
        {
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i],nums2[0]);
                
                int ind=0;
                
                for(int k=1;k<n;k++)
                {
                    if(nums2[k]<nums2[ind])
                    {
                        swap(nums2[ind],nums2[k]);
                        ind=k;
                    }
                    else
                        break;
                }
            }
            
            i++;
        }
        
        for(int i=0;i<n;i++)
        {
            nums1[i+m]=nums2[i];
        }
        
    }
};