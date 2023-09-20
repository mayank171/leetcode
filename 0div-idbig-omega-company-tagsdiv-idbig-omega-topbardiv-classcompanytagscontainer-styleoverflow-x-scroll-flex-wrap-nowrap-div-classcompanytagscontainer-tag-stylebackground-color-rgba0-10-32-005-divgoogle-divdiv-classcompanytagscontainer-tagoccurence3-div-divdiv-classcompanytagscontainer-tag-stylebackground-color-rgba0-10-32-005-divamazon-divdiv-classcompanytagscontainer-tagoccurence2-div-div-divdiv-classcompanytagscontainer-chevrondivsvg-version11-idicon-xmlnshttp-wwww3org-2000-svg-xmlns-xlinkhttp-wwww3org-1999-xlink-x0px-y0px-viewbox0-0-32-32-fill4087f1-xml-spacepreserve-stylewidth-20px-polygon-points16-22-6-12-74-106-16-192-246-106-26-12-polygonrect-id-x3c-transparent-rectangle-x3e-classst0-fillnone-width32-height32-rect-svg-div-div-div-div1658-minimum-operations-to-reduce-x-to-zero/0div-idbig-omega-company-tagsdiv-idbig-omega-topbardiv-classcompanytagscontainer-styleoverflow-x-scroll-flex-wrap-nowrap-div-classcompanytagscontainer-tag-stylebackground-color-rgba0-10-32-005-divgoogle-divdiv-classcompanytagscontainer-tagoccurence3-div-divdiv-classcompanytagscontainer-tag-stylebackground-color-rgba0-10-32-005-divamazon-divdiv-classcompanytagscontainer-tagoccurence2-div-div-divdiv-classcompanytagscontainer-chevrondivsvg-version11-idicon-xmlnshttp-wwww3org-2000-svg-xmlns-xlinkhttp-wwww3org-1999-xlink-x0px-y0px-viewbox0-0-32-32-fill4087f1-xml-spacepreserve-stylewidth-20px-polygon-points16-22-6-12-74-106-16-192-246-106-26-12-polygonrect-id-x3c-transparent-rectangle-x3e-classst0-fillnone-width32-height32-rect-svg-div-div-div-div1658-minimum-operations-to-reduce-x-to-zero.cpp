class Solution {
public:
    
    int solve(vector<int> &nums,int i,int j,int x,map<pair<int,pair<int,int>>,int> &mp)
    {
        if(x<0)
            return 1e6;
        
        if(x==0)
            return 0;
        
        if(i>j)
            return 1e6;
        
        if(mp.find({i,{j,x}})!=mp.end())
            return mp[{i,{j,x}}];
        
        int left=1+solve(nums,i+1,j,x-nums[i],mp);
        int right=1+solve(nums,i,j-1,x-nums[j],mp);
        
        return mp[{i,{j,x}}]=min(left,right);
    }
    
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        
//         map<pair<int,pair<int,int>>,int> mp;
        
//         int ans=solve(nums,0,n-1,x,mp);
        
//         if(ans>=1e6)
//             return -1;
//         return ans;
        
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        map<int,int> mp;
        mp[0]=-1;
        
        int maxi=-1;
        int target=nums[n-1]-x;
        
        if(target==0)
            return n;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-target)!=mp.end())
            {
                maxi=max(maxi,i-mp[nums[i]-target]);
            }
            
            mp[nums[i]]=i;
        }
        
        if(maxi==-1)
           return maxi;
        return n-maxi;
    }
};























