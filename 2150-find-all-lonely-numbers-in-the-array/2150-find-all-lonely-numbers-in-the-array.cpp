class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        map<int,int> mp;
        vector<int> ans;
        
        int size=nums.size();
        
        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto &it:mp)
        {
            if(it.second==1)
            {
                int x=it.first;
                auto it1=mp.find(x-1);
                auto it2=mp.find(x+1);
                
                if(it1==mp.end() && it2==mp.end())
                {
                    ans.push_back(x);
                }
            }
        }
        
        return ans;
        
    }
};