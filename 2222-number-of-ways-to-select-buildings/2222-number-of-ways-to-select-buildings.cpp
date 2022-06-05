class Solution {
public:
    long long numberOfWays(string s) {
        
        long long ans=0;
        
        int l=s.length();
        
        vector<int> pref_0;
        vector<int> pref_1;
        
        int ct=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='0')
            {
                ct++;
                pref_0.push_back(ct);
            }
            else
            {
                pref_0.push_back(ct);
            }
        }
        
        ct=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='1')
            {
                ct++;
                pref_1.push_back(ct);
            }
            else
            {
                pref_1.push_back(ct);
            }
        }
        
        vector<pair<long long,long long>> ct_101;
        vector<pair<long long,long long>> ct_010;
        
        for(int i=0;i<l;i++)
        {
            if(s[i]=='1')
            {
                ct_010.push_back({pref_0[i],abs(pref_0[i]-pref_0[l-1])});
            }
            else
            {
                ct_101.push_back({pref_1[i],abs(pref_1[i]-pref_1[l-1])});    
            }
        }
        
        for(auto &it:ct_010)
        {
            ans+=it.first*it.second;
            //cout<<it.first<<" "<<it.second<<endl;
        }
        
        for(auto &it:ct_101)
        {
            ans+=it.first*it.second;
            //cout<<it.first<<" "<<it.second<<endl;
        }
        
        return ans;
        
    }
};