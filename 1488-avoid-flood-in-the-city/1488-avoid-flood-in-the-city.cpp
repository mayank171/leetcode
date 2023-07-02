class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        
        int n=rain.size();
        vector<int> ans(n);
        
        map<int,int> mp;
        int ct=0;
        set<int> pos;
        for(int i=0;i<n;i++)
        {
            if(rain[i]>0)
            {
                if(mp.find(rain[i])==mp.end())
                {
                    mp[rain[i]]=i;
                    ans[i]=-1;
                }
                else 
                {
                    if(ct>0)
                    {
                        int ind1=mp[rain[i]];
                        mp.erase(rain[i]);
                        ct--;
                        
                        auto it=pos.lower_bound(ind1);
                        if(it==pos.end())
                            return {};
                        else
                        {
                            int ind=*it;
                            pos.erase(*it);
                            ans[ind]=rain[i];
                            ans[i]=-1;
                            mp[rain[i]]=i;
                        }
                    }
                    else
                    {
                        return {};
                    }
                }
            }
            else
            {
                ct++;
                pos.insert(i);
            }
        }
        
        while(pos.size())
        {
            int ind=*pos.begin();
            pos.erase(*pos.begin());
            ans[ind]=1;
        }
        
        return ans;
    }
};