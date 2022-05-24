class Solution {
private:
    void check(vector<int> &nums,int n,int ind,vector<vector<int>> &ans,vector<int> &temp,int &maxi)
    {
        if(ind==n)
        {
//             int x=temp.size();
//             int ori=0;
//             for(int i=0;i<x;i++)
//             {
//                 ori|=temp[i];
//             }
            
//             if(ori>maxi)
//                 maxi=ori;
            
            ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[ind]);
        check(nums,n,ind+1,ans,temp,maxi);
        temp.pop_back();
        check(nums,n,ind+1,ans,temp,maxi);

    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        

        
        vector<vector<int>> ans;
        vector<int> temp;
        
        int n=nums.size();
        
        int max_or=0;

        int ind=0;
        
        check(nums,n,ind,ans,temp,max_or);
        
        int m=ans.size();
        int ct=0;
        
        for(int i=0;i<m;i++)
        {
            int ori=0;
            for(int j=0;j<ans[i].size();j++)
            {
                ori|=ans[i][j];
            }
            
            if(ori>max_or)
                max_or=ori;
        }
        
        
        for(int i=0;i<m;i++)
        {
            int ori=0;
            for(int j=0;j<ans[i].size();j++)
            {
                ori|=ans[i][j];
            }
            
            if(ori==max_or)
                ct++;
        }
        
        return ct;
        
    }
};