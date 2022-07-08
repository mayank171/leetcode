class Solution {
private:
    double blackBox(vector<int> &dist,int n,double hour,int mid)
    {
        double ct=0.0;
        
        for(int i=0;i<n-1;i++)
        {
            double x=ceil(dist[i]/(double)mid);
            ct+=x;
            
           // cout<<x<<" "<<endl;
        }
        
        ct+=(dist[n-1]/(double)mid);
        
        return ct;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n=dist.size();
        
        int h=1e9;
        int l=1;
        
        int ans=1e9+7;
        
        while(l<=h)
        {
           // cout<<l<<" "<<h<<endl;
            int mid=l+(h-l)/2;
            
            double k=blackBox(dist,n,hour,mid);
           // cout<<k<<endl;
            
            if(k<=hour)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
     
        if(ans==1e9+7)
            return -1;
        
        return ans;
        
    }
};