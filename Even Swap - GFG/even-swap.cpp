//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            vector<pair<int,int>> vp;
            
            
            for(int i=0;i<n;i++)
            {
                if(a[i]%2==0)
                {
                    int start=i;
                    int ct=0;
                    while(start<n && a[start]%2==0)
                    {
                        start++;
                        ct++;
                    }
                    
                    vp.push_back({i,start-1});
                    i=start-1;
                }
                else if(a[i]&1)
                {
                    int start=i;
                    int ct=0;
                    while(start<n && a[start]&1)
                    {
                        start++;
                        ct++;
                    }
                    
                    vp.push_back({i,start-1});
                    i=start-1;
                }
            }
            
            for(int i=0;i<vp.size();i++)
            {
                int start=vp[i].first;
                int end=vp[i].second;
              //  cout<<start<<" "<<end<<endl;
                sort(a.begin()+start,a.begin()+end+1,std::greater<>());
            }
            
            return a;
        }
        
        
        
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends