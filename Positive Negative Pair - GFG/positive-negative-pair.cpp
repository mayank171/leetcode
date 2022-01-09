// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        unordered_set<int> s;
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            auto it=s.find(-1*arr[i]);
            
            if(it==s.end())
            {
                s.insert(arr[i]);
            }
            else
            {
                pos.push_back(arr[i]);
                s.erase(arr[i]);
                s.erase(-1*arr[i]);
            }
        }
        
        
        for(int i=0;i<pos.size();i++)
        {
            if(pos[i]>=0)
            {
                ans.push_back(-1*pos[i]);
                ans.push_back(pos[i]);
            }
            else
            {
                ans.push_back(pos[i]);
                ans.push_back(-1*pos[i]);
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends