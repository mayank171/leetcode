class Solution {
private:
    
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second>b.second)
        {
            return true;
        }
        return false;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        vector<pair<int,int>> vp;
        
        for(auto &it:mp)
        {
            vp.push_back({it.first,it.second});
        }
        
        sort(vp.begin(),vp.end(),comp);
        
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(vp[i].first);
        }
        
        return ans;
        
    }
};