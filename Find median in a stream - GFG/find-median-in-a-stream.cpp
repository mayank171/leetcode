//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    
    void insertHeap(int &x)
    {
        maxi.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxi.size()>0 && mini.size()>0 && maxi.top()>mini.top())
        {
            int val=maxi.top();maxi.pop();
            mini.push(val);
        }
        
        if(maxi.size()>mini.size()+1)
        {
            int val=maxi.top();maxi.pop();
            mini.push(val);
        }
        
        if(mini.size()>maxi.size()+1)
        {
            int val=mini.top();mini.pop();
            maxi.push(val);
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxi.size()>mini.size())
        {
            return maxi.top();
        }
        else if(maxi.size()<mini.size())
        {
            return mini.top();
        }
        else
        {
            return (maxi.top()+mini.top())/(double)2;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends