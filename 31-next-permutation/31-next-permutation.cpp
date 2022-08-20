class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int flag=0;
        int n=arr.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0)
        {
            sort(arr.begin(),arr.end());
            return ;
        }
        
        int ind=n-1;
        
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                ind=i-1;
                break;
            }
        }
        
        int min_diff=1e8;
        int index=ind+1;
        for(int i=ind+1;i<n;i++)
        {
            if(arr[i]>arr[ind] && arr[i]-arr[ind]<min_diff)
            {
                min_diff=arr[i]-arr[ind];
                index=i;
            }
        }
        
        swap(arr[ind],arr[index]);
        
        sort(arr.begin()+ind+1,arr.end());
        
        return;
        
    }
};