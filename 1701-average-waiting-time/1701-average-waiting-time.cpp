class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n=customers.size();
        
        double ans=customers[0][1];
        double t=customers[0][0]+customers[0][1];
     //   cout<<ans<<" "<<t<<endl;
        
        for(int i=1;i<n;i++)
        {
            int at=customers[i][0];
            int time=customers[i][1];
            
            if(t>at)
            {
                //ans+=((ans-at)+time);
                t+=customers[i][1];
                ans+=(t-customers[i][0]);
            }
            else
            {
                //ans+=time;
                t=customers[i][0]+customers[i][1];
                ans+=(t-customers[i][0]);
            }
            
          //  cout<<ans<<" "<<t<<endl;
        }
        
        double res=(ans*1.0)/n;
        
        return res;
    }
};