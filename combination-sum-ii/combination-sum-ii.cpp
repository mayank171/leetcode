class Solution {
    
private:
    
    void f1(vector<int> &candidates,int ind,int &sum,int target,vector<vector<int>> &ans,vector<int> temp,int n)
    {
        if(ind==n)
        {
            if(sum==target)
            {
                
                ans.push_back(temp);
                
            }
            return ;
        }
        
         if(sum==target)
            {
                
                ans.push_back(temp);
                return ;
                
            }
        
        if(sum>target)
        {
            return ;
        }
        
        int flag=0;
        for(int i=ind;i<n;i++)
        {
             if(i!=ind && candidates[i]==candidates[i-1])
                continue;
          
                sum+=candidates[i];
                temp.push_back(candidates[i]);
                f1(candidates,i+1,sum,target,ans,temp,n);
                temp.pop_back();
                sum-=candidates[i];
                flag=1;  
        }
        
        
    }
    
    
public:
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        int ind=0;
        
        int sum=0;
        
        int n=candidates.size();
        
        vector<vector<int>> ans;
        vector<int> temp;
        
       // unordered_set<int> s;
        
        
        f1(candidates,ind,sum,target,ans,temp,n);
        
        return ans;
        
    }
};