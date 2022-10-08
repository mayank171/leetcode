class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int ans=arr[n-1]-arr[0];
        
        for(int i=1;i<n;i++)
        {
            int maxi=max(arr[i-1]+k,arr[n-1]-k);
            int mini=min(arr[0]+k,arr[i]-k);
            
            ans=min(ans,maxi-mini);
        }
        
        return ans;
        
    }
};