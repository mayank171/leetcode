class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
//         int n=arr.size();
        
//         int close=0;
        
//         stable_sort(arr.begin(),arr.end(),[x](const auto a,const auto b){
//             return abs(a-x)<abs(b-x);
//         });
        
        
//         arr.resize(k);
        
        
//         sort(arr.begin(),arr.end());
//         return arr;
        
        
        int n=arr.size();
        int l=0;
        int r=n-1;
        
        while(r-l>=k)
        {
            if(x-arr[l]<=arr[r]-x)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        
        vector<int> res;
        
        while(k--)
        {
            res.push_back(arr[l]);
            l++;
        }
        
        return res;
        
        
//         int n=arr.size();
        
//         int low=0;
//         int high=n-k;
        
//         int ans=INT_MAX;
        
//         while(low<high)
//         {
//             int mid=low+(high-low)/2;
            
//             if(x-arr[mid] > arr[mid+k]-x)
//             {
//                 low=mid+1;
//             }
//             else
//             {
//                 high=mid;
//             }
//         }
        
//         vector<int> res;
        
//         int ind=low;
        
//         while(k--)
//         {
//             res.push_back(arr[ind]);
//             ind++;
//         }

        
        
//         return res;
        
        
    }
};