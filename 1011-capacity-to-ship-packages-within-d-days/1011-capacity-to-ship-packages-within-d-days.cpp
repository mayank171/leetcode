class Solution {

private:
    int blackBox(vector<int> &arr,int mid,int n)
    {
        int sum=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
                return INT_MAX;
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                ct++;
                sum=0;
                i--;
            }
        }
    return ct+1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum=accumulate(weights.begin(),weights.end(),0);
        
        int n=weights.size();
        
        int low=1;
        int high=sum;
        
        while(low<high)
        {
            int mid=(low+high)/2;
          
            if(blackBox(weights,mid,n)>days)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
      
        return min(low,high);
        
    }
};