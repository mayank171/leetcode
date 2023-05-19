//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        
        sort(range.begin(),range.end());
        
        vector<int> ans;
        
        for(int i=0;i<q;i++)
        {
            int x=queries[i];
            int s=range[0][0];
            int e=range[0][1];
            if(x<=e-s+1)
            {
                ans.push_back(s+x-1);
                continue;
            }
            
            int flag=0;
            for(int j=1;j<n;j++)
            {
                int ss=range[j][0];
                int ee=range[j][1];
                
                if(ss<=e)
                {
                    e=ee;
                }
                else
                {
                    x-=(e-s+1);
                    s=ss;
                    e=ee;
                }
                
                if(x<=e-s+1)
                {
                    flag=1;
                    ans.push_back(s+x-1);
                    break;
                }
            }
            
            if(flag==0)
            {
                ans.push_back(-1);
            }
        }
        
        return ans;
        
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends