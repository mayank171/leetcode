class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n=bank.size();
        int m=bank[0].size();
        
        vector<int> ct;
        
        for(int i=0;i<n;i++)
        {
            ct.push_back(count(bank[i].begin(),bank[i].end(),'1'));
        }
        
        
        int ans=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(ct[i]==0)
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(ct[i]==0 || ct[j]==0)
                {
                    continue;
                }
                else
                {
                    if(abs(i-j)>1)
                    {
                        int flag=0;
                        for(int k=i+1;k<j;k++)
                        {
                            if(ct[k]>0)
                            {
                                flag=1;
                                break;
                            }    
                        }
                        if(flag==1)
                        {
                            continue;
                        }
                        else
                        {
                            ans+=ct[i]*ct[j];
                        }
                    }
                    else
                    {
                        ans+=ct[i]*ct[j];
                    }
                }
            }
        }
        
        return ans;
        
    }
};