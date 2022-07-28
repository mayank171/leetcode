class Solution {

    private:
    bool check(vector<int> &dp,vector<int> &arr,int n,int start)
    {
        cout<<start<<endl;
        if(start>=n || start<0 || arr[start]<0)
            return false;
        
        if(arr[start]==0)
            return true;
        
        if(dp[start]!=-1)
        {
            if(dp[start]==1)
                return true;
            return false;
        }
        
        bool add=false;
        bool sub=false;
        
        arr[start]*=-1;
        
        add=check(dp,arr,n,start+arr[start]);
        sub=check(dp,arr,n,start-arr[start]);
        
        bool a=add|sub;
        if(a)
            return dp[start]=1;
        else
            return dp[start]=0;
    }
    
    public:
    
    
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        set<int> st;
        vector<int> dp(n,-1);
        return check(dp,arr,n,start);
        
    }
};