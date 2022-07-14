// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second)
        {
            if(a.first<b.first)
              return true;
            return false;
        }
        if(a.second<b.second)
           return true;
        return false;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({start[i],end[i]});
        }
        
        sort(vp.begin(),vp.end(),comp);
        
        int ind=vp[0].second;
        int ct=1;
        for(int i=1;i<n;i++)
        {
            if(ind<vp[i].first)
            {
                ct++;
                ind=vp[i].second;
            }
        }
        
        return ct;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends