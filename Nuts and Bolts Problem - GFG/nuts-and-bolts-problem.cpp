//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    
	    vector<char> order;
	    order.push_back('!');
	    order.push_back('#');
	    order.push_back('$');
	    order.push_back('%');
	    order.push_back('&');
	    order.push_back('*');
	    order.push_back('@');
	    order.push_back('^');
	    order.push_back('~');
	    
	    map<char,int> mp1;
	    for(int i=0;i<n;i++)
	    {
	        mp1[nuts[i]]=i;
	    }
	    
	    map<char,int> mp2;
	    for(int i=0;i<n;i++)
	    {
	        mp2[bolts[i]]=i;
	    }
	    
	    int ind=0;
	    for(int i=0;i<9;i++)
	    {
	        if(mp1.find(order[i])!=mp1.end())
	        {
	            nuts[ind]=order[i];
	            ind++;
	        }
	           
	    }
	    
	    ind=0;
	    for(int i=0;i<9;i++)
	    {
	        if(mp2.find(order[i])!=mp2.end())
	        {
	            bolts[ind]=order[i];
	            ind++;
	        }
	    }
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends