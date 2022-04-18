// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	   // int n=nums.size();
	     
	   // vector<pair<int,int>> v;
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     v.push_back({nums[i],i});
	   // }
	    
	   // sort(v.begin(),v.end());
	    
	   // vector<bool> vis(n,false);
	    
	   // int ct=0;
	   // int num_swaps=0;
	    
	   // for(int i=0;i<n;)
	   // {
	   //     if(vis[i]==true)
	   //     {
	   //         i++;
	   //         continue;
	   //     }
	   //     if(v[i].first==nums[i])
	   //     {
	   //         vis[i]=true;
	   //         i++;
	   //     }
	   //     else
	   //     {
	   //         vis[i]=true;
	   //         if(vis[v[i].second]==true)
	   //         {
	   //             if(ct>0)
	   //             {
	   //                 num_swaps+=ct;
	   //                 ct=0;
	   //                 //vis[v[i].second]=true;
	   //                 i=v[i].second+1;
	   //             }
	   //         }
	   //         else
	   //         {
	                
	   //             i=v[i].second;
	   //             ct++;
	   //         }
	                
	   //     }
	   // }
	    
	   // return num_swaps;
	   
	   
	   
	   //int n=nums.size();
	   
	   //vector<pair<int,int>> v;
	   
	   //for(int i=0;i<n;i++)
	   //{
	   //    v.push_back({nums[i],i});
	   //}
	   
	   //sort(v.begin(),v.end());
	   
	   //vector<int> vis(n,0);
	   
	   
	   //int ans=0;
	   //int ind=0;
	   //for(int i=0;i<n;i++)
	   //{
	   //    if(vis[i]==1 || v[i].second==i)
	   //    {
	   //        continue;
	   //    }
	   //    int ct=0;
	   //    int j=i;
	   //    while(vis[j]==0)
	   //    {
	   //        vis[j]=1;
	   //        ct++;
	   //        j=v[j].second;
	   //    }
	   //    ans+=ct-1;
	   //}
	   
	   //return ans;
	   
	   
	   
	   
	   
	   
	   int n=nums.size();
	   
	   vector<pair<int,int>> v;
	   
	   for(int i=0;i<n;i++)
	   {
	       v.push_back({nums[i],i});
	   }
	   
	   sort(v.begin(),v.end());
	   
	   vector<int> vis(n,0);
	   
	   int ans=0;
	   
	   for(int i=0;i<n;i++)
	   {
	       if(vis[i]==1 || v[i].second==i)
	       {
	           continue;
	       }
	       
	       int ct=0;
	       int j=i;
	       
	       while(vis[j]==0)
	       {
	           vis[j]=1;
	           j=v[j].second;
	           ct++;
	       }
	       
	       ans+=ct-1;
	   }
	   
	   
	   return ans;
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	}
	
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends