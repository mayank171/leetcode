class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int n=arr.size();
        
        int curMax=1;
        int curMin=1;
        int ans=*max_element(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            
            int temp=curMax;
            
            curMax=max(curMax*arr[i],max(arr[i]*curMin,arr[i]));
            curMin=min(temp*arr[i],min(arr[i]*curMin,arr[i]));
            ans=max(ans,max(curMax,curMin));
        }
        
        return ans;
    }
};