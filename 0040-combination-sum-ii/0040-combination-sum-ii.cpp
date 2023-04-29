class Solution {
public:
    
    void solve(vector<int> &v,vector<vector<int>> &ans,vector<int> &temp,int n,int ind,int target)
    {
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return ;
        }
        
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(target-v[i]>=0)
            {
                if(i!=ind && v[i]==v[i-1])
                {
                    continue;
                }
                else
                {
                    temp.push_back(v[i]);
                  //  cout<<v[i]<<endl;
                    solve(v,ans,temp,n,i+1,target-v[i]);
                    temp.pop_back();
                }
            }
            else
                break;
        }
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(candidates,ans,temp,n,0,target);
        
        return ans;
    }
};