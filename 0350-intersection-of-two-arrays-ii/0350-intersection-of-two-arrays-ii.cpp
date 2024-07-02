class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        map<int,int> mp1;
        map<int,int> mp2;
        
        for(int i=0;i<n1;i++)
        {
            mp1[nums1[i]]++;
        }
        
        for(int i=0;i<n2;i++)
        {
            mp2[nums2[i]]++;
        }
        
        vector<int> ans;
        
        for(auto &it:mp1)
        {
            int x=it.first;
            if(mp2.find(x)!=mp2.end())
            {
                int freq=min(it.second,mp2[x]);
                
                while(freq--)
                {
                    ans.push_back(x);
                }
            }
        }
        
        return ans;
    }
};