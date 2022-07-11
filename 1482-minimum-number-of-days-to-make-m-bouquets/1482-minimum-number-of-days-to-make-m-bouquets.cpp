class Solution {
private:
    int blackBox(vector<int> &bloomDay,int n,int mid,int k)
    {
        int ct=0;
        int ind=0;
        int ctr=0;
        for(int i=0;i<n;i++)
        {
            if(ind<k && bloomDay[i]<=mid)
            {
                ind++;
            }
            else if(ind==k) 
            {
                ct++;
                ind=0;
                i--;
            }
            else if(ind!=0)
            {
                ind=0;
                
            }
        }
        if(ind==k)
        {
            ct++;
        }
    //    cout<<ct<<endl;
        
        return ct;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n=bloomDay.size();
        
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int ki=blackBox(bloomDay,n,mid,k);
           // cout<<mid<<" "<<ki<<endl;
            
            if(ki>=m)
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