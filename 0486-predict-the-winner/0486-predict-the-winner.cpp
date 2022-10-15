class Solution {
public:
    
    int solve(vector<int> &nums,int i,int j,int flag)
    {
        if(i>j)
            return 0;
        
        if(flag==0)
        {    
            return max(nums[i]+solve(nums,i+1,j,1),nums[j]+solve(nums,i,j-1,1));
        }
        else
        {
            return min(0+solve(nums,i,j-1,0),0+solve(nums,i+1,j,0)); 
        }
            
    }
    
    bool PredictTheWinner(vector<int>& nums) {
     
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int ans=solve(nums,0,n-1,0);
        
        int ans1=sum-ans;
        
        cout<<ans<<" "<<ans1<<endl;
        
        if(ans>=ans1)
            return true;
        return false;
    }
};