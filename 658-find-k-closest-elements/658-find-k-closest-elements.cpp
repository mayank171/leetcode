class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        
        int low=0;
        int high=n-k;
        
        int ans=INT_MAX;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(x-arr[mid] > arr[mid+k]-x)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        
        vector<int> res;
        
        int ind=low;
        
        while(k--)
        {
            res.push_back(arr[ind]);
            ind++;
        }

        //sort(res.begin(),res.end());
        
        return res;
        
        
    }
};