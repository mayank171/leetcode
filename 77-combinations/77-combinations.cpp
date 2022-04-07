class Solution {
    
private:
    void comb(int n,int ind,vector<vector<int>> &ans,vector<int> &temp,int k)
    {
        if(ind>n)
        {
            if(temp.size()==k)
            {
                ans.push_back(temp);
            }
            return ;
        }
        
        if(temp.size()>n)
            return ;
        
        temp.push_back(ind);
        comb(n,ind+1,ans,temp,k);
        temp.pop_back();
        comb(n,ind+1,ans,temp,k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
//         vector<int> v;
        
//         for(int i=1;i<=n;i++)
//         {
//             v.push_back(i);
//         }
        
        int ind=1;
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        comb(n,ind,ans,temp,k);
        
        return ans;
        
    }
};