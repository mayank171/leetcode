class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> m;
        
        int N=nums.size();
        
        for(int i=0;i<N;i++)
        {
            m[nums[i]]++;
        }
        
        for(auto it:m)
        {
            if(it.second==1)
            {
                return it.first;
            }
        }
        return 0;
    }
};