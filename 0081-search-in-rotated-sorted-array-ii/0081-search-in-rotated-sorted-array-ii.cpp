class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        vector<int> arr;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                arr.push_back(nums[i]);
            }
        }
        
        if(nums[nums.size()-1]!=nums[0])
            arr.push_back(nums[nums.size()-1]);
        
        if(arr.size()==0)
        {
            arr.push_back(nums[0]);
            if(arr[0]==target)
                return true;
            return false;
        }
        
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
          //  cout<<low<<" "<<high<<endl;
            
            if(arr[mid]==target)
            {
                return true;
            }
            else if(arr[mid]>=arr[low] && arr[high]<=arr[mid])
            {
                if(target>=arr[low] && target<=arr[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(arr[mid]>=arr[low] && arr[high]>=arr[mid])
            {
                if(target>=arr[low] && target<=arr[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(arr[mid]<=arr[low] && arr[high]>=arr[mid])
            {
                if(target>=arr[mid] && target<=arr[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        
        return false;
    }
};