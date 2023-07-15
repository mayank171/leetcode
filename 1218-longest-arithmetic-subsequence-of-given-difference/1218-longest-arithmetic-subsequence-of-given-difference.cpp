class Solution {
public:
    
    int solve(vector<int> &arr,int n,int ind,int diff)
    {
        if(ind>=n)
            return 0;

        int i;
        int ans=0;
        int flag=0;
        for(i=ind+1;i<n;i++)
        {
            if(arr[i]-arr[ind]==diff)
            {
                flag=1;
                break;
            }
        }
        
        return max(1+solve(arr,n,i,diff),solve(arr,n,ind+1,diff));    
    }
    
    int longestSubsequence(vector<int>& arr, int diff) {
        
        int n=arr.size();
        //return 1+solve(arr,n,0,difference);
        
        map<int,int> mp;
   
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=1+mp[arr[i]-diff];
            ans=max(ans,mp[arr[i]]);    
        }
        
        return ans;
    }
};