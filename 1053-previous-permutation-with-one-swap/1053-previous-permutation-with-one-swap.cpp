class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        int n=arr.size();
        
        int ind=-1;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]<arr[i-1])
            {
                ind=i-1;
                break;
            }
        }
        
        if(ind==-1)
            return arr;
        
        int min_diff=1e8;
        int index=ind+1;
        
        for(int i=ind+1;i<n;i++)
        {
            if(arr[i]<arr[ind] && arr[ind]-arr[i]<min_diff)
            {
                min_diff=arr[ind]-arr[i];
                index=i;
            }
        }
        
        swap(arr[ind],arr[index]);
        
        return arr;
        
    }
};