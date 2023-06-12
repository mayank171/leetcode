class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0)
        {
            return {};
        }
        
        vector<string> ans;
        int start=0;
        int end=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+1==nums[i+1])
            {
                end=i+1;
            }
            else
            {
                if(start!=end)
                {
                    string x="";
                    x=to_string(nums[start])+"->"+to_string(nums[end]);
                    ans.push_back(x);
                    start=i+1;
                    end=i+1;    
                }
                else
                {
                    string x="";
                    x=to_string(nums[start]);
                    ans.push_back(x);
                    start=i+1;
                    end=i+1;
                }
            }
        }
        
        if(start!=end)
        {
            string x="";
            x=to_string(nums[start])+"->"+to_string(nums[end]);
            ans.push_back(x);
        }
        else
        {
            string x="";
            x=to_string(nums[start]);
            ans.push_back(x);
        }
        
        return ans;
    }
};