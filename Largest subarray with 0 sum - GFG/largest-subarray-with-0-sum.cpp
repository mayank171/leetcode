//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        map<int,int> mp;
        mp[0]=-1;
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                maxi=max(maxi,i-mp[nums[i]]);
            }
            
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=i;
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends