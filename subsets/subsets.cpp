class Solution {
private:
    
    vector<vector<int>> find_subset(vector<int> &nums)
    {
        int size=nums.size();
        
        int n=(1<<size);
        
        vector<vector<int>> ans;
        
        
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<size;j++)
            {
                if(i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        ans=find_subset(nums);
        
        return ans;
    }
};