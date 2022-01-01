class Solution {
public:
    
    void f1(vector<int> &candidates,int target,int &sum,int ind,vector<vector<int>> &ans, vector<int> &temp,int n)
    {
        if(ind==n)
        {
            if(sum==target)
            {
                ans.push_back(temp);
                return ;
            }
            else
                return ;
        }
        
        if(sum==target)
        {
           // cout<<"found";
            ans.push_back(temp);
            return ;
        }
        
        if(sum>target)
        {
            return;
        }
        
        
        // for(int i=ind;i<candidates.size();i++)
        // {
           sum+=candidates[ind];
           temp.push_back(candidates[ind]);
           f1(candidates,target,sum,ind,ans,temp,n);
           temp.pop_back();
           sum-=candidates[ind];
           f1(candidates,target,sum,ind+1,ans,temp,n); 
        //}
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int ind=0;
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        int sum=0;
        
        int n=candidates.size();
        
        f1(candidates,target,sum,ind,ans,temp,n);
        
        return ans;
        
    }
};