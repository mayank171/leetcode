class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> st1;
        set<int> st2;
        
        for(int i=0;i<nums1.size();i++)
        {
            st1.insert(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            st2.insert(nums2[i]);
        }
        
        vector<vector<int>> ans;
        
        set<int> temp;
        for(int i=0;i<nums1.size();i++)
        {
            if(st2.find(nums1[i])==st2.end())
                temp.insert(nums1[i]);
        }
        
        vector<int> a;
        for(auto &it:temp)
            a.push_back(it);
        
        ans.push_back(a);
        
        
        vector<int> b;
        set<int> temp2;
        for(int i=0;i<nums2.size();i++)
        {
            if(st1.find(nums2[i])==st1.end())
                temp2.insert(nums2[i]);
        }
        
        for(auto &it:temp2)
            b.push_back(it);
        
        ans.push_back(b);
        
        return ans;
        
    }
};