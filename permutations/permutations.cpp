class Solution {
private:
    
    void compute(int N,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,int ind)
    {
        if(temp.size()==N)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<N;i++)
        {
            int t;
            if(nums[i]!=-100)
            {
                temp.push_back(nums[i]);
                t=nums[i];
                nums[i]=-100;
            }     
            else
                continue;
            compute(N,nums,ans,temp,i+1);
            temp.pop_back();
            nums[i]=t;
        }
    }
    
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        int ind=0;
        
        int N=nums.size();
        
        compute(N,nums,ans,temp,ind);
        
        return ans;
    }
};