class Solution {
public:
    bool search(vector<int>& nums, int key) {
        
        vector<int> arr;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                arr.push_back(nums[i]);
            }
        }
        
        if(arr.size()==0 || arr.back()!=nums[nums.size()-1])
            arr.push_back(nums[nums.size()-1]);
        
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]==key)
                return true;
            else if(arr[mid]>=arr[low])
            {
                if(arr[mid]>key && arr[low]<=key)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(arr[mid]<arr[high])
            {
                if(arr[mid]<key && arr[high]>=key)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        
        return false;
        
    }
};