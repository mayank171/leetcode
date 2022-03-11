class Solution {
private:
    
    bool check(vector<int> &nums,int size,vector<vector<int>> &adj,int ssf,int i,int adj_size,int sum_all)
    {
        if(i==size)
        {
            for(int j=0;j<adj_size;j++)
            {
                if(adj[j].size()==0)
                    return false;
            }
        
            
            int sum=0;
            for(int j=0;j<adj[0].size();j++)
            {
                sum+=adj[0][j];
            }
            
            for(int j=1;j<adj_size;j++)
            {
                int sum1=0;
                for(int k=0;k<adj[j].size();k++)
                {
                    sum1+=adj[j][k];
                }
                
                if(sum1!=sum)
                {
                    return false;
                }
         
            }
            
            return true;
        }
        
        for(int j=0;j<adj_size;j++)
        {
            int sum1=0;
            for(int k=0;k<adj[j].size();k++)
            {
                sum1+=adj[j][k];
            }
            if(sum1>sum_all)
                return false;
        }
        
        for(int j=0;j<adj_size;j++)
        {
//             int sum1=accumulate(adj[j].begin(),adj[j].end(),0);
//             // cout<<sum1<<" ";
//             // cout<<sum_all/size<<endl;
//             if(sum1>sum_all)
//                 return false;
            
            if(adj[j].size()>0)
            {
                
                 adj[j].push_back(nums[i]);
                if(check(nums,size,adj,ssf,i+1,adj_size,sum_all))
                    return true;
                adj[j].pop_back();
            }
            else
            {
                adj[j].push_back(nums[i]);
                if(check(nums,size,adj,ssf+1,i+1,adj_size,sum_all))
                    return true;
                adj[j].pop_back();
                break;
            }
        }
        
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size=nums.size();
        
        sort(nums.rbegin(),nums.rend());
        
        vector<vector<int>> adj(k);
        
        int sum_all=accumulate(nums.begin(),nums.end(),0);
        sum_all/=k;
        
        if(check(nums,size,adj,0,0,k,sum_all))
            return true;
        
        return false;
    }
};