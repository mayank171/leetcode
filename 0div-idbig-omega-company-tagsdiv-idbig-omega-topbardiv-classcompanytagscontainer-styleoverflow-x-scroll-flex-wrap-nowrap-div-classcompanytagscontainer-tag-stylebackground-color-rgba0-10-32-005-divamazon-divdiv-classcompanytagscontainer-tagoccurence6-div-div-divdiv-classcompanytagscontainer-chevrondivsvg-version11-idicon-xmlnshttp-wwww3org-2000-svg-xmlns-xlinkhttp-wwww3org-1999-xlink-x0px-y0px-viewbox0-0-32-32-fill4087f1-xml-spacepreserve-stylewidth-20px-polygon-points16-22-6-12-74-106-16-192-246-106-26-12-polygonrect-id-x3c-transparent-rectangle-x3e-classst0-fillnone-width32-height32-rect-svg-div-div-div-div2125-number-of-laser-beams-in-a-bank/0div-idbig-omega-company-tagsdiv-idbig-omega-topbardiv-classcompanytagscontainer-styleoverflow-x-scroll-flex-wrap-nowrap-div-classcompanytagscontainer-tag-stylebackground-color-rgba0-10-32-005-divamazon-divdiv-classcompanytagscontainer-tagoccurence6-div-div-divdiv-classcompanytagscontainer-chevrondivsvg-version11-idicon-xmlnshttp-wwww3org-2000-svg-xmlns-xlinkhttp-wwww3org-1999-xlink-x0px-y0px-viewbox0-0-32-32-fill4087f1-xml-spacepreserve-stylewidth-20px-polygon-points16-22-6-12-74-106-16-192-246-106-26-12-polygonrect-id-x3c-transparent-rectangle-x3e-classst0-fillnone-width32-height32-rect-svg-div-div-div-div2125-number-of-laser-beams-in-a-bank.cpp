class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n=bank.size();
        
        int first=-1;
        int second=-1;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                    ct++;
            }
            
            if(first==-1 && ct!=0)
                first=ct;
            else if(second==-1 && ct!=0)
                second=ct;
            
            if(first!=-1 && second!=-1)
            {
                ans+=(first*second);
                first=second;
                second=-1;
            }
            
           // cout<<first<<" "<<second<<endl;
        }
        
        return ans;
    }
};