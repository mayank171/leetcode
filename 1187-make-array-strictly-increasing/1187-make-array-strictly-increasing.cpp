class Solution {
public:
    
    int solve(int ind,int left,vector<int> &arr1,int size,vector<int> &arr2,vector<map<int,int>> &dp)
    {
        if(ind==size)
            return 0;
        
        if(dp[ind].find(left)!=dp[ind].end())
            return dp[ind][left];
        
        int take=1e5;
        if(arr1[ind]>left)
        {
            take=solve(ind+1,arr1[ind],arr1,size,arr2,dp);
        }
        
        int ind2=upper_bound(arr2.begin(),arr2.end(),left)-arr2.begin();
        
        int nottake=1e5;
        if(ind2<arr2.size())
        {
            nottake=1+solve(ind+1,arr2[ind2],arr1,size,arr2,dp);
        }
        
        return dp[ind][left]=min(take,nottake);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(),arr2.end());
        
        int size1=arr1.size();
        int size2=arr2.size();
        
        vector<map<int,int>> dp(2001);
        
        int ans=solve(0,-1e5,arr1,size1,arr2,dp);
        
        if(ans==1e5)
            return -1;
        return ans;
    }
};