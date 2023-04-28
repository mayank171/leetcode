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
    
    static bool comp(Job a, Job b)
    {
        if(a.profit>b.profit)
           return true;
        return false;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);    
    
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        set<int> st;
        for(int i=0;i<maxi;i++)
        {
            st.insert(i+1);
        }
        
        int num=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
              continue;
            int d=arr[i].dead;
            auto it=st.lower_bound(d);
            
            if(it!=st.end())
            {
                if(*it==d)
                {
                    num++;
                    profit+=arr[i].profit;
                    st.erase(it);
                }
                else if(it==st.begin())
                {
                    continue;
                }
                else
                {
                    --it;
                    num++;
                    profit+=arr[i].profit;
                    st.erase(it);
                }
            }
            else
            {
                --it;
                num++;
                profit+=arr[i].profit;
                st.erase(it);
            }
        }
        
        return {num,profit};
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