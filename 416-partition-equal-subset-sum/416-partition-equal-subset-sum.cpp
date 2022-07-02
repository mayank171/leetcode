class Solution {
private:

//    bool check(vector<int> &nums,int size,vector<vector<int>> &adj,int ssf,int i,int adj_size,int sum_all)
//     {
//         if(i==size)
//         {
//             for(int j=0;j<adj_size;j++)
//             {
//                 if(adj[j].size()==0)
//                     return false;
//             }
        
            
//             int sum=0;
//             for(int j=0;j<adj[0].size();j++)
//             {
//                 sum+=adj[0][j];
//             }
            
//             for(int j=1;j<adj_size;j++)
//             {
//                 int sum1=0;
//                 for(int k=0;k<adj[j].size();k++)
//                 {
//                     sum1+=adj[j][k];
//                 }
                
//                 if(sum1!=sum)
//                 {
//                     return false;
//                 }
         
//             }
            
//             return true;
//         }
        
//         for(int j=0;j<adj_size;j++)
//         {
//             int sum1=0;
//             for(int k=0;k<adj[j].size();k++)
//             {
//                 sum1+=adj[j][k];
//             }
//             if(sum1>sum_all)
//                 return false;
//         }
        
//         for(int j=0;j<adj_size;j++)
//         {
//             int sum1=accumulate(adj[j].begin(),adj[j].end(),0);
//             // cout<<sum1<<" ";
//             // cout<<sum_all/size<<endl;
//             if(sum1>sum_all)
//                 return false;
            
//             if(adj[j].size()>0)
//             {
                
//                  adj[j].push_back(nums[i]);
//                 if(check(nums,size,adj,ssf,i+1,adj_size,sum_all))
//                     return true;
//                 adj[j].pop_back();
//             }
//             else
//             {
//                 adj[j].push_back(nums[i]);
//                 if(check(nums,size,adj,ssf+1,i+1,adj_size,sum_all))
//                     return true;
//                 adj[j].pop_back();
//                 break;
//             }
//         }
        
//         return false;
//     }
    bool normal(vector<vector<int>> &dp,vector<int> &arr,int size,int sum,int ind)
    {
        if(ind==0)
        {
            if(sum==arr[0])
                return true;
            return false;
        }
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        int take=0;
        if(arr[ind]<=sum)
            take=normal(dp,arr,size,sum-arr[ind],ind-1);
        int notTake=normal(dp,arr,size,sum,ind-1);
        
        return dp[ind][sum]=take|notTake;
    }
    
public:
    bool canPartition(vector<int>& nums) {

        int size=nums.size();
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum&1)
        {
            return false;
        }
        
        sum=sum/2;
        
        vector<vector<int>> dp(size,vector<int>(sum+1,-1));
        
        return normal(dp,nums,size,sum,size-1);
        
//         sort(nums.rbegin(),nums.rend());
        
//         vector<vector<int>> adj(2);
        
//         int sum_all=accumulate(nums.begin(),nums.end(),0);
//         sum_all/=2;
        
//         if(check(nums,size,adj,0,0,2,sum_all))
//             return true;
        
//         return false;
        
    }
};