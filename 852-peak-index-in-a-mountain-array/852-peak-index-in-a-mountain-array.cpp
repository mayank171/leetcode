class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        
        int low=0;
        int high=n-1;

        int ans=high;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            {
                ans=mid;
                break;
            }
            else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])
            {
                high=mid;
            }
            else
            {
                low=mid;
            }
        }
        
        
        return ans;
    }
};