class Solution {
private:
    long long blackBox(vector<int> &piles,int n,int mid)
    {
        long long ct=0;
        for(int i=0;i<n;i++)
        {
            int x=ceil(piles[i]/(mid*1.0));
           // cout<<x<<" ";
            ct+=x;
        }
       // cout<<endl;
        return ct;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            long long k=blackBox(piles,n,mid);
            
            if(k<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};