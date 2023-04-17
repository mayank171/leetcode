//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comp(Job a,Job b)
    {
        if(a.profit>b.profit)
           return true;
        return false;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr+0,arr+n,comp);
        
        set<int> st;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        for(int i=1;i<maxi+1;i++)
        {
            st.insert(i);
        }
        
        int ans=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            int dead=arr[i].dead;
            auto it=st.lower_bound(dead);
            if(it!=st.end() && *it==dead)
            {
                ct++;
                ans+=arr[i].profit;
                st.erase(it);
            }
            else if(it!=st.end() && *it!=dead)
            {
                if(it!=st.begin())
                {
                    ct++;
                    --it;
                    ans+=arr[i].profit;
                    st.erase(it);
                }
            }
            else if(it==st.end())
            {
               if(st.size()>0)
               {
                  --it;
                  ans+=arr[i].profit;
                  st.erase(it);
                  ct++;   
               }
                
            }
        }
        
        return {ct,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends