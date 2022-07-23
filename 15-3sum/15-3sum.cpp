class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
       
        int n=arr.size();
        
        int K=0;
        
        vector<vector<int>> ans;
        
        sort(arr.begin(),arr.end());
    
        for(int i=0;i<n;i++)
        {
            if(i==0 || (i>0 && arr[i]!=arr[i-1]))
            {
                int low=i+1;
                int high=n-1;
                int sum=K-arr[i];
                
                while(low<high)
                {
                    if(arr[low]+arr[high]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(arr[low]);
                        temp.push_back(arr[high]);
                        temp.push_back(arr[i]);
                        ans.push_back(temp);
                        
                        while(low<high && arr[low]==arr[low+1])  low++;
                        while(low<high && arr[high]==arr[high-1])  high--;
                        low++;
                        high--;
                    }
                    else if(arr[low]+arr[high]<sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        
        return ans;
        
    }
};