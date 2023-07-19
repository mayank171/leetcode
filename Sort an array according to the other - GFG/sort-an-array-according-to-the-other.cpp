//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int> mp;
        set<int> st;
        for(int i=0;i<M;i++)
        {
            st.insert(A2[i]);
        }
        
        map<int,int> rem;
        for(int i=0;i<N;i++)
        {
            if(st.find(A1[i])!=st.end())
            {
                mp[A1[i]]++;
            }
            else
            {
                rem[A1[i]]++;
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<M;i++)
        {
            int x=A2[i];
            int ct=mp[x];
            while(ct--)
            {
                ans.push_back(x);
            }
        }
        
        for(auto &it:rem)
        {
            int ct=it.second;
            int x=it.first;
            while(ct--)
            {
                ans.push_back(x);
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends